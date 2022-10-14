/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <iostream>

using boost::asio::ip::udp;

class Client {
  public:
    /**
     * @brief Construct a new Client object
     * 
     * @param io_service IO Service
     * @param host Host for client
     * @param port Port for client
     */
    Client(boost::asio::io_service &io_service, const std::string &host, const std::string &port)
        : _io_service(io_service), _socket(io_service, udp::endpoint(udp::v4(), 0))
    {
        udp::resolver resolver(_io_service);
        udp::resolver::query query(udp::v4(), host, port);
        udp::resolver::iterator iter = resolver.resolve(query);
        _endpoint = *iter;
        start_receive();
    }
    /**
     * @brief Destroy the Client object
     * 
     */
    ~Client();
    /**
     * @brief Send a message to the server
     * 
     * @param msg Message to be sent
     */
    void send(const std::string &msg);

  private:
    /**
     * @brief IO Service
     * 
     */
    boost::asio::io_service &_io_service;
    /**
     * @brief Socket
     * 
     */
    udp::socket _socket;
    /**
     * @brief Endpoint
     * 
     */
    udp::endpoint _endpoint;
    /**
     * @brief Buffer for receiving
     * 
     */
    boost::array<char, 64> _recv_buffer;
    /**
     * @brief Start receiving
     * 
     */
    void start_receive();
    /**
     * @brief Handle receiving
     * 
     * @param error Error
     * @param bytes_transferred Bytes transferred
     */
    void handle_receive(const boost::system::error_code &error, std::size_t /*bytes_transferred*/);
};

#endif /* !CLIENT_HPP_ */
