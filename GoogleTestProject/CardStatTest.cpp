#include "pch.h"

#include "../HearthStoneFake/Core/Api/HearthstoneApi.h"
#include "../HearthStoneFake/Model/Card/CardStat.h"
#include "../HearthStoneFake/Model/Card/CardSpec.h"
#include "../HearthStoneFake/Model/Card/CardStatDecoratorModify.h"

using namespace std;

namespace nyvux
{
	class MinionStatDecoratorModifier;

	class CardStatTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			constexpr int CARD_ID = 69543;
			CardSpec = HearthstoneApi::GetCardSpecById(CARD_ID);
		}

		CardSpec CardSpec;
	};
	TEST_F(CardStatTest, TestModify)
	{
		constexpr int MODIFY_MANA_COST = -1;
		constexpr int EXPECTED_MANA_COST = 3;

		CardStat CardStat(CardSpec);
		CardStat.Modify<CardStatDecoratorModify>(MODIFY_MANA_COST);

		EXPECT_EQ(EXPECTED_MANA_COST, CardStat.GetManaCost());
	}

	TEST_F(CardStatTest, TestModifyMore)
	{
		constexpr int MODIFY_MANA_COST = -1;
		constexpr int EXPECTED_MANA_COST = 0;

		CardStat CardStat(CardSpec);
		CardStat.Modify<CardStatDecoratorModify>(MODIFY_MANA_COST);
		CardStat.Modify<CardStatDecoratorModify>(MODIFY_MANA_COST);
		CardStat.Modify<CardStatDecoratorModify>(MODIFY_MANA_COST);
		CardStat.Modify<CardStatDecoratorModify>(MODIFY_MANA_COST);
		CardStat.Modify<CardStatDecoratorModify>(MODIFY_MANA_COST);
		CardStat.Modify<CardStatDecoratorModify>(MODIFY_MANA_COST);

		EXPECT_EQ(EXPECTED_MANA_COST, CardStat.GetManaCost());
	}

}
