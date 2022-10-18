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

void Client::send(message msg) {
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);

    std::cout << "Send message to server..." << std::endl;
    msg.print();
    oa << msg;
    _recvBuffer.assign(0);
    _socket.async_send_to(boost::asio::buffer(ss.str()), _endpoint,
        boost::bind(
            &Client::handleSend, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

}

void Client::send(message::request request, int value) {
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    message msg(request, value);

    std::cout << "Send message to server..." << std::endl;
    msg.print();
    oa << msg;
    _recvBuffer.assign(0);
    _socket.async_send_to(boost::asio::buffer(ss.str()), _endpoint,
        boost::bind(
            &Client::handleSend, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

}

    // std::stringstream ss;
    // boost::archive::text_oarchive oa(ss);
    // message test(request, value);
    // oa << test;
    // _socket.send_to(boost::asio::buffer(ss.str()), _endpoint);
void Client::startReceive()
{
  _socket.async_receive_from(
      boost::asio::buffer(_recvBuffer), _endpoint,
      boost::bind(&Client::handleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Client::handleSend(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/)
{
//   (void)error;
}

void Client::handleReceive(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
{
  std::cout << "handle receive" << std::endl;
  if (!error || error == boost::asio::error::message_size)
  {
    //   _recvBuffer.assign(0);
      std::stringstream outfile;
      outfile << _recvBuffer.data();
      boost::archive::text_iarchive oa(outfile);
      message test;
      oa >> test;
      std::cout << "Client received: " << std::endl;
      test.print();

      startReceive();
  }
}
