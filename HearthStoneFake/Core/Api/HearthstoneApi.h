#pragma once

#include <vector>
#include <string>

#include "../../Model/Card/CardSpec.h"
#include "ApiConnection.h"

#include <boost/json.hpp>

namespace nyvux
{
	class HearthstoneApi
	{
	public:
		HearthstoneApi() = default;
		virtual ~HearthstoneApi() = default;
		virtual const std::vector<std::string> GetAllCardList();
		virtual const CardSpec GetCardSpecById(const int Id);
		virtual const std::vector<CardSpec> GetCardSpecsByPage(const int Page);

	public:
		static constexpr std::string_view OAUTH_URL_HOST{ "oauth.battle.net" };
		static constexpr std::string_view API_URL_HOST{ "us.api.blizzard.com" };
		static constexpr std::string_view API_TARGET_CARD_SEARCH{ "/hearthstone/cards" };
		static constexpr std::string_view OAUTH_TARGET_TOKEN{ "/token" };
		static constexpr std::string_view ENV_ID{ "BLIZZARD_API_CLIENT_ID" };
		static constexpr std::string_view ENV_SECRET{ "BLIZZARD_API_CLIENT_SECRET" };
		static constexpr std::string_view HEADER_AUTHORIZATION = "Authorization";
		static constexpr std::string_view QUERY_LOCALE_KEY = "locale";
		static constexpr std::string_view QUERY_LOCALE_VALUE = "en_US";
		static constexpr std::string_view QUERY_PAGE_KEY = "page";
		static constexpr std::string_view QUERY_PAGE_SIZE_KEY = "pageSize";
		static constexpr std::string_view QUERY_PAGE_SIZE_VALUE = "500";

	};
}