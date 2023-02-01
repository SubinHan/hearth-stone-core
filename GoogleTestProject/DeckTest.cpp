#include "pch.h"

#include "NyvuxStone/Model/Card/Card.h"
#include "NyvuxStone/Model/Player/Deck.h"

#include "Helper.h"

using namespace std;
using namespace nyvux;

namespace nyvux
{
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
		shared_ptr<Deck> CardDeck = Deck::CreateDeck(DummyCards);

		EXPECT_EQ(CardDeck->GetCount(), Deck::DEFAULT_DECK_SIZE);
		shared_ptr<Card> Drawn = CardDeck->Draw();
		EXPECT_EQ(CardDeck->GetCount(), Deck::DEFAULT_DECK_SIZE - 1);
	}
}