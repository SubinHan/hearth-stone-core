#include "pch.h"
#include "CppUnitTest.h"

#include "../HearthStoneFake/ApiConnection.h"
#include "../HearthStoneFake/HearthstoneApi.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace nyvux
{
	TEST_CLASS(ApiConnectionTest)
	{
	public:
		
		TEST_METHOD(TestBasicRequest)
		{
			using namespace std;
			using namespace nyvux;

			auto const Host = "jsonplaceholder.typicode.com";
			auto const Target = "/posts/1";


			string const Expected = "{\n"
				"  \"userId\": 1,\n"
				"  \"id\": 1,\n"
				"  \"title\": \"sunt aut facere repellat provident occaecati excepturi optio reprehenderit\",\n"
				"  \"body\": \"quia et suscipit\\nsuscipit recusandae consequuntur expedita et cum\\nreprehenderit molestiae ut ut quas totam\\nnostrum rerum est autem sunt rem eveniet architecto\"\n"
				"}";
			try
			{
				ApiConnection Connection(Host);
				RequestBuilder Request =
					Connection.CreateRequestBuilder()
					.Target(Target);

				string Response = Connection.SendRequest(Request);
				Assert::AreEqual(Expected, Response);
				Logger::WriteMessage(Response.c_str());
			}
			catch (std::exception const& ex) 
			{
				Logger::WriteMessage(ex.what());
				Assert::Fail();
			}
		}
	};
}
