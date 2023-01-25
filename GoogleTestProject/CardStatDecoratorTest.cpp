#include "pch.h"

#include "../HearthStoneFake/HearthstoneApi.h"
#include "../HearthStoneFake/CardStat.h"
#include "../HearthStoneFake/CardSpec.h"
#include "../HearthStoneFake/ICardStatDecorator.h"
#include "../HearthStoneFake/CardStatDecoratorEmpty.h"
#include "../HearthStoneFake/CardStatDecoratorModifier.h"
#include <vector>
#include <memory>

using namespace std;

namespace nyvux
{
	TEST(CardStatDecoratorTest, TestDecoratorEmpty)
	{
		shared_ptr<ICardStatDecorator> Empty = make_shared<CardStatDecoratorEmpty>();

		EXPECT_EQ(0, Empty->GetDeltaAttack());
		EXPECT_EQ(0, Empty->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifier)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<ICardStatDecorator> Empty = make_shared<CardStatDecoratorEmpty>();
		shared_ptr<ICardStatDecorator> Buffed = make_shared<CardStatDecoratorModifier>(
			Empty, BUFF_ATTACK, BUFF_HEALTH);
		
		EXPECT_EQ(BUFF_ATTACK, Buffed->GetDeltaAttack());
		EXPECT_EQ(BUFF_HEALTH, Buffed->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifierMore)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<ICardStatDecorator> Empty = make_shared<CardStatDecoratorEmpty>();
		shared_ptr<ICardStatDecorator> Buffed = make_shared<CardStatDecoratorModifier>(
			Empty, BUFF_ATTACK, BUFF_HEALTH);
		shared_ptr<ICardStatDecorator> MoreBuffed = make_shared<CardStatDecoratorModifier>(
			Buffed, BUFF_ATTACK, BUFF_HEALTH);

		EXPECT_EQ(2 * BUFF_ATTACK, MoreBuffed->GetDeltaAttack());
		EXPECT_EQ(2 * BUFF_HEALTH, MoreBuffed->GetDeltaHealth());
	}
}
