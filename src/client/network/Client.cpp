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

// static inline boost::asio::const_buffers_1 cryptMessage(message command)
// {
//     boost::asio::streambuf b;
//     std::ostream os(&b);

//     boost::archive::binary_oarchive binary_input_archive(b);
//     binary_input_archive & BOOST_SERIALIZATION_NVP(command);
//     return (b.data());
// }

void Client::send(message::request request, int value) {
    std::stringstream os;
    boost::archive::text_oarchive oa(os);
    message test(request, value);
    oa << test;
    _socket.send_to(boost::asio::buffer(os.str()), _endpoint);
}

void Client::start_receive()
{
  std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recvBuffer), _endpoint,
      boost::bind(&Client::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Client::handleSend(const boost::system::error_code& error,
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
    //   _recvBuffer.assign(0);
      std::stringstream outfile;
      outfile << _recvBuffer.data();
      boost::archive::text_iarchive oa(outfile);
      message test;
      oa >> test;
      std::cout << "Client received: " << std::endl;
      test.print();

      start_receive();
  }
}
