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

void Server::handleListen(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
  {
    if (!error || error == boost::asio::error::message_size)
    {
        HandleCommand commandHandler;
        message msg = getStreamData();
        message msgToSend(message::ROOM, 1);

        commandHandler.findCmd(this);
        std::cout << "Add message to queue... " << std::endl;
        _queue.push(msg);
        send(msgToSend);
        listen();
    }
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


void Server::send(message msg)
{
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);

    std::cout << "Send message to client..." << std::endl;
    msg.print();
    oa << msg;
    _recvBuffer.assign(0);
    _socket.async_send_to(boost::asio::buffer(ss.str()), _remoteEndpoint,
        boost::bind(&Server::handleSend, this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Server::send(message::request req, int value)
{
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    message msg(req, value);

    std::cout << "Send message to client..." << std::endl;
    msg.print();
    oa << msg;
    _recvBuffer.assign(0);
    _socket.async_send_to(boost::asio::buffer(ss.str()), _remoteEndpoint,
        boost::bind(&Server::handleSend, this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Server::handleSend(
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{
}

/*
** HandleCommand
*/
static void CreateCommand(int value, Server *server)
{
    std::cout << "Create Command value = " << value << std::endl;
    if (server->getnbRoom() < 7) {
        server->setnbRoom(server->getnbRoom() + 1);
        server->send(message::request::ROOM, server->getnbRoom());
    }
}

static void JoinCommand(int value, Server *server)
{
    (void)server;
    std::cout << "Join Command value = " << value << std::endl;
}

static void DeleteCommand(int value, Server *server)
{
    (void)server;
    std::cout << "Delete Command value = " << value << std::endl;
}

static void LaunchCommand(int value, Server *server)
{
    (void)server;
    std::cout << "Launch Command value = " << value << std::endl;
}

static void DisconectCommand(int value, Server *server)
{
    (void)server;
    std::cout << "Disconect Command value = " << value << std::endl;
}

static void RoomCommand(int value, Server *server)
{
    (void)value;
    std::cout << "Room Command Asked" << std::endl;
    server->send(message::request::ROOM, server->getnbRoom());
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

void HandleCommand::findCmd(Server *server)
{
    std::stringstream outfile;
    outfile << server->getBuffer().data();
    boost::archive::text_iarchive oa(outfile);
    message command;
    oa >> command;
    std::cout << "Server received: " << std::endl;
    command.print();
    this->_allCommand[command.type](command.value, server);
}

size_t Server::getnbRoom() const
{
    return(this->_nbRooms);
}

void Server::setnbRoom(size_t nbRooms)
{
    this->_nbRooms = nbRooms;
}

boost::array<char, 64> Server::getBuffer() const
{
    return(this->_recvBuffer);
}
