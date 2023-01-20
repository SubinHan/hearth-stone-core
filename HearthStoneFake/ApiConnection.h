#pragma once

#include <string>
#include <memory>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include "Request.h"

namespace nyvux
{
	class ApiConnection
	{
	public:
		ApiConnection(const ApiConnection& Copy) = delete;
		ApiConnection& operator=(const ApiConnection& Rhs) = delete;

		static RequestBuilder CreateRequestBuilder();
		static std::string SendRequest(Request Request);

	public:

	private:
		static std::string SendHttpsRequest(Request Request);
		static std::string SendHttpRequest(Request Request);
		static boost::beast::http::request<boost::beast::http::string_body> 
			MakeRequest(Request Request);

	private:
	};

	

}

