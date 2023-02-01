#include "pch.h"

#include "NyvuxStone/Model/Card/CardFactory.h"
#include "NyvuxStone/Model/Card/Card.h"
#include "NyvuxStone/Model/Player/Hand.h"

#include "Helper.h"

using namespace std;

namespace nyvux
{
	class MinionStatDecoratorModify;

	class HandTest : public ::testing::Test
	{
	protected:
		static constexpr int CARD_ID = 69543;

		void SetUp() override
		{
			MakeCardSpecRepositoryToMock();
			Hand = Hand::CreateHand();
		}

		std::shared_ptr<Hand> Hand;
	};

	TEST_F(HandTest, TestGetNumCards)
	{
		shared_ptr<Card> Card = CardFactory::CreateMinionById(69543);

		EXPECT_EQ(0, Hand->GetNumCards());
		Hand->AddCard(Card);
		EXPECT_EQ(1, Hand->GetNumCards());
	}

	TEST_F(HandTest, TestIsFull)
	{
		for(int i = 0; i < 10; i++)
		{
			EXPECT_FALSE(Hand->IsFull());
			shared_ptr<Card> Card = CardFactory::CreateMinionById(69543);
			Hand->AddCard(Card);
		}

		EXPECT_TRUE(Hand->IsFull());
	}

	TEST_F(HandTest, TestAddCardALot)
	{
		EXPECT_EQ(0, Hand->GetNumCards());

		for (int i = 0; i < 10; i++)
		{
			shared_ptr<Card> Card = CardFactory::CreateMinionById(69543);
			Hand->AddCard(Card);
		}

		for (int i = 0; i < 100; i++)
		{
			shared_ptr<Card> Card = CardFactory::CreateDummyMinion();
			Hand->AddCard(Card);
		}

		Card Expected = *CardFactory::CreateMinionById(69543);

		EXPECT_EQ(10, Hand->GetNumCards());
		EXPECT_TRUE(Expected.GetCardSpec() == (*Hand->GetCard(0)).GetCardSpec());
		EXPECT_TRUE(Expected.GetCardSpec() == (*Hand->GetCard(9)).GetCardSpec());
	}

	TEST_F(HandTest, TestRemoveCard)
	{
		EXPECT_EQ(0, Hand->GetNumCards());

		{
			shared_ptr<Card> Card = CardFactory::CreateMinionById(69543);
			Hand->AddCard(Card);
		}

		for (int i = 0; i < 9; i++)
		{
			shared_ptr<Card> Card = CardFactory::CreateDummyMinion();
			Hand->AddCard(Card);
		}

		shared_ptr<Card> Removed = Hand->RemoveCard(0);
		Card Expected = *CardFactory::CreateMinionById(69543);

		EXPECT_TRUE(Expected.GetCardSpec() == Removed->GetCardSpec());
		EXPECT_EQ(9, Hand->GetNumCards());
		EXPECT_FALSE(Expected.GetCardSpec() == Hand->GetCard(0)->GetCardSpec());
	}

}
