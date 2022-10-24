/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

Client::~Client()
{
  _socket.close();
}

void Client::listen()
{
  _socket.async_receive_from(
      boost::asio::buffer(_recvBuffer), _endpoint,
      boost::bind(&Client::handleListen, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Client::handleListen(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
{
    if (!error || error == boost::asio::error::message_size)
    {
        message msg = getStreamData();
        // message msgToSend(message::ROOM, 1);

        // send(msgToSend);
        listen();
    }
}

message Client::getStreamData()
{
    std::stringstream ss;
    message msg;

    ss << _recvBuffer.data();
    boost::archive::text_iarchive ia(ss);
    ia >> msg;
    std::cout << "Client received a message: " << std::endl;
    msg.print();
    return msg;
}

void Client::send(message::request request, int value)
{
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    message msg(request, value);

    std::cout << "Send message to server..." << std::endl;
    msg.print();
    oa << msg;
    _recvBuffer.assign(0);
    _socket.send_to(boost::asio::buffer(ss.str()), _endpoint);
}

void Client::handleSend(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/)
{
}
