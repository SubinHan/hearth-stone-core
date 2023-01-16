#pragma once

#include <string>
#include <memory>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include "RequestBuilder.h"

namespace nyvux
{
	class ApiConnection
	{
	public:
		ApiConnection(const ApiConnection& Copy) = delete;
		ApiConnection& operator=(const ApiConnection& Rhs) = delete;

		static RequestBuilder CreateRequestBuilder();
		static std::string SendRequest(RequestBuilder Request);

	private:
		static std::string SendHttpsRequest(RequestBuilder Request);
		static std::string SendHttpRequest(RequestBuilder Request);
		static boost::beast::http::request<boost::beast::http::string_body> 
			MakeRequest(RequestBuilder Request);
	};

	

}

