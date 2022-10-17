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
#include "SafeQueue.hpp"

using boost::asio::ip::udp;

class Server
{
  public:
    Server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port), _nbRooms(0) {
      start_receive();
  }
    void handle_send(const boost::system::error_code& /*error*/,
        std::size_t /*bytes_transferred*/);

    void sendMessage(message::request type, int value = 0);
    boost::array<char, 64> getBuffer() const;
    size_t getnbRoom() const;
    void setnbRoom(size_t nbRooms);

  private:
    void start_receive();
    void handle_receive(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/);
    udp::socket _socket;
    udp::endpoint _remote_endpoint;
    boost::array<char, 64> _recv_buffer;
    int _port;
    SafeQueue<message> _queue;
    size_t _nbRooms;
};

class HandleCommand {
  private:
    std::vector<std::function<void(int, Server*)>> _allCommand;

  public:
    HandleCommand();
    ~HandleCommand() = default;
    void findCmd(Server *server);
};
