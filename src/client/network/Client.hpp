/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind/bind.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <iostream>
#include "../../utils/Message.hpp"

using boost::asio::ip::udp;

/**
 * @brief Client class
 *
 */
class Client {
  public:
    /**
     * @brief Construct a new Client object
     *
     * @param ioService
     * @param host
     * @param port
     */
    Client(boost::asio::io_service& ioService,const std::string& host, const std::string& port);
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
    void send(message::request request, std::string string, int value = 0);
    /**
     * @brief Get the Stream Data object
     *
     * @param bytesTransferred
     * @return message
     */
    message getStreamData(std::size_t bytesTransferred);
    /**
     * @brief Get the Nb Room object
     *
     * @return size_t
     */
    size_t getNbRoom() const;
    /**
     * @brief Get the Nb People In Room object
     *
     * @return size_t
     */
    size_t getNbPeopleInRoom() const;
    /**
     * @brief Get if the Game Start
     *
     * @return true
     * @return false
     */
    bool getGameStart() const;

  private:
    /**
     * @brief IO Service
     *
     */
    boost::asio::io_service &_ioService;
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
    std::array<char, 64> _recvBuffer;
    /**
     * @brief Start receiving
     *
     */
    void listen();
    /**
     * @brief Handle receiving
     *
     * @param error Error
     * @param bytes_transferred Bytes transferred
     */
    void handleReceive(const boost::system::error_code &error, std::size_t bytes_transferred);
    /**
     * @brief Create a Paquet object
     *
     * @param request
     * @param value
     * @return std::string
     */
    std::string createPaquet(message::request request, int value, std::string string);
    /**
     * @brief number of room create
     *
     */
    size_t _actualNbRooms;
    /**
     * @brief number of people who have join same room user
     *
     */
    size_t _actualNbPeopleInRoom;
    /**
     * @brief if the game start or not
     *
     */
    bool _gameStart;
};
