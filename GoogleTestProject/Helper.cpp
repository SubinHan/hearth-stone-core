#include "Helper.h"

#include "../HearthStoneFake/Model/Card/CardFactory.h"
#include "../HearthStoneFake/Model/Player/Deck.h"

using namespace std;
using namespace nyvux;

vector<shared_ptr<Card>> nyvux::MakeDummyCards()
{
	vector<shared_ptr<Card>> DummyCards{};
	for (int i = 0; i < Deck::DEFAULT_DECK_SIZE; i++)
	{
		DummyCards.push_back(CardFactory::CreateDummyCard());
	}
	return DummyCards;
}