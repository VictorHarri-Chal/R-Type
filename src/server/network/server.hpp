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
#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>

using boost::asio::ip::udp;

/**
 * @brief Server class
 * 
 */
class Server {
  public:
    /**
     * @brief Construct a new Server object
     * 
     * @param io_service IO Service
     * @param port Port for server
     */
    Server(boost::asio::io_service &io_service, int port)
        : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port)
    {
        start_receive();
    }

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
};

#endif /* !SERVER_HPP_ */
