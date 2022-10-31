/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#pragma once
#include <boost/asio.hpp>

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
         * @param id Id of the client
         * @param endpoint Boost asio endpoint
         */
        Client(size_t id, udp::endpoint endpoint): _id(id), _endpoint(endpoint), _idRoom(0), _ready(false) {};
        /**
         * @brief Get the Id of the client
         * 
         * @return size_t Id of the client
         */
        size_t getId() const { return _id; };
        /**
         * @brief Get the Endpoint of the client
         * 
         * @return udp::endpoint Endpoint of the client
         */
        udp::endpoint getEndpoint() const { return _endpoint; };
        /**
         * @brief Get the Id Room of the client
         * 
         * @return size_t Id Room of the client
         */
        size_t getIdRoom() const { return _idRoom; };
        /**
         * @brief Get the if the client is ready to play
         * 
         * @return true If ready to play
         * @return false If not ready to play
         */
        bool getReady() const { return _ready; };
        /**
         * @brief Set the Id Room of the client
         * 
         * @param id Id Room of the client
         */
        void setIdRoom(size_t id) { _idRoom = id; };
        /**
         * @brief Set if the client is ready to play
         * 
         * @param ready Boolean to define if ready to play or not
         */
        void setReady(bool ready) { _ready = ready; };

    private:
        /**
         * @brief Id of the client
         * 
         */
        size_t _id;
        /**
         * @brief Endpoint of the client
         * 
         */
        udp::endpoint _endpoint;
        /**
         * @brief Id Room of the client
         * 
         */
        size_t _idRoom;
        /**
         * @brief Boolean to define if ready to play or not
         * 
         */
        bool _ready;
};
