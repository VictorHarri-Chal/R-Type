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
    std::size_t bytesTransferred)
  {
    if (!error || error == boost::asio::error::message_size)
    {
        HandleCommand commandHandler;
        message command = getStreamData(bytesTransferred);


        commandHandler.findCmd(this, command);
        // std::cout << "Add message to queue... " << std::endl;
        // _queue.push(msg);
        // send(msgToSend);
        listen();
    }
}

message Server::getStreamData(std::size_t bytesTransferred)
{
    message msg;
    std::string recvStr(_recvBuffer.data(), _recvBuffer.data() + bytesTransferred);

    boost::iostreams::basic_array_source<char> source(recvStr.data(), recvStr.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char>> ss(source);
    boost::archive::binary_iarchive ia(ss);
    ia >> msg;
    std::cout << "Server received message:" << std::endl;
    msg.print();
    std::cout << "Server printed message." << std::endl;

    return msg;
}

void Server::send(std::string msg)
{
    _socket.async_send_to(boost::asio::buffer(msg), _remoteEndpoint,
        boost::bind(&Server::handleSend, this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Server::sendMessage(message::request request, int value)
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

void Server::handleSend(
    const boost::system::error_code& /*error*/,
    std::size_t /*bytesTransferred*/)
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

void HandleCommand::findCmd(Server *server, message command)
{
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

std::array<char, 64> Server::getBuffer() const
{

    return(this->_recvBuffer);
}
