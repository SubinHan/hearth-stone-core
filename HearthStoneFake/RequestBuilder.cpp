
#include "RequestBuilder.h"

#include <boost/regex.hpp>


using namespace nyvux;

RequestBuilder::RequestBuilder() :
	RequestMethod(EMethod::GET),
	RequestUrl(),
	RequestAuthentification(),
	RequestData(),
	RequestPort(PORT_HTTPS),
	RequestHeaders()
{
}

RequestBuilder& nyvux::RequestBuilder::Method(EMethod Method)
{
	RequestMethod = Method;
	return *this;
}

RequestBuilder& RequestBuilder::Url(std::string Url)
{
	RequestUrl = Url;

	Uri Uri = Uri::Parse(RequestUrl);

	ParseIfUriContainsQueryStrings(Uri);

	RequestPath = Uri.Path;
	RequestProtocol = Uri.Protocol;
	RequestHost = Uri.Host;

	if (RequestPort.empty())
	{
		RequestPort = Uri.Port;
	}

	if (RequestPort.empty())
	{
		RequestPort = PORT_HTTPS;
	}

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

RequestBuilder& nyvux::RequestBuilder::Port(const unsigned int Port)
{
	if (Port > 65535)
		RequestPort = std::string(PORT_HTTPS);

	RequestPort = std::to_string(Port);

	return *this;
}

RequestBuilder& nyvux::RequestBuilder::Header(std::string Key, std::string Value)
{
	RequestHeaders.insert({ Key, Value });

	return *this;
}

RequestBuilder& nyvux::RequestBuilder::QueryString(std::string Key, std::string Value)
{
	RequestQueryStrings.insert({ Key, Value });

	return *this;
}

bool nyvux::RequestBuilder::IsHttpsRequest()
{
	return RequestPort == PORT_HTTPS;
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

		RequestQueryStrings.insert({ Key, Value });
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
