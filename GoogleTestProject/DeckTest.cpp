#include "pch.h"

#include <vector>
#include "../HearthStoneFake/Model/Card/Card.h"
#include "../HearthStoneFake/Model/Player/Deck.h"
#include "../HearthStoneFake/Model/Card/CardFactory.h"

#include <memory>

using namespace std;

namespace nyvux
{
	vector<shared_ptr<Card>> MakeDummyCards()
	{
		vector<shared_ptr<Card>> DummyCards{};
		for (int i = 0; i < Deck::DEFAULT_DECK_SIZE; i++)
		{
			DummyCards.push_back(CardFactory::CreateDummyCard());
		}
		return DummyCards;
	}

	class DeckTest : public ::testing::Test
	{
	public:
		vector<shared_ptr<Card>> DummyCards;

	protected:
		void SetUp()
		{
			DummyCards = MakeDummyCards();
		}

		void TearDown()
		{

		}

	};


	TEST_F(DeckTest, TestDraw)
	{
		Deck CardDeck(DummyCards);

		EXPECT_EQ(CardDeck.GetCount(), Deck::DEFAULT_DECK_SIZE);
		shared_ptr<Card> Drawn = CardDeck.Draw();
		EXPECT_EQ(CardDeck.GetCount(), Deck::DEFAULT_DECK_SIZE - 1);
	}
}