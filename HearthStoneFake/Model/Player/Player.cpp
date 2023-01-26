#include "Player.h"

using namespace std;

std::shared_ptr<nyvux::Player> nyvux::Player::CreatePlayer(std::shared_ptr<nyvux::Deck> Deck)
{
	return make_shared<Player>(Deck);
}

void nyvux::Player::DrawCard()
{
}

nyvux::Player::Player(std::shared_ptr<nyvux::Deck> Deck)
	: Deck(Deck),
	Field(Field::CreateField()),
	Hand(Hand::CreateHand())
{
}
