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

        std::stringstream outfile;
        outfile << _recv_buffer.data();
        boost::archive::text_iarchive oa(outfile);
        message test1;
        oa >> test1;
        std::cout << "Server received: " << std::endl;
        test1.print();

        commandHandler.findCmd(test1, this);

        std::stringstream os;
        message test2(message::ROOM, 1);
        // message test2(message::ROOM, _rooms.size());
        boost::archive::text_oarchive oa2(os);
        oa2 << test2;

        _recv_buffer.assign(0);
        _socket.async_send_to(boost::asio::buffer(os.str()), _remote_endpoint,
            boost::bind(&Server::handle_send, this, boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred));
        start_receive();
    }
}

void Server::handle_send(
    const boost::system::error_code& /*error*/,
    std::size_t /*bytes_transferred*/)
{
}
