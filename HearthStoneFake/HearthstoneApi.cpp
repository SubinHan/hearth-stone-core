#include "HearthstoneApi.h"

#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>

using namespace std;

const vector<string> HearthstoneApi::GetAllCardList()
{
	boost::asio::io_context Context;
	boost::asio::ip::tcp::resolver Resolver(Context);
	boost::beast::tcp_stream Stream(Context);

	try
	{
		auto const Host = "us.api.blizzard.com";
		auto const Port = "80";
		auto const Target = "/hearthstone/cards";
		bool bIsVer10 = false;
		int Version = bIsVer10 ? 10 : 11;

		auto const Results = Resolver.resolve(Host, Port);
		Stream.connect(Results);

		string UrlHost = Host;
		UrlHost += ":";
		UrlHost += Port;

		boost::beast::http::request<boost::beast::http::string_body> Req{ boost::beast::http::verb::get, Target, Version };
		Req.set(boost::beast::http::field::host, UrlHost);
		Req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		boost::beast::http::write(Stream, Req);

		boost::beast::flat_buffer Buffer;

		boost::beast::http::response<boost::beast::http::dynamic_body> Res;

		boost::beast::http::read(Stream, Buffer, Res);

		string Json = boost::beast::buffers_to_string(Res.body().data());
		cout << Json << endl;

		boost::beast::error_code ErrorCode;
		Stream.socket().shutdown(boost::asio::ip::tcp::socket::shutdown_both, ErrorCode);

		if (ErrorCode && ErrorCode != boost::beast::errc::not_connected)
		{
			clog << "error: " << ErrorCode.message() << endl;
			return vector<string>();
		}
	}
	catch (std::exception const& ex) {
		clog << "exception: " << ex.what() << endl;

		return vector<string>();
	}

	return vector<string>();
}

const std::string HearthstoneApi::GetEnv(std::string Key)
{
	return getenv(Key.c_str());
}
