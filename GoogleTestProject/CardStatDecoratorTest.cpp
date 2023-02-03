#include "pch.h"

#include "NyvuxStone/Core/Api/HearthstoneApi.h"
#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorBase.h"
#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorModify.h"

using namespace std;

namespace nyvux
{
	TEST(CardStatDecoratorTest, TestDecoratorBase)
	{
		shared_ptr<CharacterStatDecoratorBase> Base = make_shared<CharacterStatDecoratorBase>();

		EXPECT_EQ(0, Base->GetDeltaAttack());
		EXPECT_EQ(0, Base->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifier)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<CharacterStatDecoratorBase> Base = make_shared<CharacterStatDecoratorBase>();
		shared_ptr<CharacterStatDecoratorBase> Buffed = make_shared<CharacterStatDecoratorModify>(
			Base, BUFF_ATTACK, BUFF_HEALTH);
		
		EXPECT_EQ(BUFF_ATTACK, Buffed->GetDeltaAttack());
		EXPECT_EQ(BUFF_HEALTH, Buffed->GetDeltaHealth());
	}

	TEST(CardStatDecoratorTest, TestModifierMore)
	{
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		shared_ptr<CharacterStatDecoratorBase> Base = make_shared<CharacterStatDecoratorBase>();
		shared_ptr<CharacterStatDecoratorBase> Buffed = make_shared<CharacterStatDecoratorModify>(
			Base, BUFF_ATTACK, BUFF_HEALTH);
		shared_ptr<CharacterStatDecoratorBase> MoreBuffed = make_shared<CharacterStatDecoratorModify>(
			Buffed, BUFF_ATTACK, BUFF_HEALTH);

		EXPECT_EQ(2 * BUFF_ATTACK, MoreBuffed->GetDeltaAttack());
		EXPECT_EQ(2 * BUFF_HEALTH, MoreBuffed->GetDeltaHealth());
	}
}
