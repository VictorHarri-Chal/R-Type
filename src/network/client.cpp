#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

using boost::asio::ip::udp;

class UDPClient
{
public:
	UDPClient(
		boost::asio::io_service& io_service, 
		const std::string& host, 
		const std::string& port
	) : io_service_(io_service), socket_(io_service, udp::endpoint(udp::v4(), 0)) {
		udp::resolver resolver(io_service_);
		udp::resolver::query query(udp::v4(), host, port);
		udp::resolver::iterator iter = resolver.resolve(query);
		endpoint_ = *iter;
    start_receive();
	}

	~UDPClient()
	{
		socket_.close();
	}

	void send(const std::string& msg) {
		socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
	}

  private:
	boost::asio::io_service& io_service_;
	udp::socket socket_;
	udp::endpoint endpoint_;
  boost::array<char, 64> recv_buffer_;
  
  void start_receive()
  {
    std::cout << "start receive" << std::endl;
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_), endpoint_,
        boost::bind(&UDPClient::handle_receive, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred));
  }

  void handle_receive(const boost::system::error_code& error,
      std::size_t /*bytes_transferred*/)
  {
    std::cout << "handle receive" << std::endl;
    if (!error || error == boost::asio::error::message_size)
    {
      std::cout << "server have receive : " << recv_buffer_.data() << std::endl;
      recv_buffer_.assign(0);
      start_receive();
    }
  }

};

int main()
{
	boost::asio::io_service io_service;
	UDPClient client(io_service, "localhost", "4242");
  std::string message;

  while (message != "quit") {
    message.clear();
    std::cout << "message = ";
	  std::getline(std::cin >> std::ws, message);
    client.send(message);
    io_service.run_one();
  }
  
}