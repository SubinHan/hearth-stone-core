#pragma once

#include <vector>
#include <string>

#include "CardSpec.h"
#include "ApiConnection.h"

namespace nyvux
{
	class HearthstoneApi
	{
	public:
		static const std::vector<std::string> GetAllCardList();
		//static const std::string GetEnv(std::string Key);
		static const CardSpec GetCardSpecById(const int id);

	public:
		static constexpr std::string_view OAUTH_URL_HOST{ "oauth.battle.net" };
		static constexpr std::string_view API_URL_HOST{ "us.api.blizzard.com" };
		static constexpr std::string_view API_TARGET_CARD_SEARCH{ "/hearthstone/cards" };
		static constexpr std::string_view OAUTH_TARGET_TOKEN{ "/token" };
		static constexpr std::string_view ENV_ID{ "BLIZZARD_API_CLIENT_ID" };
		static constexpr std::string_view ENV_SECRET{ "BLIZZARD_API_CLIENT_SECRET" };
		
	private:
		static CardSpec ParseToCard(std::string_view JsonContent);
	};
}