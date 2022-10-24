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
    std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::message_size)
    {
        // message msg = getStreamData();
        // // message msgToSend(message::ROOM, 1);

        // // send(msgToSend);

        message msg;

        std::string recv_str(_recvBuffer.data(), _recvBuffer.data() + bytes_transferred);

        boost::iostreams::basic_array_source<char> device(recv_str.data(), recv_str.size());
        boost::iostreams::stream<boost::iostreams::basic_array_source<char>> s(device);
        boost::archive::binary_iarchive ia(s);
        ia >> msg;

        std::cout << msg.type << std::endl;
        std::cout << msg.value << std::endl;

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

// void Client::send(message::request request, int value)
// {
//     std::stringstream ss;
//     boost::archive::text_oarchive oa(ss);
//     message msg(request, value);

//     std::cout << "Send message to server..." << std::endl;
//     msg.print();
//     oa << msg;
//     // _recvBuffer.assign(0);
//     _socket.send_to(boost::asio::buffer(ss.str()), _endpoint);
// }

void Client::send(const std::string &message)
{
    _socket.send_to(boost::asio::buffer(message), _endpoint);
}

void Client::sendMessage(message::request request, int value)
{
    std::cout << request << std::endl;
    std::cout << value << std::endl;

    message msg(request, value);

    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>> s(inserter);
    boost::archive::binary_oarchive oa(s);

    oa << msg;

    s.flush();

    send(serial_str);
}

void Client::handleSend(const boost::system::error_code& error,
        std::size_t /*bytes_transferred*/)
{
}
