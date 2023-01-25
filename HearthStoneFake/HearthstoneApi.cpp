#include "HearthstoneApi.h"
#include "HearthstoneApiAuth.h"
#include "CardSpecRepository.h"
#include "Request.h"

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
				Result.push_back(static_cast<int>(*Value));
		}
		return Result;
	}

	const AccessToken GetAccessToken()
	{
		auto& Auth = HearthstoneApiAuth::GetInstance();
		return Auth.GetAccessToken();
	}

	const string MakeAuthorizationContent(AccessToken Token)
	{
		return "Bearer " + Token.Token;
	}


	CardSpec ParseToCard(boost::json::object JsonContent)
	{
		if (auto Value = JsonContent["error"].if_object())
			return CardSpecRepository::INVALID_CARDSPEC;

		CardSpec Result{};

		if (auto Value = JsonContent[CardSpec::KEY_CARD_ID].if_int64())
			Result.CardId = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_COLLECTIBLE].if_int64())
			Result.Collectible = static_cast<bool>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_SLUG].if_string())
			Result.Slug = *Value;
		if (auto Value = JsonContent[CardSpec::KEY_CLASS_ID].if_int64())
			Result.ClassId = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_MULTI_CLASS_IDS].if_array())
			Result.MultiClassIds = JsonArrayToVector(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_SPELL_SCHOOL_ID].if_int64())
			Result.SpellSchoolId = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_CARD_TYPE_ID].if_int64())
			Result.CardTypeId = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_CARD_SET_ID].if_int64())
			Result.CardSetId = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_RARITY_ID].if_int64())
			Result.RarityId = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_HEALTH].if_int64())
			Result.Health = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_ATTACK].if_int64())
			Result.Attack = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_MANA_COST].if_int64())
			Result.ManaCost = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_NAME].if_string())
			Result.Name = *Value;
		if (auto Value = JsonContent[CardSpec::KEY_TEXT].if_string())
			Result.Text = *Value;
		if (auto Value = JsonContent[CardSpec::KEY_PARENT_ID].if_int64())
			Result.ParentId = static_cast<int>(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_CHILD_IDS].if_array())
			Result.ChildIds = JsonArrayToVector(*Value);
		if (auto Value = JsonContent[CardSpec::KEY_KEYWORD_IDS].if_array())
			Result.KeywordIds = JsonArrayToVector(*Value);

		return Result;
	}
}

const vector<string> HearthstoneApi::GetAllCardList()
{
	return vector<string>{};
}

const CardSpec HearthstoneApi::GetCardSpecById(const int id)
{
	auto Token = GetAccessToken();

	auto RequestBuilder = RequestBuilder::CreateRequestBuilder()
		.Url(string(API_URL_HOST) + string(API_TARGET_CARD_SEARCH) + "/" + to_string(id) + "?locale=en_US")
		.PutHeader(string(HEADER_AUTHORIZATION), MakeAuthorizationContent(Token))
		.Method(EMethod::GET);

	ApiConnection& Connection = ApiConnection::GetInstance();

	string Response = Connection.SendRequest(RequestBuilder.Build());

	auto Converted = json::parse(Response).as_object();

	return ParseToCard(Converted);
}

const std::vector<CardSpec> nyvux::HearthstoneApi::GetCardSpecsByPage(const int Page)
{
	auto Token = GetAccessToken();

	auto RequestBuilder = RequestBuilder::CreateRequestBuilder()
		.Url(string(API_URL_HOST) + string(API_TARGET_CARD_SEARCH))
		.PutHeader(string(HEADER_AUTHORIZATION), MakeAuthorizationContent(Token))
		.Method(EMethod::GET)
		.PutQueryString(string(QUERY_LOCALE_KEY), string(QUERY_LOCALE_VALUE))
		.PutQueryString(string(QUERY_PAGE_KEY), to_string(Page))
		.PutQueryString(string(QUERY_PAGE_SIZE_KEY), string(QUERY_PAGE_SIZE_VALUE));

	ApiConnection& Connection = ApiConnection::GetInstance();

	string Response = Connection.SendRequest(RequestBuilder.Build());

	auto JsonContent = json::parse(Response).as_object();

	auto Value = JsonContent["cards"].if_array();
	auto Cards = JsonContent["cards"].as_array();

	vector<CardSpec> Result;

	for (auto Iter = Cards.begin(); Iter != Cards.end(); Iter++)
	{
		if (auto Value = Iter->if_object())
			Result.push_back(ParseToCard(*Value));
	}

	auto Cardsas = JsonContent["cards"].as_array();

	for (auto Card : Cards)
	{
		if (auto Value = Card.if_object())
			Result.push_back(ParseToCard(*Value));
	}

	return Result;
}
