#include "pch.h"

#include "NyvuxStone/Model/Player/Player.h"

#include "NyvuxStone/Model/Player/SecretZone.h"
#include "NyvuxStone/Model/Card/Secret.h"
#include "NyvuxStone/Model/Card/Spell.h"
#include "NyvuxStone/Core/Game/GameMediator.h"
#include "NyvuxStone/Core/Game/Command/RemoveMinionInFieldCommand.h"
#include "NyvuxStone/Model/Player/PlayerException.h"
#include <nyvux/utils/Random.h>

using namespace std;
using namespace nyvux;

Player::Player(std::shared_ptr<nyvux::Deck> Deck, std::shared_ptr<nyvux::GameMediator> GameMediator)
	: Deck(Deck),
	Field(Field::CreateField()),
	Hand(Hand::CreateHand()),
	Hero(Hero::CreateHero()),
	SecretZone(SecretZone::CreateSecretZone()),
	GameMediator(GameMediator),
	CurrentMana(0),
	MaxMana(0),
	OverloadedMana(0)
{
}

std::shared_ptr<Player> Player::CreatePlayer(std::shared_ptr<nyvux::Deck> Deck, std::shared_ptr<nyvux::GameMediator> GameMediator)
{
	auto Player = make_shared<nyvux::Player>(Deck, GameMediator);
	Player->AddOnDestroyedCommand(make_shared<RemoveMinionInFieldCommand>(Player));

	return Player;
}

void Player::DrawCard()
{
	shared_ptr<Card> Drawn = Deck->Draw();
	Hand->AddCard(Drawn);

	auto DrawEvent =
		NyvuxStoneEvent::CreateNyvuxStoneEvent(shared_from_this(), nullptr, Drawn);

	FireDrawed(DrawEvent);
}

int Player::GetNumCardsInDeck() const
{
	return Deck->GetCount();
}

int nyvux::Player::GetNumCardsInHand() const
{
	return Hand->GetNumCards();
}

int nyvux::Player::GetNumPlayedInField() const
{
	return Field->GetNumPlayed();
}

void nyvux::Player::PlayMinion(int ZeroBasedHandIndex, int ZeroBasedFieldIndex, std::shared_ptr<Character> Target)
{
	if (!Field->CanPlace())
	{
		throw PlayerException("The field is full.");
	}

	if (Hand->IsEmpty())
	{
		throw PlayerException("The hand is empty.");
	}

	auto ToPlay = Hand->GetCard(ZeroBasedHandIndex);
	auto Minion = std::dynamic_pointer_cast<nyvux::Minion>(ToPlay);
	if (!Minion)
	{
		throw PlayerException("The given card is not a minion or a location.");
	}

	Hand->RemoveCard(ZeroBasedHandIndex);
	Field->PlaceCard(Minion, ZeroBasedFieldIndex);

	auto PlayEvent =
		NyvuxStoneEvent::CreateNyvuxStoneEvent(shared_from_this(), ToPlay, Target);
	FirePlayed(PlayEvent);

	if (Field->IsPlaced(Minion))
	{
		GameMediator->RegisterCard(Minion);
		auto SummonEvent =
			NyvuxStoneEvent::CreateNyvuxStoneEvent(shared_from_this(), nullptr, Minion);
		FireSummoned(SummonEvent);
	}
}

std::shared_ptr<Character> Player::GetCardInFieldAt(int ZeroBasedIndex)
{
	return Field->GetCardAt(ZeroBasedIndex);
}

bool nyvux::Player::CanAttack(int ZeroBasedFieldIndexOfOpponents)
{
	auto Opponent = GameMediator->GetOpponentPlayerOf(shared_from_this());
	auto Character = Opponent->GetCardInFieldAt(ZeroBasedFieldIndexOfOpponents);

	auto Minion = dynamic_pointer_cast<nyvux::Minion>(Character);

	if (!Minion)
	{
		// The card is a location.
		return false;
	}

	if (Minion->HasTaunt())
	{
		return true;
	}

	for(int i = 0; i < Opponent->GetNumPlayedInField(); i++)
	{
		if (i == ZeroBasedFieldIndexOfOpponents)
			continue;
		auto AnotherPlaceable = Opponent->GetCardInFieldAt(i);
		auto AnotherMinion = dynamic_pointer_cast<nyvux::Minion>(AnotherPlaceable);

		if (!AnotherMinion)
			continue;

		if (AnotherMinion->HasTaunt())
			return false;
	}

	return true;
}

