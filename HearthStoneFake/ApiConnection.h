#pragma once

#include <string>
#include <memory>

namespace nyvux
{
	class RequestBuilder;

	class ApiConnection
	{
	public:
		ApiConnection(const std::string Host, const std::string Port = "80");
		ApiConnection(const ApiConnection& Copy) = delete;
		ApiConnection& operator=(const ApiConnection& Rhs) = delete;
		virtual ~ApiConnection();

		RequestBuilder CreateRequestBuilder();
		std::string SendRequest(RequestBuilder Request);

	private:

	private:
		const std::string Host;
		const std::string Port;
	};

	class RequestBuilder
	{
	public:
		enum class EMethod;
		friend class ApiConnection;

		RequestBuilder();
		RequestBuilder& operator=(const RequestBuilder& Rhs) = delete;

		RequestBuilder& Method(EMethod Method);
		RequestBuilder& Target(std::string Target);
		RequestBuilder& Authentification(std::string Auth);
		RequestBuilder& Data(std::string Data);

		enum class EMethod
		{
			GET,
			POST
		};

	private:
		EMethod RequestMethod;
		std::string RequestTarget;
		std::string RequestAuthentification;
		std::string RequestData;
	};
}

