/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "server.hpp"
#include <fstream>
using boost::asio::ip::udp;

static void CreateCommand(int value, Server *server)
{
    (void)server;
    std::cout << "Create Command value = " << value << std::endl;
    if (server->getnbRoom() < 7) {
        server->setnbRoom(server->getnbRoom() + 1);
        server->sendMessage(message::request::ROOM, server->getnbRoom());
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
    server->sendMessage(message::request::ROOM, server->getnbRoom());
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

// TODO: Add class constructor here

void Server::start_receive()
{
  std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recv_buffer), _remote_endpoint,
      boost::bind(&Server::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Server::handle_receive(const boost::system::error_code& error,
    std::size_t /*bytes_transferred*/)
  {
    if (!error || error == boost::asio::error::message_size)
    {
      HandleCommand commandHandler;

        std::cout << "Queue size after the push:" << _queue.getSize() << std::endl;
        _queue.pop();
        std::cout << "Queue size after the pop:" << _queue.getSize() << std::endl;

        commandHandler.findCmd(this);
        start_receive();
    }
}

void Server::sendMessage(message::request type, int value)
{
    message Command(type, value);
    std::stringstream os;
    boost::archive::text_oarchive oa(os);
    oa << Command;

    _socket.async_send_to(boost::asio::buffer(os.str()), _remote_endpoint,
        boost::bind(&Server::start_receive, this));
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
    return(this->_recv_buffer);
}
