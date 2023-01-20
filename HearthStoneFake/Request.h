#pragma once

#include <string>
#include <map>

namespace nyvux
{
	struct Uri
	{
	public:
		std::string QueryString, Path, Protocol, Host, Port;

		static Uri Parse(const std::string& uri);
	};

	enum class EMethod
	{
		GET,
		POST
	};

	struct Request
	{
		EMethod Method;
		std::string Url;
		std::string Authentification;
		std::string Data;
		std::string Port;
		std::string Path;
		std::string Protocol;
		std::string Host;
		std::map<std::string, std::string> Headers;
		std::map<std::string, std::string> QueryStrings;

		bool IsHttpsRequest();
	};

	class RequestBuilder
	{
	public:
		friend class ApiConnection;

		RequestBuilder();
		RequestBuilder& operator=(const RequestBuilder& Rhs) = delete;

		RequestBuilder& Method(EMethod Method);
		RequestBuilder& Url(std::string Url);
		RequestBuilder& Authentification(std::string Auth);
		RequestBuilder& Data(std::string Data);
		RequestBuilder& Port(const unsigned int Port);
		RequestBuilder& PutHeader(std::string Key, std::string Value);
		RequestBuilder& PutQueryString(std::string Key, std::string Value);

		Request Build();

	public:
		static constexpr std::string_view PORT_HTTPS = "443";
		static constexpr std::string_view PORT_HTTP = "80";

	private:
		void ParseIfUriContainsQueryStrings(Uri Uri);

	private:
		Request Request;
	};

}
