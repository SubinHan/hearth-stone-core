#include "testpch.h"

#include "Helper.h"

#include "NyvuxStone/Model/HeroPower/HeroPower.h"
#include "NyvuxStone/Model/HeroPower/MageHeroPower.h"

using namespace std;

namespace nyvux
{
	class HeroPowerTest : public ::testing::Test
	{
	protected:
		void SetUp() override
		{
			Character = MakeMockCharacter();
		}
		std::shared_ptr<HeroPower> HeroPower = nullptr;
		std::shared_ptr<MockCharacter> Character;
	};

	TEST_F(HeroPowerTest, TestMageException)
	{
		HeroPower = make_shared<MageHeroPower>();

		EXPECT_THROW({
				HeroPower->Use();
			}, HeroPowerException);
	}

	TEST_F(HeroPowerTest, TestMage)
	{
		HeroPower = make_shared<MageHeroPower>();
		EXPECT_CALL(*Character, GainDamage(1));

		HeroPower->UseTo(Character);
	}

	
}
