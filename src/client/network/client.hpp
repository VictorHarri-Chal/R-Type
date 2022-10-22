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
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include "../../utils/Message.hpp"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>

using boost::asio::ip::udp;

/**
 * @brief Client class
 * 
 */
class Client {
  public:
    Client(
      boost::asio::io_service& io_service,
      const std::string& host,
      const std::string& port
    ) : _io_service(io_service), _socket(io_service, udp::endpoint(udp::v4(), 0)) {
      udp::resolver resolver(_io_service);
      udp::resolver::query query(udp::v4(), host, port);
      udp::resolver::iterator iter = resolver.resolve(query);
      _endpoint = *iter;
      _actualNbRooms = 0;
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

    void send();
    void send(message::request request, int value = 0);

    size_t getNbRoom() const;

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
    size_t _actualNbRooms;
};

#endif /* !CLIENT_HPP_ */
