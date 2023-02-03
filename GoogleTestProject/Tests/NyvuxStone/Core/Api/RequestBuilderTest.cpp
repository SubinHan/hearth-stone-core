#include "testpch.h"
#include "NyvuxStone/Core/Api/Request.h"

namespace nyvux
{
	TEST(RequestBuilderTest, TestParseUrl)
	{
		using namespace std;
		using namespace nyvux;

		auto Builder = RequestBuilder::CreateRequestBuilder()
			.Url("https://www.test.com/path/test?querykey=queryvalue&another=theother")
			.PutQueryString("key", "value");

		// TODO: Test this.
		//ApiConnection::SendRequest(Builder);
		EXPECT_EQ(1, 1);
	}
}

