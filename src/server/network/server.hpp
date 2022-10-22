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

#include "SafeQueue.hpp"
#include "../../utils/Message.hpp"

using boost::asio::ip::udp;

/**
 * @brief Server class
 * 
 */
class Server {
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
    /**
     * @brief Start receiving
     * 
     */
    void start_receive();
    /**
     * @brief Handle receive
     * 
     * @param error Error
     * @param bytes_transferred Bytes transferred
     */
    void handle_receive(const boost::system::error_code &error, std::size_t /*bytes_transferred*/);
    /**
     * @brief Handle send
     * 
     * @param error Error
     * @param bytes_transferred Bytes transferred
     */
    void handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code & /*error*/,
        std::size_t /*bytes_transferred*/);
    /**
     * @brief Socket
     * 
     */
    udp::socket _socket;
    /**
     * @brief Endpoint
     * 
     */
    udp::endpoint _remote_endpoint;
    /**
     * @brief Buffer for data
     * 
     */
    boost::array<char, 64> _recv_buffer;
    /**
     * @brief Port
     * 
     */
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
