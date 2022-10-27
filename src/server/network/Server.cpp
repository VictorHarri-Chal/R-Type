/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

/**
 * @brief Create a Room object
 * 
 * @param server 
 * @return room_t 
 */
static room_t CreateRoom(Server *server)
{
    room_t room;

    room.id = server->getRoomId();
    room.isOpen = true;
    room.name = "Room " + std::to_string(room.id);
    room.currPlayers = 0;
    return (room);
}
/**
 * @brief Execute create room command
 * 
 * @param value 
 * @param server 
 * @param actualId 
 */
static void CreateCommand(std::string body, Server *server, size_t actualId)
{
    (void)actualId;
    std::cout << "Create Command value = " << body << std::endl;
    if (server->countRoom() < 7) {
        server->addRooms(CreateRoom(server));
        server->setRoomId(server->getRoomId() + 1);
        server->SendToAll(message::request::ROOM, std::to_string(server->countRoom()));
    }
}
/**
 * @brief Execute join room command
 * 
 * @param value 
 * @param server 
 * @param actualId 
 */
static void JoinCommand(std::string body, Server *server, size_t actualId)
{
    (void)server;
    std::cout << "Player join room " << body << std::endl;
    server->getClients().at(actualId).setIdRoom(std::stoi(body));
    server->addPlayerInRoom(std::stoi(body), actualId);
    server->SendToAllInRoom(message::request::INROOM, actualId, std::to_string(server->getRooms()[std::stoi(body)]._idPeopleInRoom.size()));
}
/**
 * @brief Execute delete room command
 * 
 * @param value 
 * @param server 
 * @param actualId 
 */
static void DeleteCommand(std::string body, Server *server, size_t actualId)
{
    (void)actualId;
    std::cout << "Delete Command value = " << body << std::endl;
    server->removeRooms(std::stoi(body));
    server->SendToAll(message::request::ROOM, std::to_string(server->countRoom()));
}
/**
 * @brief Execute Launch command when game start
 * 
 * @param value 
 * @param server 
 * @param actualId 
 */
static void LaunchCommand(std::string body, Server *server, size_t actualId)
{
    (void)actualId;
    (void)body;
    std::cout << "Lauch Command Asked" << std::endl;
    server->SendToAllInRoom(message::request::LAUNCH, actualId);
}
/**
 * @brief Execute ready command in room
 * 
 * @param value 
 * @param server 
 * @param actualId 
 */
static void ReadyCommand(std::string body, Server *server, size_t actualId)
{
    size_t nbPlayer = server->getRooms()[server->getClients().at(actualId).getIdRoom()]._idPeopleInRoom.size();

    std::cout << "Player " << actualId << " is ready" << std::endl;
    server->getClients().at(actualId).setReady(true);
    server->setPlayerReady(actualId);
    if (nbPlayer >= 2 && server->countNbPeopleReadyInRoom(server->getClients().at(actualId).getIdRoom()) == nbPlayer)
        LaunchCommand(body, server, actualId);
}
/**
 * @brief Execute disconect room command
 * 
 * @param value 
 * @param server 
 * @param actualId 
 */
static void DisconectCommand(std::string body, Server *server, size_t actualId)
{
    std::cout << "Disconect Command value = " << body << std::endl;
    server->removePlayerInRoom(server->getRooms().at(server->getClients().at(actualId).getIdRoom()).id, actualId);
    server->SendToAll(message::request::ROOM, std::to_string(server->countRoom()));
    server->SendToAllInRoom(message::request::INROOM, actualId, std::to_string(server->getRooms()[server->getRooms().at(server->getClients().at(actualId).getIdRoom()).id]._idPeopleInRoom.size()));
    server->getClients().at(actualId).setIdRoom(-1);

}
/**
 * @brief Execute room command who send number of room
 * 
 * @param value 
 * @param server 
 * @param actualId 
 */
static void RoomCommand(std::string body, Server *server, size_t actualId)
{
    (void)actualId;
    (void)body;
    std::cout << "Room Command Asked" << std::endl;
    server->sendMessage(message::request::ROOM, std::to_string(server->countRoom()));
}

HandleCommand::HandleCommand()
{
    _allCommand.emplace_back(CreateCommand);
    _allCommand.emplace_back(JoinCommand);
    _allCommand.emplace_back(DeleteCommand);
    _allCommand.emplace_back(ReadyCommand);
    _allCommand.emplace_back(DisconectCommand);
    _allCommand.emplace_back(RoomCommand);
    _allCommand.emplace_back(LaunchCommand);
}

