/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

using boost::asio::ip::udp;

// TODO: Add class constructor here

void Server::listen()
{
  _socket.async_receive_from(
      boost::asio::buffer(_recvBuffer), _remoteEndpoint,
      boost::bind(&Server::handleListen, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

message Server::getStreamData()
{
    std::stringstream ss;
    message msg;

    ss << _recvBuffer.data();
    boost::archive::text_iarchive ia(ss);
    ia >> msg;
    std::cout << "Server received a message: " << std::endl;
    msg.print();
    return msg;
}

void Server::handleListen(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
  {
    if (!error || error == boost::asio::error::message_size)
    {
        HandleCommand commandHandler;
        message msg = getStreamData();
        message msgToSend(message::ROOM, 1);

        commandHandler.findCmd(msg, this);
        std::cout << "Add message to queue... " << std::endl;
        _queue.push(msg);
        send(msgToSend);
        listen();
    }
}

void Server::send(message msg)
{
    std::stringstream sscanf;
    boost::archive::text_oarchive oa(sscanf);

    std::cout << "Send message to client..." << std::endl;
    msg.print();
    oa << msg;
    _recvBuffer.assign(0);
    _socket.async_send_to(boost::asio::buffer(sscanf.str()), _remoteEndpoint,
        boost::bind(&Server::handleSend, this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Server::handleSend(
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{
}

static void CreateCommand(int value, Server *server)
{
    std::cout << "Create Command value = " << value << std::endl;
}

static void JoinCommand(int value, Server *server)
{
    std::cout << "Join Command value = " << value << std::endl;
}

static void DeleteCommand(int value, Server *server)
{
    std::cout << "Delete Command value = " << value << std::endl;
}

static void LaunchCommand(int value, Server *server)
{
    std::cout << "Launch Command value = " << value << std::endl;
}

static void DisconectCommand(int value, Server *server)
{
    std::cout << "Disconect Command value = " << value << std::endl;
}

static void RoomCommand(int value, Server *server)
{
    std::cout << "Room Command Asked" << std::endl;
}

HandleCommand::HandleCommand()
{
    _allCommand.emplace_back(CreateCommand);
    _allCommand.emplace_back(JoinCommand);
    _allCommand.emplace_back(DeleteCommand);
    _allCommand.emplace_back(LaunchCommand);
    _allCommand.emplace_back(DisconectCommand);
    _allCommand.emplace_back(RoomCommand);
}

void HandleCommand::findCmd(message command, Server *server)
{
    this->_allCommand[command.type](command.value, server);
}
