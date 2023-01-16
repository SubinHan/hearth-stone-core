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


RequestBuilder ApiConnection::CreateRequestBuilder()
{
	return RequestBuilder();
}

std::string ApiConnection::SendHttpsRequest(RequestBuilder Request)
{
	using namespace boost::asio;
	using namespace boost::beast;

	// The SSL context is required, and holds certificates
	ssl::context ctx{ ssl::context::sslv23_client };

	boost::asio::io_context Context;
	ssl::stream<ip::tcp::socket> Stream{ Context, ctx };
	boost::beast::tcp_stream Stream2(Context);

	boost::asio::ip::tcp::resolver Resolver(Context);
	auto const Results = Resolver.resolve(Request.RequestHost, Request.RequestPort);

	// Make the connection on the IP address we get from a lookup
	boost::asio::connect(Stream.next_layer(), Results.begin(), Results.end());
	Stream.handshake(ssl::stream_base::client);

	auto Req = MakeRequest(Request);

	http::write(Stream, Req);

	flat_buffer Buffer;
	http::response<http::dynamic_body> Res;
	http::read(Stream, Buffer, Res);

	boost::beast::error_code ec;
	Stream.shutdown(ec);

	if (ec && ec != boost::beast::errc::not_connected)
	{
		std::clog << "error: " << ec.message() << std::endl;
	}

	switch (Res.base().result_int())
	{
	case 301:
		return SendRequest(Request.Url(Res.base()["Location"]));
	}

	return buffers_to_string(Res.body().data());
}

std::string ApiConnection::SendHttpRequest(RequestBuilder Request)
{
	using namespace boost::asio;
	using namespace boost::beast;

	io_context Context;
	tcp_stream Stream{ Context };

	ip::tcp::resolver Resolver(Context);
	auto const Results = Resolver.resolve(Request.RequestHost, Request.RequestPort);
	Stream.connect(Results);

	auto Req = MakeRequest(Request);

	http::write(Stream, Req);

	flat_buffer Buffer;
	http::response<http::dynamic_body> Res;
	http::read(Stream, Buffer, Res);

	boost::beast::error_code ec;
	Stream.socket().shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

	if (ec && ec != boost::beast::errc::not_connected)
	{
		std::clog << "error: " << ec.message() << std::endl;
	}

	switch (Res.base().result_int())
	{
	case 301:
		return SendRequest(Request.Url(Res.base()["Location"]));
	}


	return buffers_to_string(Res.body().data());
}

http::request<http::string_body> ApiConnection::MakeRequest(RequestBuilder Request)
{
	std::string UrlHost = Request.RequestHost;
	UrlHost += ":";
	UrlHost += Request.RequestPort;

	int Version = 11;

	http::request<http::string_body> Req
	{
	Request.RequestMethod == RequestBuilder::EMethod::GET ? http::verb::get : http::verb::post,
	std::string(Request.RequestPath) + std::string(Request.RequestQueryString),
	Version
	};
	Req.set(http::field::host, UrlHost);
	Req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	if (!Request.RequestAuthentification.empty())
	{
		Req.set(http::field::authorization, Request.RequestAuthentification);
	}

	for (auto &[Key, Value] : Request.RequestHeaders)
	{
		Req.set(Key, Value);
	}

	if (!Request.RequestData.empty())
	{
		Req.body() = Request.RequestData;
	}

	Req.prepare_payload();

	return Req;
}

std::string ApiConnection::SendRequest(RequestBuilder Request)
{
	if (Request.IsHttpsRequest())
	{
		return SendHttpsRequest(Request);
	}

	return SendHttpRequest(Request);
}