bool Player::CanAddSecret()
{
	return SecretZone->CanAddSecret();
}

void Player::AddSecret(std::shared_ptr<Secret> Secret)
{
	SecretZone->RegisterSecret(Secret, GameMediator);
}

void Player::RemoveSecret(std::shared_ptr<Secret> Secret)
{
	SecretZone->UnregisterSecret(Secret, GameMediator);
}

void Player::RemovePlaceableInField(std::shared_ptr<Minion> Card)
{
	Field->Remove(Card);
}

void Player::IncreaseMaxMana()
{
	MaxMana++;
}

void Player::FulfillMana()
{
	CurrentMana = MaxMana - OverloadedMana;
}

void Player::OverloadMana(int Amount)
{
	OverloadedMana += Amount;
}

void Player::UnlockAllOverloadedMana()
{
	OverloadedMana = 0;
}

void Player::AddCardIntoHand(std::shared_ptr<Card> Card)
{
	Hand->AddCard(Card);
}

bool Player::ContainsMinionInField(std::shared_ptr<Minion> Minion)
{
	return Field->ContainsMinion(Minion);
}

std::shared_ptr<Minion> Player::GetRandomMinionInField()
{
	const int FieldSize = Field->GetNumPlayed();
	const int RandomIndex = Random().Uniform(0, FieldSize);
	return Field->GetCardAt(RandomIndex);
}

void nyvux::Player::CastSpell(std::shared_ptr<Spell> Spell, std::shared_ptr<Character> Target)
{
	auto Event = 
		NyvuxStoneEvent::CreateNyvuxStoneEvent(shared_from_this(), Spell, Target);
	FireCasted(Event);

	auto ActualTarget = std::dynamic_pointer_cast<Character>(Event->TargetCard);
	auto ActualSpell = std::dynamic_pointer_cast<nyvux::Spell>(Event->FromCard);

	ActualSpell->Cast(shared_from_this(), ActualTarget);
}

void nyvux::Player::PlaySpell(int ZeroBasedHandIndex, std::shared_ptr<Character> Target)
{
	std::shared_ptr<Spell> Spell = std::dynamic_pointer_cast<nyvux::Spell>(Hand->GetCard(ZeroBasedHandIndex));

	if(!Spell)
	{
		throw PlayerException("The card is not a spell");
	}

	int ManaCost = Spell->GetCardSpec().ManaCost;

	if (CurrentMana < ManaCost)
		throw PlayerException("Not enough mana to cast the spell.");

	if (Spell->NeedsTarget() && !Target)
		throw PlayerException("Spell needs a target but the given target is null");

	Hand->RemoveCard(ZeroBasedHandIndex);
	CurrentMana -= ManaCost;

	auto Event = 
		NyvuxStoneEvent::CreateNyvuxStoneEvent(shared_from_this(), Spell, Target);
	FirePlayed(Event);

	auto ActualSpell = std::dynamic_pointer_cast<nyvux::Spell>(Event->FromCard);
	auto ActualTarget = std::dynamic_pointer_cast<Character>(Event->TargetCard);

	CastSpell(ActualSpell, ActualTarget);
}

void Player::DestroyTopCardsInDeck()
{
	Deck->DestroyCard(0);
}

int Player::GetCurrentHealth() const
{
	return Hero->GetCurrentHealth();
}

int Player::GetCurrentArmor() const
{
	return Hero->GetCurrentArmor();
}

int Player::GetMaxHealth() const
{
	return Hero->GetMaxHealth();
}

std::shared_ptr<Hero> nyvux::Player::GetHero()
{
	return Hero;
}

int Player::GetCurrentMana() const
{
	return CurrentMana;
}

int Player::GetMaxMana() const
{
	return MaxMana;
}

int Player::GetOverloadedMana() const
{
	return OverloadedMana;
}
