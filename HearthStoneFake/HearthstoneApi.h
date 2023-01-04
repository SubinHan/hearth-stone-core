#pragma once

#include <vector>
#include <string>

namespace nyvux
{
	class HearthstoneApi
	{
	public:
		static const std::vector<std::string> GetAllCardList();
		static const std::string GetEnv(std::string Key);

	public:
		static constexpr std::string_view URL_HOST{ "oauth.battle.net" };
		static constexpr std::string_view URL_TARGET_TOKEN{ "/token" };
		static constexpr std::string_view ENV_ID{ "BLIZZARD_API_CLIENT_ID" };
		static constexpr std::string_view ENV_SECRET{ "BLIZZARD_API_CLIENT_SECRET" };
		
	};
}