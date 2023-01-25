#include "pch.h"

#include "../HearthStoneFake/Core/Api/HearthstoneApi.h"
#include "../HearthStoneFake/Model/Card/CardStat.h"
#include "../HearthStoneFake/Model/Card/CardSpec.h"
#include "../HearthStoneFake/Model/Card/CardStatDecoratorModifier.h"
#include "../HearthStoneFake/Model/Card/CardStatDecoratorSilence.h"
#include <vector>

using namespace std;

namespace nyvux
{
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
	TEST_F(CardStatTest, TestVanilla)
	{
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;
		constexpr int EXPECTED_CURRENT_HEALTH = 5;

		CardStat CardStat(CardSpec);

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestBuff)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 5;
		constexpr int EXPECTED_MAX_HEALTH = 7;
		constexpr int EXPECTED_CURRENT_HEALTH = 7;

		CardStat CardStat(CardSpec);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestBuffMore)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 6;
		constexpr int EXPECTED_MAX_HEALTH = 9;
		constexpr int EXPECTED_CURRENT_HEALTH = 9;

		CardStat CardStat(CardSpec);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestSilence)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;
		constexpr int EXPECTED_CURRENT_HEALTH = 5;

		CardStat CardStat(CardSpec);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);
		CardStat.Modify<CardStatDecoratorSilence>();

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestSilenceAndBuff)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 5;
		constexpr int EXPECTED_MAX_HEALTH = 7;
		constexpr int EXPECTED_CURRENT_HEALTH = 7;

		CardStat CardStat(CardSpec);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);
		CardStat.Modify<CardStatDecoratorSilence>();
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestDamage)
	{
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;

		CardStat CardStat(CardSpec);

		CardStat.Damage(AMOUNT_DAMAGE);

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestDamageAndBuff)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 5;
		constexpr int EXPECTED_MAX_HEALTH = 7;

		CardStat CardStat(CardSpec);

		CardStat.Damage(AMOUNT_DAMAGE);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestDamageAndNerf)
	{
		constexpr int MODIFY_ATTACK = -1;
		constexpr int MODIFY_HEALTH = -2;
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 3;
		constexpr int EXPECTED_MAX_HEALTH = 3;


		CardStat CardStat(CardSpec);

		CardStat.Damage(AMOUNT_DAMAGE);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestDamageAndNerfAndSilence)
	{
		constexpr int MODIFY_ATTACK = -1;
		constexpr int MODIFY_HEALTH = -2;
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;

		CardStat CardStat(CardSpec);

		CardStat.Damage(AMOUNT_DAMAGE);
		CardStat.Modify<CardStatDecoratorModifier>(MODIFY_ATTACK, MODIFY_HEALTH);
		CardStat.Modify<CardStatDecoratorSilence>();

		EXPECT_EQ(EXPECTED_ATTACK, CardStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CardStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestDamageAndHeal)
	{
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int AMOUNT_HEAL = 1;
		constexpr int EXPECTED_HEALTH = 4;

		CardStat CardStat(CardSpec);

		CardStat.Damage(AMOUNT_DAMAGE);
		CardStat.Heal(AMOUNT_HEAL);

		EXPECT_EQ(EXPECTED_HEALTH, CardStat.GetCurrentHealth());
	}

	TEST_F(CardStatTest, TestOverHeal)
	{
		constexpr int AMOUNT_HEAL = 99;
		constexpr int EXPECTED_HEALTH = 5;

		CardStat CardStat(CardSpec);

		CardStat.Heal(AMOUNT_HEAL);

		EXPECT_EQ(EXPECTED_HEALTH, CardStat.GetCurrentHealth());
	}

}
