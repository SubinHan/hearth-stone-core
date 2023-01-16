#include "pch.h"
#include "CppUnitTest.h"

#include "../HearthStoneFake/HearthstoneApiAuth.h"

#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace nyvux
{
	TEST_CLASS(HearthstoneApiAuthTest)
	{
	public:

		TEST_METHOD(TestSingleton)
		{
			using namespace std;

			HearthstoneApiAuth& Singleton =
				HearthstoneApiAuth::GetInstance();
			
			Assert::IsTrue(&Singleton == &HearthstoneApiAuth::GetInstance());
		}

		TEST_METHOD(TestAuth)
		{
			HearthstoneApiAuth& Auth = HearthstoneApiAuth::GetInstance();

			const AccessToken Token = Auth.GetAccessToken();

			Assert::IsFalse(Token.Token.empty());
			Assert::AreEqual(Token.Type, std::string("bearer"));
			Assert::IsTrue(Token.ExpiresIn > 0);
			Assert::IsTrue(Token.Scope.empty());
		}

		TEST_METHOD(TestAuthReusesToken)
		{
			HearthstoneApiAuth& Auth = HearthstoneApiAuth::GetInstance();

			const AccessToken Token = Auth.GetAccessToken();

			Assert::IsFalse(Token.Token.empty());
			Assert::AreEqual(Token.Type, std::string("bearer"));
			Assert::IsTrue(Token.ExpiresIn > 0);
			Assert::IsTrue(Token.Scope.empty());

			const AccessToken AnotherToken = Auth.GetAccessToken();

			Assert::IsTrue(Token == AnotherToken);
		}
	};
}
