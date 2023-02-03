#include "pch.h"

#include "NyvuxStone/Model/Player/Hero.h"

using namespace std;

namespace nyvux
{
	class HeroTest : public ::testing::Test
	{
	protected:

		void SetUp() override
		{
			Hero = make_shared<nyvux::Hero>();
		}

		std::shared_ptr<Hero> Hero;
	};

	TEST_F(HeroTest, TestHealth)
	{
		EXPECT_EQ(30, Hero->GetCurrentHealth());
		EXPECT_EQ(30, Hero->GetMaxHealth());
	}

	TEST_F(HeroTest, TestArmor)
	{
		EXPECT_EQ(0, Hero->GetCurrentArmor());

		Hero->GainArmor(5);

		EXPECT_EQ(30, Hero->GetCurrentHealth());
		EXPECT_EQ(5, Hero->GetCurrentArmor());
	}

	TEST_F(HeroTest, TestDamage)
	{
		EXPECT_EQ(30, Hero->GetCurrentHealth());

		Hero->GainDamage(5);

		EXPECT_EQ(25, Hero->GetCurrentHealth());
		EXPECT_EQ(30, Hero->GetMaxHealth());

		Hero->GainArmor(5);
		Hero->GainDamage(10);

		EXPECT_EQ(20, Hero->GetCurrentHealth());
		EXPECT_EQ(0, Hero->GetCurrentArmor());
	}

	TEST_F(HeroTest, TestOverDamage)
	{
		EXPECT_EQ(30, Hero->GetCurrentHealth());

		Hero->GainDamage(5000);

		EXPECT_EQ(0, Hero->GetCurrentHealth());
		EXPECT_EQ(30, Hero->GetMaxHealth());
	}

	TEST_F(HeroTest, TestHeal)
	{
		EXPECT_EQ(30, Hero->GetCurrentHealth());

		Hero->GainDamage(10);

		EXPECT_EQ(20, Hero->GetCurrentHealth());
		EXPECT_EQ(30, Hero->GetMaxHealth());

		Hero->GainArmor(5);
		Hero->GainHeal(5);

		EXPECT_EQ(25, Hero->GetCurrentHealth());
		EXPECT_EQ(5, Hero->GetCurrentArmor());

		Hero->GainHeal(5);

		EXPECT_EQ(30, Hero->GetCurrentHealth());
		EXPECT_EQ(5, Hero->GetCurrentArmor());

		Hero->GainHeal(5);
		EXPECT_EQ(30, Hero->GetMaxHealth());
		EXPECT_EQ(30, Hero->GetCurrentHealth());
		EXPECT_EQ(5, Hero->GetCurrentArmor());
	}

	TEST_F(HeroTest, TestOverHeal)
	{
		EXPECT_EQ(30, Hero->GetCurrentHealth());

		Hero->GainDamage(10);
		Hero->GainArmor(5);

		EXPECT_EQ(20, Hero->GetCurrentHealth());
		EXPECT_EQ(30, Hero->GetMaxHealth());
		EXPECT_EQ(5, Hero->GetCurrentArmor());

		Hero->GainHeal(5000);

		EXPECT_EQ(30, Hero->GetCurrentHealth());
		EXPECT_EQ(30, Hero->GetMaxHealth());
		EXPECT_EQ(5, Hero->GetCurrentArmor());
	}
}
