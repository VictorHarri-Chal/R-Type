/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "server.hpp"

using boost::asio::ip::udp;

// TODO: Add class constructor here

void Server::start_receive()
{
  std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recv_buffer), _remote_endpoint,
      boost::bind(&Server::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Server::handle_receive(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
  {
    std::cout << "handle receive" << std::endl;
    if (!error || error == boost::asio::error::message_size)
    {
      std::cout << "new message from client : " << _recv_buffer.data() << std::endl;
      boost::shared_ptr<std::string> message(
          new std::string(_recv_buffer.data()));

      _socket.async_send_to(boost::asio::buffer(*message), _remote_endpoint,
          boost::bind(&Server::handle_send, this, message,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
      _recv_buffer.assign(0);
      start_receive();
    }
}

void Server::handle_send(boost::shared_ptr<std::string> /*message*/,
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{
}
