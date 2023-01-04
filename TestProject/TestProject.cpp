#include "pch.h"
#include "CppUnitTest.h"

#include <string>
#include "../HearthStoneFake/ApiConnection.cpp"
#include "../HearthStoneFake/HearthstoneApi.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(TestProject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			using namespace std;
			using namespace nyvux;

			auto const Host = "jsonplaceholder.typicode.com";
			auto const Port = "80";
			auto const Target = "/posts/1";

			const string Id = HearthstoneApi::GetEnv(HearthstoneApi::ENV_ID);
			const string Secret = HearthstoneApi::GetEnv(HearthstoneApi::ENV_SECRET);
			const string AuthContent = Id + ":" + Secret;
			auto const Data = "grant_type=client_credentials";

			ApiConnection Connection(Host);
			string Res = 
				Connection.RequestBuilder()
					.Target(Target)
					.Authentification(AuthContent)
					.Data(Data)
					.Request();

			cout << Res << endl;
		}
	};
}
