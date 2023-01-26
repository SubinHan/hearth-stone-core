#include "pch.h"

#include "../HearthStoneFake/Model/Card/CardFactory.h"
#include "../HearthStoneFake/Model/Card/Minion.h"
#include "../HearthStoneFake/Model/Player/Field.h"

#include <memory>

using namespace std;

namespace nyvux
{
	class MinionStatDecoratorModifier;

	class FieldTest : public ::testing::Test
	{
	protected:
		static constexpr int CARD_ID = 69543;

		void SetUp() override
		{
			Field = Field::CreateField();
		}
		
		shared_ptr<Field> Field;
	};
	TEST_F(FieldTest, TestGetNumPlayed)
	{
		shared_ptr<Minion> Minion = CardFactory::CreateMinionById(CARD_ID);
		EXPECT_EQ(0, Field->GetNumPlayed());
		Field->PutMinion(Minion, 0);
		EXPECT_EQ(1, Field->GetNumPlayed());
	}

	TEST_F(FieldTest, TestPutMinion)
	{
		EXPECT_TRUE(Field->CanPutMinion());

		shared_ptr<Minion> Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_FALSE(Field->CanPutMinion());
	}


	TEST_F(FieldTest, TestPutMinionWeird)
	{
		EXPECT_TRUE(Field->CanPutMinion());

		shared_ptr<Minion> Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, -1);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 230);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, -58432);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 3);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 514823);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, -4295);
		EXPECT_TRUE(Field->CanPutMinion());

		Minion = CardFactory::CreateMinionById(CARD_ID);
		Field->PutMinion(Minion, 0);
		EXPECT_FALSE(Field->CanPutMinion());
	}

}
