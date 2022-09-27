/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** client
*/

#include "client.hpp"

UDPClient::~UDPClient()
{
  _socket.close();
}

void UDPClient::send(const std::string& msg) {
  _socket.send_to(boost::asio::buffer(msg, msg.size()), _endpoint);
}

void UDPClient::start_receive()
{
  std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recv_buffer), _endpoint,
      boost::bind(&UDPClient::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void UDPClient::handle_receive(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
{
  std::cout << "handle receive" << std::endl;
  if (!error || error == boost::asio::error::message_size)
  {
    std::cout << "server have receive : " << _recv_buffer.data() << std::endl;
    _recv_buffer.assign(0);
    start_receive();
  }
}
