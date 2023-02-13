#include "pch.h"

#include "NyvuxStone/Model/Player/Player.h"

#include "NyvuxStone/Core/Game/Command/RemovePlaceableInFieldCommand.h"
#include "NyvuxStone/Model/Player/PlayerException.h"

using namespace std;
using namespace nyvux;

Player::Player(std::shared_ptr<nyvux::Deck> Deck, std::shared_ptr<nyvux::GameMediator> GameMediator)
	: Deck(Deck),
	Field(Field::CreateField()),
	Hand(Hand::CreateHand()),
	GameMediator(GameMediator)
{
}

std::shared_ptr<Player> Player::CreatePlayer(std::shared_ptr<nyvux::Deck> Deck, std::shared_ptr<nyvux::GameMediator> GameMediator)
{
	auto Player = make_shared<nyvux::Player>(Deck, GameMediator);
	Player->AddOnDestroyedCommand(make_shared<RemovePlaceableInFieldCommand>(Player));

	return Player;
}

void Player::DrawCard()
{
	shared_ptr<Card> Drawn = Deck->Draw();
	Hand->AddCard(Drawn);
	FireDrawed(Event{ Drawn });
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

void nyvux::Player::PlaceCardWithoutBattlecry(int ZeroBasedHandIndex, int ZeroBasedFieldIndex)
{
	if (!Field->CanPlace())
	{
		throw PlayerException("The field is full.");
	}

	if(Hand->IsEmpty())
	{
		throw PlayerException("The hand is empty.");
	}

	auto ToPlay = Hand->GetCard(ZeroBasedHandIndex);

	auto Placeable = std::dynamic_pointer_cast<Character>(ToPlay);
	if(!Placeable)
	{
		throw PlayerException("The given card is not a minion or a location.");
	}

	Hand->RemoveCard(ZeroBasedHandIndex);
	Field->PlaceCard(Placeable, ZeroBasedFieldIndex);
	FirePlayed(Event{ Placeable });

	if(Field->IsPlaced(Placeable))
	{
		GameMediator->RegisterCard(Placeable);
		FireSummoned(Event{ Placeable });
	}
}

std::shared_ptr<Character> Player::GetCardInFieldAt(int ZeroBasedIndex)
{
	return Field->GetCardAt(ZeroBasedIndex);
}

bool nyvux::Player::CanAttack(int ZeroBasedFieldIndexOfOpponents)
{
	auto Opponent = GameMediator->GetOpponentPlayerOf(shared_from_this());
	auto Placeable = Opponent->GetCardInFieldAt(ZeroBasedFieldIndexOfOpponents);

	auto Minion = dynamic_pointer_cast<nyvux::Minion>(Placeable);

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

void Player::RemovePlaceableInField(std::shared_ptr<Character> Card)
{
	Field->Remove(Card);
}

int Player::GetCurrentMana()
{
	return CurrentMana;
}

int Player::GetMaxMana()
{
	return MaxMana;
}
