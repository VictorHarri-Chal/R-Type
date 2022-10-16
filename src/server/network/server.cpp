/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "server.hpp"
#include <fstream>
using boost::asio::ip::udp;

// static message decryptMessage(boost::array<char, 64> _recv_buffer)
// {
//     std::cout << _recv_buffer.data() << std::endl;
//     boost::asio::streambuf b;
//     std::ostream os(&b);
//     os << _recv_buffer.data();

//     boost::archive::binary_iarchive binary_input_archive(b);
//     message recv;
//     binary_input_archive & BOOST_SERIALIZATION_NVP(recv);
//     std::cout << "reLecture" << std::endl;
//     recv.print();

//     return (recv);
// }

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
    if (!error || error == boost::asio::error::message_size)
    {
      message test1(message::JOIN, 11);
      HandleCommand commandHandler;
      // decryptMessage(_recv_buffer);

        commandHandler.findCmd(test1);
        std::cout << "Queue size after the push:" << _queue.getSize() << std::endl;
        _queue.pop();
        std::cout << "Queue size after the pop:" << _queue.getSize() << std::endl;

        std::stringstream outfile;
        outfile << _recv_buffer.data();
        boost::archive::text_iarchive oa(outfile);
        message test;
        oa >> test;
        test.print();
        start_receive();

        // boost::shared_ptr<std::string> message(
        //     new std::string("hello world"));

        // _socket.async_send_to(boost::asio::buffer(*message), _remote_endpoint,
        //     boost::bind(&Server::handle_send, this, message,
        //       boost::asio::placeholders::error,
        //       boost::asio::placeholders::bytes_transferred));
        // _recv_buffer.assign(0);
        start_receive();
    }
}

void Server::handle_send(boost::shared_ptr<std::string> /*message*/,
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{
}
