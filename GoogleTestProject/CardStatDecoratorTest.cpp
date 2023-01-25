#include "pch.h"

#include "../HearthStoneFake/HearthstoneApi.h"
#include "../HearthStoneFake/ICardStat.h"
#include "../HearthStoneFake/CardSpec.h"
#include "../HearthStoneFake/ICardStatDecorator.h"
#include "../HearthStoneFake/CardStatVanilla.h"
#include "../HearthStoneFake/CardStatDecoratorModifier.h"
#include <vector>
#include <memory>

using namespace std;

namespace nyvux
{
	TEST(CardStatDecoratorTest, TestVanillaCard)
	{
		constexpr int CARD_ID = 69543;

		CardSpec Spec = HearthstoneApi::GetCardSpecById(CARD_ID);

		shared_ptr<ICardStat> Vanilla = make_shared<CardStatVanilla>(Spec);

		EXPECT_EQ(Spec.Attack, Vanilla->GetAttack());
		EXPECT_EQ(Spec.Health, Vanilla->GetMaxHealth());
	}

	TEST(CardStatDecoratorTest, TestModifier)
	{
		constexpr int CARD_ID = 69543;
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		CardSpec Spec = HearthstoneApi::GetCardSpecById(CARD_ID);

		shared_ptr<ICardStat> Vanilla = make_shared<CardStatVanilla>(Spec);
		shared_ptr<ICardStat> Buffed = make_shared<CardStatDecoratorModifier>(
			Vanilla, BUFF_ATTACK, BUFF_HEALTH);
		
		EXPECT_EQ(Spec.Attack + BUFF_ATTACK, Buffed->GetAttack());
		EXPECT_EQ(Spec.Health + BUFF_HEALTH, Buffed->GetMaxHealth());
	}

	TEST(CardStatDecoratorTest, TestModifierMore)
	{
		constexpr int CARD_ID = 69543;
		constexpr int BUFF_ATTACK = 1;
		constexpr int BUFF_HEALTH = 2;

		CardSpec Spec = HearthstoneApi::GetCardSpecById(CARD_ID);

		shared_ptr<ICardStat> Vanilla = make_shared<CardStatVanilla>(Spec);
		shared_ptr<ICardStat> Buffed = make_shared<CardStatDecoratorModifier>(
			Vanilla, BUFF_ATTACK, BUFF_HEALTH);
		shared_ptr<ICardStat> MoreBuffed = make_shared<CardStatDecoratorModifier>(
			Buffed, BUFF_ATTACK, BUFF_HEALTH);

		EXPECT_EQ(Spec.Attack + 2 * BUFF_ATTACK, MoreBuffed->GetAttack());
		EXPECT_EQ(Spec.Health + 2 * BUFF_HEALTH, MoreBuffed->GetMaxHealth());
	}
}
