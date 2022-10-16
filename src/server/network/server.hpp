/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
/*include fstream for file I/O*/
#include <fstream>

// // /*include binary_oarchive.hpp for binary_oacrhive*/
// #include <boost/archive/binary_oarchive.hpp>

// // /*include binary_iarchive.hpp for binary_iacrhive*/
// #include <boost/archive/binary_iarchive.hpp>

#include "SafeQueue.hpp"
#include "HandleCommand.hpp"

using boost::asio::ip::udp;

class Server
{
  public:
    Server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port) {
      start_receive();
  }

  private:
    void start_receive();
    void handle_receive(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/);

    void handle_send(boost::shared_ptr<std::string> /*message*/,
        const boost::system::error_code& /*error*/,
        std::size_t /*bytes_transferred*/);

    udp::socket _socket;
    udp::endpoint _remote_endpoint;
    boost::array<char, 64> _recv_buffer;
    int _port;
    SafeQueue<message> _queue;
};


#endif /* !SERVER_HPP_ */
