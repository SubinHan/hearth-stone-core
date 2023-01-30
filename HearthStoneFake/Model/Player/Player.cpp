#include "Player.h"

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
	//if (!Field->CanPutMinion())
	//{
	//	throw PlayerException();
	//}

	//if(Hand->IsEmpty())
	//{
	//	throw PlayerException();
	//}

	//auto ToPlay = Hand->GetCard(ZeroBasedHandIndex);

	//auto Placeable = std::static_pointer_cast<IPlaceable>(ToPlay);


	//Field->PutMinion(ZeroBasedFieldIndex);

}

