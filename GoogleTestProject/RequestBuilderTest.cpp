#include "pch.h"
#include "../HearthStoneFake/RequestBuilder.h"
#include "../HearthStoneFake/ApiConnection.h"

namespace nyvux
{
	TEST(RequestBuilderTest, TestParseUrl)
	{
		using namespace std;
		using namespace nyvux;

		auto Builder = ApiConnection::CreateRequestBuilder()
			.Url("https://www.test.com/path/test?querykey=queryvalue&another=theother")
			.QueryString("key", "value");

		// TODO: Test this.
		//ApiConnection::SendRequest(Builder);
		EXPECT_EQ(1, 1);
	}
}

