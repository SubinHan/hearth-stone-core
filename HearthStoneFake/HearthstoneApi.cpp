#include "HearthstoneApi.h"
#include "HearthstoneApiAuth.h"

#include <nyvux/utils/EnvironmentVariableReader.h>

#include <boost/beast/core/detail/base64.hpp>
#include <boost/json.hpp>

using namespace std;
using namespace nyvux;
using namespace boost;

namespace nyvux
{
	vector<int> JsonArrayToVector(json::array& JsonArray)
	{
		vector<int> Result;
		for (auto iter = JsonArray.begin(); iter != JsonArray.end(); iter++)
		{
			if (auto Value = iter->if_int64())
				Result.push_back(*Value);
		}
		return Result;
	}
}

const vector<string> HearthstoneApi::GetAllCardList()
{
	return vector<string>{};
}

const Card HearthstoneApi::GetCardById(const int id)
{

	auto& Auth = HearthstoneApiAuth::GetInstance();
	AccessToken Token = Auth.GetAccessToken();

	auto Request = ApiConnection::CreateRequestBuilder()
		.Url(string(API_URL_HOST) + string(API_TARGET_CARD_SEARCH) + "/" + to_string(id) + "?locale=en_US")
		.Header("Authorization", "Bearer " + Token.Token)
		.Method(RequestBuilder::EMethod::GET);

	string Response = ApiConnection::SendRequest(Request);

	return ParseToCard(Response);
}

Card HearthstoneApi::ParseToCard(std::string_view JsonContent)
{
	auto Converted = json::parse(JsonContent).as_object();

	Card Result{};

	if (auto Value = Converted[Card::KEY_CARD_ID].if_int64())
		Result.CardId = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_COLLECTIBLE].if_int64())
		Result.Collectible = static_cast<bool>(*Value);
	if (auto Value = Converted[Card::KEY_SLUG].if_string())
		Result.Slug = *Value;
	if (auto Value = Converted[Card::KEY_CLASS_ID].if_int64())
		Result.ClassId = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_MULTI_CLASS_IDS].if_array())
	{
		Result.MultiClassIds = JsonArrayToVector(*Value);
	}
	if (auto Value = Converted[Card::KEY_SPELL_SCHOOL_ID].if_int64())
		Result.SpellSchoolId = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_CARD_TYPE_ID].if_int64())
		Result.CardTypeId = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_CARD_SET_ID].if_int64())
		Result.CardSetId = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_RARITY_ID].if_int64())
		Result.RarityId = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_MANA_COST].if_int64())
		Result.ManaCost = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_NAME].if_string())
		Result.Name = *Value;
	if (auto Value = Converted[Card::KEY_TEXT].if_string())
		Result.Text = *Value;
	if (auto Value = Converted[Card::KEY_PARENT_ID].if_int64())
		Result.ParentId = static_cast<int>(*Value);
	if (auto Value = Converted[Card::KEY_CHILD_IDS].if_array())
	{
		Result.ChildIds = JsonArrayToVector(*Value);
	}
	if (auto Value = Converted[Card::KEY_KEYWORD_IDS].if_array())
	{
		Result.KeywordIds = JsonArrayToVector(*Value);
	}

	return Result;
}
