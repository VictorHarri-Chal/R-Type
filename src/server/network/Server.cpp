/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "Server.hpp"
#include "../../utils/Rooms.hpp"
#include <fstream>
using boost::asio::ip::udp;

static room_t CreateRoom(Server *server)
{
    room_t room;

    room.id = server->getRoomId();
    room.isOpen = true;
    room.name = "Room " + std::to_string(room.id);
    room.currPlayers = 0;
    return (room);
}

static void CreateCommand(int value, Server *server)
{
    std::cout << "Create Command value = " << value << std::endl;
    if (server->countRoom() < 7) {
        server->addRooms(CreateRoom(server));
        server->setRoomId(server->getRoomId() + 1);
        server->SendToAll(message::request::ROOM, server->countRoom());
    }
}

static void JoinCommand(int value, Server *server)
{
    (void)server;
    std::cout << "Player join room " << value << std::endl;
    server->addPlayerInRoom(value);
    server->sendMessage(message::request::INROOM, server->getRooms()[value].currPlayers);
}

static void DeleteCommand(int value, Server *server)
{
    (void)server;
    std::cout << "Delete Command value = " << value << std::endl;
    server->removeRooms(value / 10);
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
    server->sendMessage(message::request::ROOM, server->countRoom());
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
        getOrCreateClientId(this->_remote_endpoint);
        commandHandler.findCmd(this);
        start_receive();
    }
}

uint32_t Server::getOrCreateClientId(udp::endpoint endpoint)
{
    size_t nbClient = this->_nbClients;
    for (const auto& client : clients)
        if (client.second == endpoint)
            return client.first;
    std::cout << "New User id: " << nbClient << std::endl;
    clients.insert(Client(nbClient, endpoint));
    this->_nbClients++;
    return nbClient;
};

void Server::sendMessage(message::request type, int value)
{
    message Command(type, value);
    std::stringstream os;
    boost::archive::text_oarchive oa(os);
    oa << Command;

    _socket.async_send_to(boost::asio::buffer(os.str()), _remote_endpoint,
        boost::bind(&Server::start_receive, this));
}

void Server::sendToClient(message::request type, udp::endpoint target_endpoint, int value)
{
    message Command(type, value);
    std::stringstream os;
    boost::archive::text_oarchive oa(os);
    oa << Command;

    _socket.async_send_to(boost::asio::buffer(os.str()), target_endpoint,
        boost::bind(&Server::start_receive, this));
}

void Server::SendToAll(message::request type, int value)
{
    for (auto client : clients)
        sendToClient(type, client.second, value);
}

void Server::addPlayerInRoom(size_t id)
{
    this->_rooms[id].currPlayers += 1;
}

std::vector<room_t> Server::getRooms() const
{
    return(this->_rooms);
}

static int findPlace(Server *server)
{
    for (size_t i = 0; i < server->getRooms().size(); i++) {
        if (server->getRooms()[i].id == -1)
            return(i);
    }
    return (-1);
}

void Server::addRooms(room_t room)
{
    int place = findPlace(this);
    if (place == -1)
        return;
    this->_rooms[place] = room;
}

void Server::removeRooms(int id)
{
    if (id == -1 || this->_rooms[id].id == -1)
        return;
    this->_rooms[id].id = -1;
}

boost::array<char, 64> Server::getBuffer() const
{
    return(this->_recv_buffer);
}

size_t Server::countRoom()
{
    int nbRoom = 0;
    for (size_t i = 0; i < this->_rooms.size(); i++) {
        if (this->_rooms[i].id != -1)
            nbRoom++;
    }
    std::cout << nbRoom << std::endl;
    return (nbRoom);
}

size_t Server::getRoomId() const
{
    return(this->_roomId);
}

void Server::setRoomId(size_t roomId)
{
    this->_roomId = roomId;
}