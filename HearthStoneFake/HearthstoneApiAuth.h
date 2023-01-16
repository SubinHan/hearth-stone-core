#pragma once

#include <string>

namespace nyvux
{
	struct AccessToken
	{
		std::string Type;
		std::string Token;
		int ExpiresIn;
		std::string Scope;

		AccessToken() : Type(""), Token(""), ExpiresIn(0), Scope("") {}

		bool operator==(const AccessToken&) const = default;
	};

	class HearthstoneApiAuth
	{
	public:
		HearthstoneApiAuth(const HearthstoneApiAuth& ref) = delete;
		HearthstoneApiAuth& operator=(const HearthstoneApiAuth& ref) = delete;

		static HearthstoneApiAuth& GetInstance();
		const AccessToken GetAccessToken();

	private:
		HearthstoneApiAuth();
		~HearthstoneApiAuth();

	private:
		static constexpr std::string_view KEY_ACCESS_TOKEN = "access_token";
		static constexpr std::string_view KEY_TOKEN_TYPE = "token_type";
		static constexpr std::string_view KEY_EXPIRES_IN = "expires_in";
		static constexpr std::string_view KEY_SCOPE = "scope";

		bool bHasToken;
		AccessToken Token;
	};

}