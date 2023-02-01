#include "NyvuxStone/Core/Api/HearthstoneApiAuth.h"

#include "NyvuxStone/Core/Api/HearthstoneApi.h"

#include <boost/beast/core/detail/base64.hpp>
#include <boost/json.hpp>
#include <nyvux/utils/EnvironmentVariableReader.h>


using namespace nyvux;

HearthstoneApiAuth& HearthstoneApiAuth::GetInstance()
{
    static HearthstoneApiAuth Instance;
    return Instance;
}

const AccessToken HearthstoneApiAuth::GetAccessToken()
{
	if (bHasToken)
		return Token;

	using namespace std;

	const string Id = EnvironmentVariableReader::GetEnv(string(HearthstoneApi::ENV_ID));
	const string Secret = EnvironmentVariableReader::GetEnv(string(HearthstoneApi::ENV_SECRET));
	string AuthContent = Id;
	AuthContent.append(":");
	AuthContent.append(Secret);

	auto const Data = "grant_type=client_credentials";

	auto EncodedSize = boost::beast::detail::base64::encoded_size(AuthContent.size());
	string EncodedAuth{};
	EncodedAuth.resize(EncodedSize);
	boost::beast::detail::base64::encode(&EncodedAuth[0], &AuthContent[0], AuthContent.size());

	auto RequestBuilder = RequestBuilder::CreateRequestBuilder()
		.Url(string(HearthstoneApi::OAUTH_URL_HOST) + string(HearthstoneApi::OAUTH_TARGET_TOKEN))
		.Authentification("Basic " + EncodedAuth)
		.Data(Data)
		.Method(EMethod::POST)
		.PutHeader("Content-Type", "application/x-www-form-urlencoded");

	ApiConnection& Connection = ApiConnection::GetInstance();
	string Response = Connection.SendRequest(RequestBuilder.Build());

	auto Json = boost::json::parse(Response).as_object();

	if(auto value = Json[KEY_ACCESS_TOKEN].if_string())
		Token.Token = *value;
	if (auto value = Json[KEY_TOKEN_TYPE].if_string())
		Token.Type = *value;
	if (auto value = Json[KEY_EXPIRES_IN].if_int64())
		Token.ExpiresIn = static_cast<int>(*value);
	if (auto value = Json[KEY_SCOPE].if_string())
		Token.Scope = *value;

	bHasToken = true;

	return Token;
}

HearthstoneApiAuth::HearthstoneApiAuth() : bHasToken(false)
{
}

HearthstoneApiAuth::~HearthstoneApiAuth()
{
}
