#include "pch.h"

#include "NyvuxStone/Core/Api/HearthstoneApi.h"
#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorBase.h"
#include "NyvuxStone/Core/Game/Decorator/MinionStat/MinionStatDecoratorModify.h"

#include <vector>
#include <memory>

using namespace std;

namespace nyvux
{
	TEST(CardStatDecoratorTest, TestDecoratorBase)
	{
		shared_ptr<MinionStatDecoratorBase> Base = make_shared<MinionStatDecoratorBase>();

		EXPECT_EQ(0, Base->GetDeltaAttack());
		EXPECT_EQ(0, Base->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifier)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<MinionStatDecoratorBase> Base = make_shared<MinionStatDecoratorBase>();
		shared_ptr<MinionStatDecoratorBase> Buffed = make_shared<MinionStatDecoratorModify>(
			Base, BUFF_ATTACK, BUFF_HEALTH);
		
		EXPECT_EQ(BUFF_ATTACK, Buffed->GetDeltaAttack());
		EXPECT_EQ(BUFF_HEALTH, Buffed->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifierMore)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<MinionStatDecoratorBase> Base = make_shared<MinionStatDecoratorBase>();
		shared_ptr<MinionStatDecoratorBase> Buffed = make_shared<MinionStatDecoratorModify>(
			Base, BUFF_ATTACK, BUFF_HEALTH);
		shared_ptr<MinionStatDecoratorBase> MoreBuffed = make_shared<MinionStatDecoratorModify>(
			Buffed, BUFF_ATTACK, BUFF_HEALTH);

		EXPECT_EQ(2 * BUFF_ATTACK, MoreBuffed->GetDeltaAttack());
		EXPECT_EQ(2 * BUFF_HEALTH, MoreBuffed->GetDeltaHealth());
	}
}
