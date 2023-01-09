#include "ApiConnection.h"

#include <iostream>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

using namespace nyvux;

ApiConnection::ApiConnection(const std::string Host, const std::string Port) : 
	Host(Host), 
	Port(Port)
{
}

ApiConnection::~ApiConnection()
{
}

RequestBuilder ApiConnection::CreateRequestBuilder()
{
	return RequestBuilder();
}

std::string ApiConnection::SendRequest(RequestBuilder Request)
{
	boost::asio::io_context Context;
	boost::asio::ip::tcp::resolver Resolver(Context);
	auto Stream = boost::beast::tcp_stream(Context);
	auto const Results = Resolver.resolve(Host, Port);
	Stream.connect(Results);

	std::string UrlHost = Host;
	UrlHost += ":";
	UrlHost += Port;
	
	int Version = 11;

	using namespace boost::beast;

	http::request<http::string_body> Req{ http::verb::get, Request.RequestTarget, Version };
	Req.set(http::field::host, UrlHost);
	Req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
	
	if (!Request.RequestAuthentification.empty())
	{
		Req.set(http::field::authorization, Request.RequestAuthentification);
	}

	if (!Request.RequestData.empty())
	{
		auto Body = Req.body();
		Body.append(Request.RequestData);
	}

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

	return buffers_to_string(Res.body().data());
}

RequestBuilder::RequestBuilder() : 
	RequestMethod(EMethod::GET),
	RequestTarget("/"), 
	RequestAuthentification(), 
	RequestData()
{
}

RequestBuilder& nyvux::RequestBuilder::Method(EMethod Method)
{
	RequestMethod = Method;
	return *this;
}

RequestBuilder& RequestBuilder::Target(std::string Target)
{
	if (Target[0] != '/')
		Target = "/" + Target;

	RequestTarget = Target;
	return *this;
}

RequestBuilder& RequestBuilder::Authentification(std::string Auth)
{
	RequestAuthentification = Auth;
	return *this;
}

RequestBuilder& RequestBuilder::Data(std::string Data)
{
	RequestData = Data;
	return *this;
}
