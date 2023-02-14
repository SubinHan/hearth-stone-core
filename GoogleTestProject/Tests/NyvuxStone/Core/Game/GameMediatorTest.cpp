#include "testpch.h"

#include "Helper.h"
#include "NyvuxStone/Core/Game/GameMediator.h"
#include "NyvuxStone/Core/Game/Command/ModifyMinionStatCommand.h"
#include "NyvuxStone/Model/Card/Minion.h"

using namespace std;

namespace nyvux
{
	class GameMediatorTest : public ::testing::Test
	{

	protected:
		void SetUp()
		{
			GameMediator = GameMediator::CreateGameMediator();
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
		PlayerA->PlayMinion(0, 0);
		auto PlayedMinion = PlayerA->GetCardInFieldAt(0);

		shared_ptr<Minion> Minion = dynamic_pointer_cast<nyvux::Minion>(PlayedMinion);

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

	TEST_F(GameMediatorTest, TestIfListenerDestroysWhenCardDestroy)
	{
		PlayerA->DrawCard();
		PlayerA->PlayMinion(0, 0);
		auto PlayedMinion = PlayerA->GetCardInFieldAt(0);

		shared_ptr<Minion> Minion = dynamic_pointer_cast<nyvux::Minion>(PlayedMinion);

		if (!Minion)
		{
			FAIL();
		}

		constexpr int DUMMY_ORIGINAL_ATTACK = 0;
		constexpr int DUMMY_ORIGINAL_HEALTH = 1;
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;

		Minion->AddOnDrawedCommand(make_shared<ModifyMinionStatCommand>(Minion, MODIFY_ATTACK, MODIFY_HEALTH));

		PlayerB->DrawCard();

		Minion->GainDamage(500);

		PlayerB->DrawCard();

		EXPECT_EQ(DUMMY_ORIGINAL_HEALTH + MODIFY_HEALTH, Minion->GetMaxHealth());
		EXPECT_EQ(DUMMY_ORIGINAL_ATTACK + MODIFY_ATTACK, Minion->GetAttack());

		EXPECT_EQ(0, PlayerA->GetNumPlayedInField());
	}
	
}