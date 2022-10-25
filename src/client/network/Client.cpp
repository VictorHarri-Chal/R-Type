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
    std::size_t bytesTransferred)
{
    if (!error || error == boost::asio::error::message_size)
    {
        message msg;
        std::string recvStr(_recvBuffer.data(), _recvBuffer.data() + bytesTransferred);

        boost::iostreams::basic_array_source<char> source(recvStr.data(), recvStr.size());
        boost::iostreams::stream<boost::iostreams::basic_array_source<char>> ss(source);
        boost::archive::binary_iarchive ia(ss);
        ia >> msg;
        std::cout << "Client received message:" << std::endl;
        msg.print();
        std::cout << "Client printed message." << std::endl;

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

void Client::send(const std::string &message)
{
    _socket.send_to(boost::asio::buffer(message), _endpoint);
}

void Client::sendMessage(message::request request, int value)
{
    message msg(request, value);
    std::string str;
    boost::iostreams::back_insert_device<std::string> insert(str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>> ss(insert);
    boost::archive::binary_oarchive oa(ss);

    std::cout << "Sending message: " << std::endl;
    msg.print();
    oa << msg;
    ss.flush();
    send(str);
}

void Client::handleSend(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/)
{
}
