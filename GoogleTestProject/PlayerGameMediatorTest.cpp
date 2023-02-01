#include "pch.h"

#include "NyvuxStone/Core/Game/GameMediator.h"
#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorTaunt.h"

#include "Helper.h"
#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorSilence.h"

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

		Minion->Modify<MinionStatDecoratorTaunt>();

		EXPECT_TRUE(PlayerA->CanAttack(0));
		EXPECT_FALSE(PlayerA->CanAttack(1));

		Minion->Modify<MinionStatDecoratorSilence>();

		EXPECT_TRUE(PlayerA->CanAttack(0));
		EXPECT_TRUE(PlayerA->CanAttack(1));
	}

}