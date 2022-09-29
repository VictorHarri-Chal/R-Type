/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

Client::~Client()
{
  _socket.close();
}

void Client::send(const std::string& msg) {
  _socket.send_to(boost::asio::buffer(msg, msg.size()), _endpoint);
}

void Client::start_receive()
{
  std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recv_buffer), _endpoint,
      boost::bind(&Client::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Client::handle_receive(const boost::system::error_code& error,
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
