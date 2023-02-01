#include "pch.h"

#include "NyvuxStone/Model/Player/Player.h"

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
	return make_shared<Player>(Deck, GameMediator);
}

void Player::DrawCard()
{
	shared_ptr<Card> Drawn = Deck->Draw();
	Hand->AddCard(Drawn);
	FireDrawed(Drawn);
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

void nyvux::Player::PlaceCardWithoutBattleCry(int ZeroBasedHandIndex, int ZeroBasedFieldIndex)
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

	auto Placeable = std::dynamic_pointer_cast<AbstractPlaceableCard>(ToPlay);
	if(!Placeable)
	{
		throw PlayerException("The given card is not a minion or a location.");
	}

	Hand->RemoveCard(ZeroBasedHandIndex);
	Field->PlaceCard(Placeable, ZeroBasedFieldIndex);
	FirePlayed(Placeable);

	if(Field->IsPlaced(Placeable))
	{
		FireSummoned(Placeable);
	}
}

std::shared_ptr<AbstractPlaceableCard> Player::GetCardInFieldAt(int ZeroBasedIndex)
{
	return Field->GetCardAt(ZeroBasedIndex);
}

void Player::FirePlayed(std::shared_ptr<Card> Card)
{
	// TODO: Implement it.
}

void Player::FireDrawed(std::shared_ptr<Card> Card)
{
	GameMediator->FireDrawed(shared_from_this(), Card);
}

void Player::FireSummoned(std::shared_ptr<AbstractPlaceableCard> Shared)
{
	GameMediator->FireSummoned(shared_from_this(), Shared);
}

