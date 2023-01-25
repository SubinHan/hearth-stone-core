
#include "Request.h"

#include <boost/regex.hpp>


using namespace nyvux;

bool Request::IsHttpsRequest()
{
	return Port == RequestBuilder::PORT_HTTPS;
}

RequestBuilder::RequestBuilder() : Request()
{
	Request.Method = EMethod::GET;
	Request.Port = PORT_HTTPS;
}

RequestBuilder RequestBuilder::CreateRequestBuilder()
{
	return RequestBuilder();
}

RequestBuilder& nyvux::RequestBuilder::Method(EMethod Method)
{
	Request.Method = Method;
	return *this;
}

RequestBuilder& RequestBuilder::Url(std::string Url)
{
	Request.Url = Url;

	Uri Uri = Uri::Parse(Request.Url);

	ParseIfUriContainsQueryStrings(Uri);

	Request.Path = Uri.Path;
	Request.Protocol = Uri.Protocol;
	Request.Host = Uri.Host;

	if (Request.Port.empty())
	{
		Request.Port = Uri.Port;
	}

	if (Request.Port.empty())
	{
		Request.Port = PORT_HTTPS;
	}

	return *this;
}

RequestBuilder& RequestBuilder::Authentification(std::string Auth)
{
	Request.Authentification = Auth;
	return *this;
}

RequestBuilder& RequestBuilder::Data(std::string Data)
{
	Request.Data = Data;
	return *this;
}

RequestBuilder& nyvux::RequestBuilder::Port(const unsigned int Port)
{
	if (Port > 65535)
		Request.Port = std::string(PORT_HTTPS);

	Request.Port = std::to_string(Port);

	return *this;
}

RequestBuilder& nyvux::RequestBuilder::PutHeader(std::string Key, std::string Value)
{
	Request.Headers.insert({ Key, Value });

	return *this;
}

RequestBuilder& nyvux::RequestBuilder::PutQueryString(std::string Key, std::string Value)
{
	Request.QueryStrings.insert({ Key, Value });

	return *this;
}

Request nyvux::RequestBuilder::Build()
{
	return Request;
}

void RequestBuilder::ParseIfUriContainsQueryStrings(Uri Uri)
{
	auto RequestQueryString = Uri.QueryString;
	auto QueryPairStart = RequestQueryString.begin();
	while (QueryPairStart != RequestQueryString.end())
	{
		QueryPairStart++;
		auto QueryPairMiddle = std::find(QueryPairStart, RequestQueryString.end(), '=');

		auto Key = std::string(QueryPairStart, QueryPairMiddle);
		QueryPairMiddle++;
		QueryPairStart = std::find(QueryPairMiddle, RequestQueryString.end(), '&');
		auto Value = std::string(QueryPairMiddle, QueryPairStart);

		Request.QueryStrings.insert({ Key, Value });
	}
}

Uri nyvux::Uri::Parse(const std::string& uri)
{
	Uri result;

	typedef std::string::const_iterator iterator_t;

	if (uri.length() == 0)
		return result;

	iterator_t uriEnd = uri.end();

	// get query start
	iterator_t queryStart = std::find(uri.begin(), uriEnd, '?');

	// protocol
	iterator_t protocolStart = uri.begin();
	iterator_t protocolEnd = std::find(protocolStart, uriEnd, ':');            //"://");

	if (protocolEnd != uriEnd)
	{
		std::string prot = &*(protocolEnd);
		if ((prot.length() > 3) && (prot.substr(0, 3) == "://"))
		{
			result.Protocol = std::string(protocolStart, protocolEnd);
			protocolEnd += 3;   //      ://
		}
		else
			protocolEnd = uri.begin();  // no protocol
	}
	else
		protocolEnd = uri.begin();  // no protocol

	// host
	iterator_t hostStart = protocolEnd;
	iterator_t pathStart = std::find(hostStart, uriEnd, '/');  // get pathStart

	iterator_t hostEnd = std::find(protocolEnd,
		(pathStart != uriEnd) ? pathStart : queryStart,
		':');  // check for port

	result.Host = std::string(hostStart, hostEnd);

	// port
	if ((hostEnd != uriEnd) && ((&*(hostEnd))[0] == ':'))  // we have a port
	{
		hostEnd++;
		iterator_t portEnd = (pathStart != uriEnd) ? pathStart : queryStart;
		result.Port = std::string(hostEnd, portEnd);
	}

	// path
	if (pathStart != uriEnd)
		result.Path = std::string(pathStart, queryStart);

	// query
	if (queryStart != uriEnd)
		result.QueryString = std::string(queryStart, uri.end());

	return result;

}   // Parse
