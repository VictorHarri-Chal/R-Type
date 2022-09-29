/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

#include "ClientBuffer.hpp"

using boost::asio::ip::udp;

class UDPClient
{
  public:
    UDPClient(
      boost::asio::io_service& io_service,
      const std::string& host,
      const std::string& port
    ) : _io_service(io_service), _socket(io_service, udp::endpoint(udp::v4(), 0)) {
      udp::resolver resolver(_io_service);
      udp::resolver::query query(udp::v4(), host, port);
      udp::resolver::iterator iter = resolver.resolve(query);
      _endpoint = *iter;
      start_receive();
    }

    ~UDPClient();

    void send(const std::string& msg);

    private:

      // ClientBuffer _buffer;

      boost::asio::io_service& _io_service;
      udp::socket _socket;
      udp::endpoint _endpoint;
      boost::array<char, 64> _recv_buffer;

      void start_receive();
      void handle_receive(const boost::system::error_code& error,
          std::size_t /*bytes_transferred*/);
};

#endif /* !CLIENT_HPP_ */
