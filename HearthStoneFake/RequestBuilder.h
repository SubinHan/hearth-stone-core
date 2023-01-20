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

	class RequestBuilder
	{
	public:
		enum class EMethod;
		friend class ApiConnection;

		RequestBuilder();
		RequestBuilder& operator=(const RequestBuilder& Rhs) = delete;

		RequestBuilder& Method(EMethod Method);
		RequestBuilder& Url(std::string Url);
		RequestBuilder& Authentification(std::string Auth);
		RequestBuilder& Data(std::string Data);
		RequestBuilder& Port(const unsigned int Port);
		RequestBuilder& Header(std::string Key, std::string Value);
		RequestBuilder& QueryString(std::string Key, std::string Value);

		bool IsHttpsRequest();

	private:
		void ParseIfUriContainsQueryStrings(Uri Uri);

	public:
		enum class EMethod
		{
			GET,
			POST
		};


	private:
		static constexpr std::string_view PORT_HTTPS = "443";
		static constexpr std::string_view PORT_HTTP = "80";

		EMethod RequestMethod;
		std::string RequestUrl;
		std::string RequestAuthentification;
		std::string RequestData;
		std::string RequestPort;
		std::string RequestPath;
		std::string RequestProtocol;
		std::string RequestHost;
		std::map<std::string, std::string> RequestHeaders;
		std::map<std::string, std::string> RequestQueryStrings;
	};

}
