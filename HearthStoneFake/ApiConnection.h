#pragma once

#include <string>

namespace nyvux
{
	class ApiConnection
	{
	public:
		ApiConnection(std::string Host);
		ApiConnection(const ApiConnection& copy) = delete;
		ApiConnection& operator=(const ApiConnection& rhs) = delete;
		virtual ~ApiConnection();

		RequestBuilder CreateRequestBuilder();
	};

	class RequestBuilder
	{
		RequestBuilder Target(std::string Target);
		RequestBuilder Authentification(std::string Auth);
		RequestBuilder Data(std::string Data);
		std::string Send();
	};
}

