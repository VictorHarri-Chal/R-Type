/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#include "Server.hpp"

/**
 * @brief Execute join room command
 *
 * @param value
 * @param server
 * @param actualId
 */
static void JoinCommand(std::string value, Server *server, size_t actualId)
{
    (void)server;
    (void)actualId;
    std::cout << "Player join room " << value << std::endl;
    server->addPlayerInRoom(actualId);
    server->_nbClientsInRoom++;
    server->SendToAll(message::request::INROOM, std::to_string(server->_nbClientsInRoom));
}

/**
 * @brief Execute Launch command when game start
 *
 * @param value
 * @param server
 * @param actualId
 */
static void LaunchCommand(std::string value, Server *server, size_t actualId)
{
    (void)value;
    std::cout << "Launch Command Asked" << std::endl;
    server->SendToAllInRoom(message::request::LAUNCH, actualId, "");
    server->setIsGameLaunched(true);
}

/**
 * @brief Execute ready command in room
 *
 * @param value
 * @param server
 * @param actualId
 */
static void ReadyCommand(std::string value, Server *server, size_t actualId)
{
    (void)actualId;
    (void)value;
    (void)server;
    size_t nbPlayer = server->getRoom()._idPeopleInRoom.size();

    std::cout << "Player " << actualId << " is ready" << std::endl;
    server->getClients().at(actualId).setReady(true);
    server->setPlayerReady(actualId);
    if (nbPlayer >= 2 && server->countNbPeopleReadyInRoom(server->getClients().at(actualId).getIdRoom()) == nbPlayer)
        LaunchCommand(value, server, actualId);
}
/**
 * @brief Execute disconect room command
 *
 * @param value
 * @param server
 * @param actualId
 */
static void DisconectCommand(std::string value, Server *server, size_t actualId)
{
    std::cout << "Disconect Command value = " << value << std::endl;
    server->removePlayerInRoom(actualId);
    server->_nbClientsInRoom--;
    server->SendToAll(message::request::INROOM, std::to_string(server->_nbClientsInRoom));
}

static void InRoomCommand(std::string value, Server *server, size_t actualId)
{
    (void)value;
    (void)server;
    (void)actualId;
    
    std::cout << "In Room Command" << std::endl;
}

static void MoveCommand(std::string body, Server *server, size_t actualId)
{
    (void)actualId;
    // (void)body;
    std::cout << "Move Command Asked" << std::endl;
    // server->sendMessage(message::request::ROOM, std::to_string(server->countRoom()));
}

HandleCommand::HandleCommand()
{
    _allCommand.emplace_back(JoinCommand);
    _allCommand.emplace_back(ReadyCommand);
    _allCommand.emplace_back(DisconectCommand);
    _allCommand.emplace_back(InRoomCommand);
    _allCommand.emplace_back(LaunchCommand);
    _allCommand.emplace_back(MoveCommand);

}

void HandleCommand::findCmd(Server *server, message msg, size_t actualId)
{
    this->_allCommand[msg.type](msg.body, server, actualId);
}
/**
 * Before handle command function
 **/

Server::Server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _nbClientsInRoom(0), _port(port),
_nbClients(0), _isGameLaunched(false), _isGameInit(false), waitCommand(false)
{
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

void Server::listenInGame()
{
//   std::cout << "start receive" << std::endl;
  _socket.async_receive_from(
      boost::asio::buffer(_recvBuffer), _remoteEndpoint,
      boost::bind(&Server::handleReceiveInGame, this,
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
        if (this->_isGameLaunched)
            this->gameLoop();
        else
            listen();
    }
}

void Server::handleReceiveInGame(const boost::system::error_code& error, std::size_t bytesTransferred)
  {
    if (!error || error == boost::asio::error::message_size)
    {
        size_t idClient;
        message msg = this->getStreamData(bytesTransferred);
        idClient = getOrCreateClientId(this->_remoteEndpoint);
        msg.print();
        listenInGame();
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
}

void Server::sendMessage(message::request request, std::string value)
{
    _socket.async_send_to(boost::asio::buffer(createPaquet(request, value)), _remoteEndpoint, boost::bind(&Server::listen, this));
}

void Server::sendToClient(message::request request, udp::endpoint targetEndpoint, std::string value)
{
    _socket.async_send_to(boost::asio::buffer(createPaquet(request, value)), targetEndpoint, boost::bind(&Server::listen, this));
}

void Server::SendToAll(message::request type, std::string body)
{
    for (auto client : clients)
        sendToClient(type, client.second.getEndpoint(), body);
}

void Server::SendToAllInRoom(message::request type, size_t actualId, std::string body)
{
    size_t actualRoom = this->clients.at(actualId).getIdRoom();
    int i = 1;
    for (auto client : clients) {
        if (client.second.getIdRoom() == actualRoom) {
            if (type == message::request::LAUNCH) {
                sendToClient(type, client.second.getEndpoint(), std::to_string(i));
                i++;
            } else {
                sendToClient(type, client.second.getEndpoint(), body);
            }
        }
    }
}

void Server::gameLoop(void)
{
    _game = new rtype::Game();
    _game->init();

    listenInGame();
    // if (getIsGameLaunched()) {
    //     if (!getIsGameInit()) {
    //         
    //         setIsGameInit(true);
    //     }
    // }
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

std::string Server::createPaquet(message::request request, std::string value)
{
    message msg(request, value);
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

void Server::addPlayerInRoom(size_t idPlayer)
{
    this->_room._idPeopleInRoom.insert(std::pair(idPlayer, false));
}

void Server::removePlayerInRoom(size_t idPlayer)
{
    std::map<size_t, bool>::iterator it;
    it = this->_room._idPeopleInRoom.find(idPlayer);
    this->_room._idPeopleInRoom.erase(it);
}

room_t Server::getRoom() const
{
    return(this->_room);
}

std::array<char, 64> Server::getBuffer() const
{
    return(this->_recvBuffer);
}

ClientList Server::getClients() const
{
    return (this->clients);
}

size_t Server::countNbPeopleReadyInRoom(size_t idRoom)
{
    (void)idRoom;
    size_t nbPeople = 0;

    for(std::map<size_t, bool>::iterator i = this->_room._idPeopleInRoom.begin(); i != this->_room._idPeopleInRoom.end(); i++)
        if ((*i).second == true)
            nbPeople++;
    return (nbPeople);
}

void Server::setPlayerReady(size_t idClient)
{
    this->_room._idPeopleInRoom.at(idClient) = true;
}

bool Server::getIsGameLaunched()
{
    return (this->_isGameLaunched);
}

bool Server::getIsGameInit()
{
    return (this->_isGameInit);
}

void Server::setIsGameLaunched(bool value)
{
    this->_isGameLaunched = value;
}

void Server::setIsGameInit(bool value)
{
    this->_isGameInit = value;
}