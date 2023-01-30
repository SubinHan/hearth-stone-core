#include "Player.h"

#include "PlayerException.h"

using namespace std;
using namespace nyvux;

Player::Player(shared_ptr<nyvux::Deck> Deck)
	: Deck(Deck),
	Field(Field::CreateField()),
	Hand(Hand::CreateHand())
{
}

std::shared_ptr<Player> Player::CreatePlayer(std::shared_ptr<nyvux::Deck> Deck)
{
	return make_shared<Player>(Deck);
}

void Player::DrawCard()
{
	shared_ptr<Card> Drawn = Deck->Draw();
	Hand->AddCard(Drawn);
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
	FirePlayed();
}

void Player::FirePlayed()
{
	// TODO: Implement it.
}

