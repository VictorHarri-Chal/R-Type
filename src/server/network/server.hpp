/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** server
*/

#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>

#include "../../utils/Message.hpp"
#include "HandleCommand.hpp"
#include "SafeQueue.hpp"

using boost::asio::ip::udp;

class Server
{
  public:
    Server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port) {
      start_receive();
  }
    void handle_send(const boost::system::error_code& /*error*/,
        std::size_t /*bytes_transferred*/);

    udp::socket _socket;
    udp::endpoint _remote_endpoint;
    boost::array<char, 64> _recv_buffer;
    int _port;
    SafeQueue<message> _queue;
    std::vector<int> _rooms;

  private:
    void start_receive();
    void handle_receive(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/);


};
