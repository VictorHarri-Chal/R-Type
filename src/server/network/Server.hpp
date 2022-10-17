/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
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
    /**
     * @brief Server constructor
     * @param io_service
     * @param port
     */
    Server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port) {
        std::cout << "Start receiving..." << std::endl;
        listen();
    }

    /**
     * @brief Handle data sent from the clients to the server
     * @param error
     * @param bytes_transferred
     */

    void send(message msg);
  private:
    message getStreamData();

    void handleSend(const boost::system::error_code& /*error*/,
        std::size_t /*bytes_transferred*/);
    void listen();
    void handleListen(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/);

    udp::socket _socket;
    int _port;
    udp::endpoint _remoteEndpoint;
    boost::array<char, 64> _recvBuffer;
    SafeQueue<message> _queue;
    std::vector<int> _rooms;
};

class HandleCommand {
  private:
    std::vector<std::function<void(int, Server*)>> _allCommand;

  public:
    HandleCommand();
    ~HandleCommand() = default;
    void findCmd(message command, Server *server);
};
