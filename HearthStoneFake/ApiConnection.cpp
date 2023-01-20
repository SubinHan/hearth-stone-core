#include "ApiConnection.h"

#include <iostream>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

using namespace nyvux;
using namespace boost::asio;
using namespace boost::beast;

namespace nyvux
{
	http::request<http::string_body> MakeRequest(Request Request)
	{
		std::string UrlHost = Request.Host;
		UrlHost += ":";
		UrlHost += Request.Port;

		int Version = 11;

		std::stringstream Target;

		Target << Request.Path;
		if (!Request.QueryStrings.empty())
		{
			Target << "?";
			auto Iter = Request.QueryStrings.begin();
			Target << Iter->first << "=" << Iter->second;
			Iter++;
			for (; Iter != Request.QueryStrings.end(); Iter++)
			{
				Target << "&";
				Target << Iter->first << "=" << Iter->second;
			}
		}

		http::request<http::string_body> Req
		{
		Request.Method == EMethod::GET ? http::verb::get : http::verb::post,
		Target.view(),
		Version
		};
		Req.set(http::field::host, UrlHost);
		Req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		if (!Request.Authentification.empty())
		{
			Req.set(http::field::authorization, Request.Authentification);
		}

		for (auto& [Key, Value] : Request.Headers)
		{
			Req.set(Key, Value);
		}

		if (!Request.Data.empty())
		{
			Req.body() = Request.Data;
		}

		Req.prepare_payload();

		return Req;
	}
}

nyvux::ApiConnection::ApiConnection()
{
}

ApiConnection& nyvux::ApiConnection::GetInstance()
{
	static ApiConnection Instance;
	return Instance;
}

std::string ApiConnection::SendHttpsRequest(Request Request)
{
	using namespace boost::asio;
	using namespace boost::beast;

	SocketPool& SocketPool = SocketPool::GetInstance();
	ssl::stream<ip::tcp::socket>& Stream = SocketPool.GetSslStream(Request.Host, Request.Port);

	auto Req = MakeRequest(Request);

	http::write(Stream, Req);

	flat_buffer Buffer;
	http::response<http::dynamic_body> Res;
	http::read(Stream, Buffer, Res);

	switch (Res.base().result_int())
	{
	case 301:
		Request.Url = Res.base()["Location"];
		return SendRequest(Request);
	}

	return buffers_to_string(Res.body().data());
}

std::string ApiConnection::SendHttpRequest(Request Request)
{
	using namespace boost::asio;
	using namespace boost::beast;

	SocketPool& SocketPool = SocketPool::GetInstance();
	auto& Stream = SocketPool.GetTcpStream(Request.Host, Request.Port);

	auto Req = MakeRequest(Request);

	http::write(Stream, Req);

	flat_buffer Buffer;
	http::response<http::dynamic_body> Res;
	http::read(Stream, Buffer, Res);

	switch (Res.base().result_int())
	{
	case 301:
		Request.Url = Res.base()["Location"];
		return SendRequest(Request);
	}

	return buffers_to_string(Res.body().data());
}

std::string ApiConnection::SendRequest(Request Request)
{
	if (Request.IsHttpsRequest())
	{
		return SendHttpsRequest(Request);
	}

	return SendHttpRequest(Request);
}