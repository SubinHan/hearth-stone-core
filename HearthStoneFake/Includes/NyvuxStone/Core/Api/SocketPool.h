#pragma once

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast/core/tcp_stream.hpp>

#include <map>

namespace nyvux
{
	class SocketPool
	{
	public:
		SocketPool(const SocketPool& Ref) = delete;
		SocketPool& operator=(const SocketPool& Ref) = delete;

		SocketPool();
		~SocketPool();

		static SocketPool& GetInstance();

		boost::asio::ssl::stream<boost::asio::ip::tcp::socket>&
			GetSslStream(std::string Host, std::string Port);
		boost::beast::tcp_stream& GetTcpStream(std::string Host, std::string Port);

	private:
		std::unique_ptr<boost::asio::ssl::context> SslContext;
		std::unique_ptr<boost::asio::io_context> IoContext;

		std::map<std::pair<std::string, std::string>, boost::asio::ssl::stream<boost::asio::ip::tcp::socket>>
			SslStreams;
		std::map<std::pair<std::string, std::string>, boost::beast::tcp_stream>
			TcpStreams;
	};
}
