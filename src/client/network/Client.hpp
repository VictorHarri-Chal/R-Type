/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include "../../ecs/world.hpp"
#include "../../utils/Message.hpp"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <regex>

using boost::asio::ip::udp;

/**
 * @brief Temporary entities structure
 * 
 */
struct entityTmp
{
    /**
     * @brief Id of the temporary entity
     * 
     */
    size_t id;
    /**
     * @brief Position X of the temporary entity
     * 
     */
    float posX;
    /**
     * @brief Position Y of the temporary entity
     * 
     */
    float posY;
};
/**
 * @brief Vector of entities received from the server
 * 
 */
typedef std::vector<entityTmp> entitiesReceive;

/**
 * @brief Client class
 *
 */
class Client {
  public:
    /**
     * @brief Construct a new Client object
     *
     * @param ioService Boost io_service
     * @param host Host to connect
     * @param port Port to connect
     */
    Client(boost::asio::io_service &ioService, const std::string &host, const std::string &port);
    /**
     * @brief Destroy the Client object
     *
     */
    ~Client();
    /**
     * @brief Send a message to the server
     *
     * @param request Request type
     * @param body Body of the message
     */
    void send(message::request request, std::string body = "");
    /**
     * @brief Get the Stream Data object
     *
     * @param bytesTransferred Bytes transferred
     * @return message Message received
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
     * @return size_t Number of rooms
     */
    size_t getNbPeopleInRoom() const;
    /**
     * @brief Get if the Game Start
     *
     * @return true If the game start
     * @return false If the game doesn't start
     */
    bool getGameStart() const;
    /**
     * @brief Get the current player number
     *
     * @return The number of the player
     */
    std::string getPlayerNumber() const;
    /**
     * @brief Pop entity from the entities list
     * 
     */
    void popEntity();
    /**
     * @brief Get the Entities object
     * 
     * @return entitiesReceive Entities received from the server
     */
    entitiesReceive getEntities() const;
    /**
     * @brief Get the Entities At index
     * 
     * @param pos Index of the entity
     * @return entityTmp The temporary entity
     */
    entityTmp getEntitiesAt(size_t pos) const;
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
    std::array<char, 512> _recvBuffer;
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
    std::string createPaquet(message::request request, std::string body);
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
    /**
     * @brief store which player is this client
     *
     */
    std::string _playerNumber;
    /**
     * @brief Entities received from the server
     * 
     */
    entitiesReceive entities;
    /**
     * @brief Add entity in the list of entities
     * 
     * @param body Body for the entity
     */
    void addEntity(std::string body);
};
