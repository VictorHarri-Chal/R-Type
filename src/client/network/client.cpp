/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#include "client.hpp"

Client::~Client()
{
  _socket.close();
}

static inline boost::asio::const_buffers_1 cryptMessage(message command)
{
    boost::asio::streambuf b;
    std::ostream os(&b);
  
    boost::archive::binary_oarchive binary_input_archive(b);
    binary_input_archive & BOOST_SERIALIZATION_NVP(command);
    return (b.data());
}

void Client::send(const std::string& msg) {
    message test(message::CREATE, "hello world");
    boost::asio::const_buffers_1 command = cryptMessage(test);
    (void)msg;

  _socket.send_to(boost::asio::buffer(command, command.size()), _endpoint);
  test.print();
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

void Client::handle_send(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/)
{
  (void)error;
}

void Client::handle_receive(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
{
  std::cout << "handle receive" << std::endl;
  if (!error || error == boost::asio::error::message_size)
  {
      // _socket.async_send_to(boost::asio::buffer(command.data(), command.size()), _endpoint,
      //     boost::bind(&Client::handle_send, this,
      //       boost::asio::placeholders::error,
      //       boost::asio::placeholders::bytes_transferred));
      // _recv_buffer.assign(0);
      // test.print();
    start_receive();
  }
}