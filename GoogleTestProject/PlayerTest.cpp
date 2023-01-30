#include "pch.h"

#include <vector>
#include "Helper.h"
#include "../HearthStoneFake/Model/Card/Card.h"
#include "../HearthStoneFake/Model/Player/Player.h"

#include <memory>

using namespace std;

namespace nyvux
{

	class PlayerTest : public ::testing::Test
	{
	public:
		vector<shared_ptr<Card>> DummyCards;

	protected:
		void SetUp()
		{
			DummyCards = MakeDummyCards();
			shared_ptr<Deck> Deck = Deck::CreateDeck(DummyCards);

			Player = Player::CreatePlayer(Deck);
		}

		shared_ptr<Player> Player;
	};

	TEST_F(PlayerTest, TestDraw)
	{
		EXPECT_EQ(30, Player->GetNumCardsInDeck());
		Player->DrawCard();
		EXPECT_EQ(29, Player->GetNumCardsInDeck());		
	}

	TEST_F(PlayerTest, TestPlayPlaceable)
	{
		Player->DrawCard();
		Player->DrawCard();
		Player->DrawCard();

		EXPECT_EQ(3, Player->GetNumCardsInHand());
		EXPECT_EQ(0, Player->GetNumPlayedInField());

		constexpr int HAND_POS = 0;
		constexpr int FIELD_POS = 0;
		Player->PlaceCardWithoutBattleCry(HAND_POS, FIELD_POS);

		EXPECT_EQ(2, Player->GetNumCardsInHand());
		EXPECT_EQ(1, Player->GetNumPlayedInField());
	}

	TEST_F(PlayerTest, TestDrawDiscards)
	{
		for(int i = 0; i < Hand::MAX_HAND_SIZE; i++)
		{
			Player->DrawCard();
		}

		EXPECT_EQ(Hand::MAX_HAND_SIZE, Player->GetNumCardsInHand());

		Player->DrawCard();

		EXPECT_EQ(Hand::MAX_HAND_SIZE, Player->GetNumCardsInHand());
		EXPECT_EQ(
			Deck::DEFAULT_DECK_SIZE - Hand::MAX_HAND_SIZE - 1, 
			Player->GetNumCardsInDeck()
		);
	}


}