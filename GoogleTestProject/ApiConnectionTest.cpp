#include "pch.h"
#include "../HearthStoneFake/Core/Api/ApiConnection.h"

namespace nyvux
{
	TEST(ApiConnectionTest, TestBasicRequest) 
	{
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(true);

		using namespace std;
		using namespace nyvux;

		const string Host = "jsonplaceholder.typicode.com";
		const string Target = "/posts/1";

		string const Expected = "{\n"
			"  \"userId\": 1,\n"
			"  \"id\": 1,\n"
			"  \"title\": \"sunt aut facere repellat provident occaecati excepturi optio reprehenderit\",\n"
			"  \"body\": \"quia et suscipit\\nsuscipit recusandae consequuntur expedita et cum\\nreprehenderit molestiae ut ut quas totam\\nnostrum rerum est autem sunt rem eveniet architecto\"\n"
			"}";

		try
		{
			auto RequestBuilder = RequestBuilder::CreateRequestBuilder()
				.Url(Host + Target)
				.Port(80);

			ApiConnection& Connection = ApiConnection::GetInstance();
			string Response = Connection.SendRequest(RequestBuilder.Build());

			EXPECT_EQ(Expected, Response);
		}
		catch (std::exception const& ex)
		{
			FAIL() << ex.what();
		}
	}
}

