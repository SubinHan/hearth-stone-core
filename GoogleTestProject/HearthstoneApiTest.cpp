#include "pch.h"

#include "NyvuxStone/Core/Api/HearthstoneApi.h"
#include "NyvuxStone/Model/Card/CardSpec.h"
#include "NyvuxStone/Model/Card/CardSpecRepository.h"
#include <vector>

using namespace std;

namespace nyvux
{
	TEST(HearthstoneApiTest, TestGetCardById)
	{
		using namespace std;

		constexpr int CARD_ID = 79593;

		CardSpec Expected = {};
		Expected.CardId = CARD_ID;
		Expected.Collectible = true;
		Expected.Slug = "79593-all-fel-breaks-loose";
		Expected.ClassId = 14;
		Expected.MultiClassIds = vector<int>{};
		Expected.SpellSchoolId = 7;
		Expected.CardTypeId = 5;
		Expected.CardSetId = 1691;
		Expected.RarityId = 1;
		Expected.ManaCost = 5;
		Expected.Name = string("All Fel Breaks Loose");
		Expected.Text = string("Summon a friendly Demon that died this game. <b>Infuse ( Demons):</b> Summon three instead.");
		Expected.ParentId = CARD_ID;
		vector<int> ExpectedChildIds;
		ExpectedChildIds.push_back(79595);
		Expected.ChildIds = ExpectedChildIds;
		vector<int> ExpectedKeywordIds;
		ExpectedKeywordIds.push_back(238);
		Expected.KeywordIds = ExpectedKeywordIds;

		CardSpec Actual = HearthstoneApi().GetCardSpecById(CARD_ID);

		EXPECT_TRUE(Expected == Actual);
	}

	TEST(HearthstoneApiTest, TestGetCardByIdInvalid)
	{
		using namespace std;

		constexpr int CARD_ID = 1;
		
		CardSpec Expected = CardSpecRepository::INVALID_CARDSPEC;
		CardSpec Actual = HearthstoneApi().GetCardSpecById(CARD_ID);

		EXPECT_TRUE(Expected == Actual);
	}

	TEST(HearthstoneApiTest, TestGetAllCards)
	{
		int TotalNumCards{ 0 };

		for (int i = 1;; i++)
		{
			vector<CardSpec> CardSpecs = HearthstoneApi().GetCardSpecsByPage(i);
			TotalNumCards += static_cast<int>(CardSpecs.size());

			if (CardSpecs.empty())
				break;
		}

		EXPECT_TRUE(TotalNumCards >= 4500);
	}

}
