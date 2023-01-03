#include <iostream>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace std;

int main()
{
	boost::asio::io_context ioc;
	boost::asio::ip::tcp::resolver resolver(ioc);
	boost::beast::tcp_stream stream(ioc);

	try
	{
		auto const host = "jsonplaceholder.typicode.com";
		auto const port = "80";
		auto const target = "/posts/1";
		bool isVer1_0 = false;
		int version = isVer1_0 ? 10 : 11;

		auto const results = resolver.resolve(host, port);
		stream.connect(results);


		string urlHost = host;
		urlHost += ":";
		urlHost += port;

		boost::beast::http::request<boost::beast::http::string_body> req{ boost::beast::http::verb::get, target, version };
		req.set(boost::beast::http::field::host, urlHost);
		req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		boost::beast::http::write(stream, req);

		boost::beast::flat_buffer buffer;

		boost::beast::http::response<boost::beast::http::dynamic_body> res;

		boost::beast::http::read(stream, buffer, res);

		string json = boost::beast::buffers_to_string(res.body().data());
		cout << json << endl;

		boost::beast::error_code ec;
		stream.socket().shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

		if (ec && ec != boost::beast::errc::not_connected)
		{
			clog << "error: " << ec.message() << endl;
			return -1;
		}
	}
	catch (std::exception const& ex) {
		clog << "exception: " << ex.what() << endl;

		return -1;
	}

	return 0;
}