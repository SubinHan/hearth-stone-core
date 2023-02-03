#include "testpch.h"

#include "NyvuxStone/Core/Game/GameMediator.h"

#include "Helper.h"

using namespace std;

namespace nyvux
{
	class PlayerGameMediatorTest : public ::testing::Test
	{

	protected:
		void SetUp()
		{
			GameMediator = make_shared<nyvux::GameMediator>();
			PlayerA = MakeDummyPlayer(GameMediator);
			PlayerB = MakeDummyPlayer(GameMediator);

			GameMediator->RegisterPlayers(PlayerA, PlayerB);
		}

		shared_ptr<GameMediator> GameMediator;
		shared_ptr<Player> PlayerA;
		shared_ptr<Player> PlayerB;
	};

	TEST_F(PlayerGameMediatorTest, TestCanAttack)
	{
		PlayerA->DrawCard();
		PlayerA->PlaceCardWithoutBattlecry(0, 0);

		PlayerB->DrawCard();
		PlayerB->DrawCard();
		PlayerB->PlaceCardWithoutBattlecry(0, 0);
		PlayerB->PlaceCardWithoutBattlecry(0, 0);

		EXPECT_TRUE(PlayerA->CanAttack(0));

		auto Card = PlayerB->GetCardInFieldAt(0);
		auto Minion = dynamic_pointer_cast<nyvux::Minion>(Card);

		if (!Minion)
			FAIL();

		Minion->GainTaunt();

		EXPECT_TRUE(PlayerA->CanAttack(0));
		EXPECT_FALSE(PlayerA->CanAttack(1));

		Minion->Silence();

		EXPECT_TRUE(PlayerA->CanAttack(0));
		EXPECT_TRUE(PlayerA->CanAttack(1));
	}

}