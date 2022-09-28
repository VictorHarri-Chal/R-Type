/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using boost::asio::ip::udp;

class udp_server
{
  public:
    udp_server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port) {
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
};


#endif /* !SERVER_HPP_ */
