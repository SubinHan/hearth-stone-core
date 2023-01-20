#pragma once

#include <string>
#include <memory>
#include <map>

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

		ApiConnection();

		static ApiConnection& GetInstance();

		std::string SendRequest(Request Request);

	public:
		
	private:
		std::string SendHttpsRequest(Request Request);
		std::string SendHttpRequest(Request Request);

	private:
	};

	

}