void HandleCommand::findCmd(Server *server, message msg, size_t actualId)
{
    this->_allCommand[msg.type](msg.body, server, actualId);
}
/**
 * Before handle command function
 **/

Server::Server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port), _roomId(0), _nbClients(0)
{
    room_t room;
    room.id = -1;
    std::vector<room_t> tmp(7, room);
    _rooms = tmp;
    listen();
}

void Server::listen()
{
  std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recvBuffer), _remoteEndpoint,
      boost::bind(&Server::handleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Server::handleReceive(const boost::system::error_code& error, std::size_t bytesTransferred)
  {
    if (!error || error == boost::asio::error::message_size)
    {
        HandleCommand commandHandler;
        size_t idClient;
        message msg = this->getStreamData(bytesTransferred);
        std::cout << "Queue size after the push:" << _queue.getSize() << std::endl;
        _queue.pop();
        std::cout << "Queue size after the pop:" << _queue.getSize() << std::endl;
        idClient = getOrCreateClientId(this->_remoteEndpoint);
        commandHandler.findCmd(this, msg, idClient);
        listen();
    }
}

uint32_t Server::getOrCreateClientId(udp::endpoint endpoint)
{
    size_t nbClient = this->_nbClients;

    for (const auto& client : clients)
        if (client.second.getEndpoint() == endpoint)
            return client.first;

    Client newClient(nbClient, endpoint);
    std::cout << "New User id: " << nbClient << std::endl;
    clients.insert(std::pair(nbClient, newClient));
    this->_nbClients++;
    return nbClient;
};

void Server::sendMessage(message::request request, std::string body)
{
    _socket.async_send_to(boost::asio::buffer(createPaquet(request, body)), _remoteEndpoint, boost::bind(&Server::listen, this));
}

void Server::sendToClient(message::request request, udp::endpoint targetEndpoint, std::string body)
{
    _socket.async_send_to(boost::asio::buffer(createPaquet(request, body)), targetEndpoint, boost::bind(&Server::listen, this));
}

void Server::SendToAll(message::request type, std::string body)
{
    for (auto client : clients)
        sendToClient(type, client.second.getEndpoint(), body);
}

void Server::SendToAllInRoom(message::request type, size_t actualId, std::string body)
{
    size_t actualRoom = this->clients.at(actualId).getIdRoom();

    for (auto client : clients)
        if (client.second.getIdRoom() == actualRoom)
            sendToClient(type, client.second.getEndpoint(), body);
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

    return msg;
}

std::string Server::createPaquet(message::request request, std::string body)
{
    message msg(request, body);
    std::string str;

    boost::iostreams::back_insert_device<std::string> insert(str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string>> ss(insert);
    boost::archive::binary_oarchive oa(ss);

    std::cout << "Sending message: ";
    msg.print();
    oa << msg;
    ss.flush();
    return (str);
}

void Server::addPlayerInRoom(size_t idRoom, size_t idPlayer)
{
    this->_rooms[idRoom]._idPeopleInRoom.insert(std::pair(idPlayer, false));
}

void Server::removePlayerInRoom(size_t idRoom, size_t idPlayer)
{
    this->_rooms[idRoom]._idPeopleInRoom.erase(idPlayer);
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

std::array<char, 64> Server::getBuffer() const
{
    return(this->_recvBuffer);
}

size_t Server::countRoom()
{
    int nbRoom = 0;
    for (size_t i = 0; i < this->_rooms.size(); i++) {
        if (this->_rooms[i].id >= 0)
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

ClientList Server::getClients() const
{
    return (this->clients);
}

size_t Server::countNbPeopleReadyInRoom(size_t idRoom)
{
    size_t nbPeople = 0;

    for(std::map<size_t, bool>::iterator i = this->_rooms[idRoom]._idPeopleInRoom.begin(); i != this->_rooms[idRoom]._idPeopleInRoom.end(); i++)
        if ((*i).second == true)
            nbPeople++;
    return (nbPeople);
}

void Server::setPlayerReady(size_t idClient)
{
    this->_rooms.at(this->clients.at(idClient).getIdRoom())._idPeopleInRoom.at(idClient) = true;
}