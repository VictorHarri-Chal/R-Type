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
            _nbRooms = 0;
            std::cout << "Start receiving..." << std::endl;
            listen();
        }

        /**
         * @brief Send message to clients
         * @param message
         */
        void send(message msg);
        void send(message::request req, int value);

        size_t getnbRoom() const;
        void setnbRoom(size_t nbRooms);
        boost::array<char, 64> getBuffer() const;

      private:
        /**
        * @brief Listen to clients
        */
        void listen();

        /**
        * @brief Get data from stream
        * @return message
        */
        message getStreamData();

        /**
        * @brief Handle data sent from the clients to the server
        * @param error
        * @param bytes_transferred
        */
        void handleListen(const boost::system::error_code& error,
            std::size_t /*bytes_transferred*/);

        /**
        * @brief Handle data sent from the server to the clients
        * @param error
        * @param bytes_transferred
        */
        void handleSend(const boost::system::error_code& /*error*/,
            std::size_t /*bytes_transferred*/);

        udp::socket _socket;
        int _port;
        udp::endpoint _remoteEndpoint;
        boost::array<char, 64> _recvBuffer;
        SafeQueue<message> _queue;
        size_t _nbRooms;
};

/*
** HandleCommand
*/
class HandleCommand {
  private:
    std::vector<std::function<void(int, Server*)>> _allCommand;

  public:
    HandleCommand();
    ~HandleCommand() = default;
    void findCmd(Server *server);
};