/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#pragma once

#include <boost/array.hpp>
#include <array>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <boost/iostreams/stream.hpp>
#include <boost/serialization/vector.hpp>
#include <sstream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/iostreams/device/back_inserter.hpp>


#include "../../utils/Message.hpp"

using boost::asio::ip::udp;

class Client
{
  public:
    Client(
      boost::asio::io_service& io_service,
      const std::string& host,
      const std::string& port
    ) : _ioService(io_service), _socket(io_service, udp::endpoint(udp::v4(), 0)) {
      udp::resolver resolver(_ioService);
      udp::resolver::query query(udp::v4(), host, port);
      udp::resolver::iterator iter = resolver.resolve(query);

      _endpoint = *iter;
      listen();
    }

    ~Client();

    // void send(message msg);
    // void send(message::request request, int value = 0);
    void send(const std::string &message);
    void sendMessage(message::request request, int value = 0);

        private :
        /**
         * @brief Get data from stream
         * @return message
         */
        message getStreamData();

    void listen();
    void handleListen(const boost::system::error_code &error, std::size_t /*bytes_transferred*/);
    void handleSend(const boost::system::error_code &error, std::size_t /*bytes_transferred*/);

    boost::asio::io_service &_ioService;
    udp::socket _socket;
    udp::endpoint _endpoint;
    std::array<char, 64> _recvBuffer;
    //   boost::array<char, 64> _recvBuffer;
};
