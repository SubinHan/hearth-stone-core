#include "NyvuxStone/View/UserInteraction.h"

#include "NyvuxStone/Model/Card/CardFactory.h"

#include <memory>


using namespace std;

namespace nyvux
{
	vector<shared_ptr<Card>> MakeDummyCards()
	{
		vector<shared_ptr<Card>> DummyCards{};
		for (int i = 0; i < Deck::DEFAULT_DECK_SIZE; i++)
		{
			DummyCards.push_back(CardFactory::CreateDummyMinion());
		}
		return DummyCards;
	}
}

std::shared_ptr<nyvux::Deck> nyvux::UserInteraction::ReadDeckPlayerA()
{
	// TODO: Implement this.
	return make_shared<Deck>(MakeDummyCards());
}

std::shared_ptr<nyvux::Deck> nyvux::UserInteraction::ReadDeckPlayerB()
{
	// TODO: Implement this.
	return make_shared<Deck>(MakeDummyCards());
}

