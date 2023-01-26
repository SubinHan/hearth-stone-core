#include "pch.h"

#include "../HearthStoneFake/Core/Api/HearthstoneApi.h"
#include "../HearthStoneFake/Model/Card/IMinionStatDecorator.h"
#include "../HearthStoneFake/Model/Card/MinionStatDecoratorEmpty.h"
#include "../HearthStoneFake/Model/Card/MinionStatDecoratorModifier.h"
#include <vector>
#include <memory>

using namespace std;

namespace nyvux
{
	TEST(CardStatDecoratorTest, TestDecoratorEmpty)
	{
		shared_ptr<IMinionStatDecorator> Empty = make_shared<MinionStatDecoratorEmpty>();

		EXPECT_EQ(0, Empty->GetDeltaAttack());
		EXPECT_EQ(0, Empty->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifier)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<IMinionStatDecorator> Empty = make_shared<MinionStatDecoratorEmpty>();
		shared_ptr<IMinionStatDecorator> Buffed = make_shared<MinionStatDecoratorModifier>(
			Empty, BUFF_ATTACK, BUFF_HEALTH);
		
		EXPECT_EQ(BUFF_ATTACK, Buffed->GetDeltaAttack());
		EXPECT_EQ(BUFF_HEALTH, Buffed->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifierMore)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<IMinionStatDecorator> Empty = make_shared<MinionStatDecoratorEmpty>();
		shared_ptr<IMinionStatDecorator> Buffed = make_shared<MinionStatDecoratorModifier>(
			Empty, BUFF_ATTACK, BUFF_HEALTH);
		shared_ptr<IMinionStatDecorator> MoreBuffed = make_shared<MinionStatDecoratorModifier>(
			Buffed, BUFF_ATTACK, BUFF_HEALTH);

		EXPECT_EQ(2 * BUFF_ATTACK, MoreBuffed->GetDeltaAttack());
		EXPECT_EQ(2 * BUFF_HEALTH, MoreBuffed->GetDeltaHealth());
	}
}
