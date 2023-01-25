#include "pch.h"

#include "../HearthStoneFake/Core/Api/HearthstoneApiAuth.h"

#include <memory>

namespace nyvux
{
	TEST(HearthstoneApiAuthTest, TestSingleton) 
	{
		using namespace std;

		HearthstoneApiAuth& Singleton =
			HearthstoneApiAuth::GetInstance();

		EXPECT_TRUE(&Singleton == &HearthstoneApiAuth::GetInstance());
	}

	TEST(HearthstoneApiAuthTest, TestAuth) 
	{
		HearthstoneApiAuth& Auth = HearthstoneApiAuth::GetInstance();

		const AccessToken Token = Auth.GetAccessToken();

		EXPECT_FALSE(Token.Token.empty());
		EXPECT_EQ(Token.Type, std::string("bearer"));
		EXPECT_TRUE(Token.ExpiresIn > 0);
		EXPECT_TRUE(Token.Scope.empty());
	}

	TEST(HearthstoneApiAuthTest, TestReusesToken)
	{
		HearthstoneApiAuth& Auth = HearthstoneApiAuth::GetInstance();

		const AccessToken Token = Auth.GetAccessToken();

		EXPECT_FALSE(Token.Token.empty());
		EXPECT_EQ(Token.Type, std::string("bearer"));
		EXPECT_TRUE(Token.ExpiresIn > 0);
		EXPECT_TRUE(Token.Scope.empty());

		const AccessToken AnotherToken = Auth.GetAccessToken();

		EXPECT_TRUE(Token == AnotherToken);
	}
}
