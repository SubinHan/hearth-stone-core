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

	}
}