/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** ClientBuffer
*/

#ifndef CLIENTBUFFER_HPP_
#define CLIENTBUFFER_HPP_

#include <boost/asio/streambuf.hpp>
#include <iostream>
#include <string>

struct ClientPayload {
    int request;
    int data_length;
    std::string data;
};

class ClientBuffer {
    public:
        ClientBuffer();
        ~ClientBuffer() = default;

        void write(struct ClientPayload &);
        void write(const std::string &data);
        void write(int i);
    private:
        std::ostream _oStream;
        std::istream _iStream;
        boost::asio::streambuf _streamBuffer;
};

#endif /* !CLIENTBUFFER_HPP_ */
