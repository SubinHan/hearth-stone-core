#include "testpch.h"

#include "Helper.h"
#include "NyvuxStone/Core/Game/GameMediator.h"
#include "NyvuxStone/Model/Card/Minion.h"
#include "NyvuxStone/Model/Event/ModifyMinionStatCommand.h"

using namespace std;

namespace nyvux
{
	class GameMediatorTest : public ::testing::Test
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

	TEST_F(GameMediatorTest, TestDrawEvent)
	{
		PlayerA->DrawCard();
		PlayerA->PlaceCardWithoutBattlecry(0, 0);
		auto Placeable = PlayerA->GetCardInFieldAt(0);

		shared_ptr<Minion> Minion = dynamic_pointer_cast<nyvux::Minion>(Placeable);

		if(!Minion)
		{
			FAIL();
		}

		constexpr int DUMMY_ORIGINAL_ATTACK = 0;
		constexpr int DUMMY_ORIGINAL_HEALTH = 1;
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;

		Minion->AddOnDrawedCommand(make_shared<ModifyMinionStatCommand>(Minion, MODIFY_ATTACK, MODIFY_HEALTH));
		
		PlayerB->DrawCard();

		EXPECT_EQ(DUMMY_ORIGINAL_HEALTH + MODIFY_HEALTH, Minion->GetMaxHealth());
		EXPECT_EQ(DUMMY_ORIGINAL_ATTACK + MODIFY_ATTACK, Minion->GetAttack());
	}

	TEST_F(GameMediatorTest, TestGetOpponentPlayer)
	{
		EXPECT_TRUE(&(*(GameMediator->GetOpponentPlayerOf(PlayerA))) == &(*(PlayerB)));
		EXPECT_TRUE(&(*(GameMediator->GetOpponentPlayerOf(PlayerB))) == &(*(PlayerA)));

		EXPECT_TRUE(GameMediator->GetOpponentPlayerOf(PlayerA) == PlayerB);
		EXPECT_TRUE(GameMediator->GetOpponentPlayerOf(PlayerB) == PlayerA);
	}
	
}