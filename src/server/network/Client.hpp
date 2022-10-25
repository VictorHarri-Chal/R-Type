/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#pragma once
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class Client {
    public:
        Client(size_t id, udp::endpoint endpoint): _id(id), _endpoint(endpoint), _idRoom(0), _ready(false) {};

        size_t getId() const { return _id; };
        udp::endpoint getEndpoint() const { return _endpoint; };
        size_t getIdRoom() const { return _idRoom; };
        bool getReady() const { return _ready; };
        
        void setIdRoom(size_t id) { _idRoom = id; };
        void setReady(bool ready) { _ready = ready; };

    private:
        size_t _id;
        udp::endpoint _endpoint;
        size_t _idRoom;
        bool _ready;
};
