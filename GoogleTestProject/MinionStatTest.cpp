#include "pch.h"

#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorModify.h"
#include "NyvuxStone/Core/Game/Decorator/CharacterStat/CharacterStatDecoratorSilence.h"
#include "NyvuxStone/Model/Card/CharacterStat.h"
#include "NyvuxStone/Model/Card/CardSpec.h"

#include "Helper.h"

using namespace std;

namespace nyvux
{
	class CharacterStatTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			constexpr int CARD_ID = MOCK_CARD_ID;
			CardSpec = MakeCardSpecRepositoryToMock().GetCardSpecById(CARD_ID);
		}

		CardSpec CardSpec;
	};
	TEST_F(CharacterStatTest, TestVanilla)
	{
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;
		constexpr int EXPECTED_CURRENT_HEALTH = 5;

		CharacterStat CharacterStat(CardSpec);

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestBuff)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 5;
		constexpr int EXPECTED_MAX_HEALTH = 7;
		constexpr int EXPECTED_CURRENT_HEALTH = 7;

		CharacterStat CharacterStat(CardSpec);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestBuffMore)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 6;
		constexpr int EXPECTED_MAX_HEALTH = 9;
		constexpr int EXPECTED_CURRENT_HEALTH = 9;

		CharacterStat CharacterStat(CardSpec);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestSilence)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;
		constexpr int EXPECTED_CURRENT_HEALTH = 5;

		CharacterStat CharacterStat(CardSpec);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);
		CharacterStat.Modify<CharacterStatDecoratorSilence>();

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestSilenceAndBuff)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int EXPECTED_ATTACK = 5;
		constexpr int EXPECTED_MAX_HEALTH = 7;
		constexpr int EXPECTED_CURRENT_HEALTH = 7;

		CharacterStat CharacterStat(CardSpec);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);
		CharacterStat.Modify<CharacterStatDecoratorSilence>();
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_CURRENT_HEALTH, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestDamage)
	{
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;

		CharacterStat CharacterStat(CardSpec);

		CharacterStat.Damage(AMOUNT_DAMAGE);

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestDamageAndBuff)
	{
		constexpr int MODIFY_ATTACK = 1;
		constexpr int MODIFY_HEALTH = 2;
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 5;
		constexpr int EXPECTED_MAX_HEALTH = 7;

		CharacterStat CharacterStat(CardSpec);

		CharacterStat.Damage(AMOUNT_DAMAGE);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestDamageAndNerf)
	{
		constexpr int MODIFY_ATTACK = -1;
		constexpr int MODIFY_HEALTH = -2;
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 3;
		constexpr int EXPECTED_MAX_HEALTH = 3;


		CharacterStat CharacterStat(CardSpec);

		CharacterStat.Damage(AMOUNT_DAMAGE);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestDamageAndNerfAndSilence)
	{
		constexpr int MODIFY_ATTACK = -1;
		constexpr int MODIFY_HEALTH = -2;
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int EXPECTED_ATTACK = 4;
		constexpr int EXPECTED_MAX_HEALTH = 5;

		CharacterStat CharacterStat(CardSpec);

		CharacterStat.Damage(AMOUNT_DAMAGE);
		CharacterStat.Modify<CharacterStatDecoratorModify>(MODIFY_ATTACK, MODIFY_HEALTH);
		CharacterStat.Modify<CharacterStatDecoratorSilence>();

		EXPECT_EQ(EXPECTED_ATTACK, CharacterStat.GetAttack());
		EXPECT_EQ(EXPECTED_MAX_HEALTH, CharacterStat.GetMaxHealth());
		EXPECT_EQ(EXPECTED_MAX_HEALTH - AMOUNT_DAMAGE, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestDamageAndHeal)
	{
		constexpr int AMOUNT_DAMAGE = 2;
		constexpr int AMOUNT_HEAL = 1;
		constexpr int EXPECTED_HEALTH = 4;

		CharacterStat CharacterStat(CardSpec);

		CharacterStat.Damage(AMOUNT_DAMAGE);
		CharacterStat.Heal(AMOUNT_HEAL);

		EXPECT_EQ(EXPECTED_HEALTH, CharacterStat.GetCurrentHealth());
	}

	TEST_F(CharacterStatTest, TestOverHeal)
	{
		constexpr int AMOUNT_HEAL = 99;
		constexpr int EXPECTED_HEALTH = 5;

		CharacterStat CharacterStat(CardSpec);

		CharacterStat.Heal(AMOUNT_HEAL);

		EXPECT_EQ(EXPECTED_HEALTH, CharacterStat.GetCurrentHealth());
	}
	
}
