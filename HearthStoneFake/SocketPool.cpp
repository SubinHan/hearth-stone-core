#include "SocketPool.h"

#include <iostream>

using namespace nyvux;
using namespace std;
using namespace boost::asio;
using namespace boost::beast;

nyvux::SocketPool::SocketPool() :
	SslContext(make_unique<ssl::context>(ssl::context::sslv23_client)),
	IoContext(make_unique<io_context>()),
	SslStreams(),
	TcpStreams()
{
	for (auto& Each : SslStreams)
	{
		boost::beast::error_code ec;
		Each.second.shutdown(ec);

		if (ec && ec != boost::beast::errc::not_connected)
		{
			std::clog << "error: " << ec.message() << std::endl;
		}
	}

	for (auto& Each : TcpStreams)
	{
		boost::beast::error_code ec;
		Each.second.socket().shutdown(ip::tcp::socket::shutdown_both, ec);

		if (ec && ec != boost::beast::errc::not_connected)
		{
			std::clog << "error: " << ec.message() << std::endl;
		}
	}
}

nyvux::SocketPool::~SocketPool()
{
}

SocketPool& nyvux::SocketPool::GetInstance()
{
	static SocketPool Instance{};
	return Instance;
}

ssl::stream<ip::tcp::socket>& nyvux::SocketPool::GetSslStream(std::string Host, std::string Port)
{
	const auto Index = make_pair(Host, Port);

	if (SslStreams.contains(Index))
		return SslStreams.find(Index)->second;;

	SslStreams.try_emplace(Index, *IoContext.get(), *SslContext.get());

	auto& Stream = SslStreams.find(Index)->second;

	ip::tcp::resolver Resolver(*IoContext.get());
	auto const Results = Resolver.resolve(Host, Port);
	connect(Stream.next_layer(), Results.begin(), Results.end());
	Stream.handshake(ssl::stream_base::client);

	return Stream;
}

tcp_stream& nyvux::SocketPool::GetTcpStream(std::string Host, std::string Port)
{
	const auto Index = make_pair(Host, Port);

	if (TcpStreams.contains(Index))
		return TcpStreams.find(Index)->second;

	TcpStreams.try_emplace(Index, *IoContext.get());

	auto& Stream = TcpStreams.find(Index)->second;

	ip::tcp::resolver Resolver(*IoContext.get());
	auto const Results = Resolver.resolve(Host, Port);
	Stream.connect(Results);

	return Stream;
}
