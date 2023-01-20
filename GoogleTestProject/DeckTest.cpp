#include "pch.h"

#include <vector>
#include "../HearthStoneFake/Card.h"
#include "../HearthStoneFake/Deck.h"
#include "../HearthStoneFake/CardFactory.h"

using namespace std;

namespace nyvux
{
	vector<Card> MakeDummyCards()
	{
		vector<Card> DummyCards{};
		for (int i = 0; i < Deck::DEFAULT_DECK_SIZE; i++)
		{
			DummyCards.push_back(CardFactory::CreateDummyCard());
		}
		return DummyCards;
	}

	class DeckTest : public ::testing::Test
	{
	public:
		vector<Card> DummyCards;

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
		Card Drawn = CardDeck.Draw();
		EXPECT_EQ(CardDeck.GetCount(), Deck::DEFAULT_DECK_SIZE - 1);
	}
}