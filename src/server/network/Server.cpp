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
 * @param playerId
 */
static void JoinCommand(std::string value, Server *server, size_t playerId)
{
    (void)server;
    (void)playerId;
    std::cout << "Player join room " << value << std::endl;
    server->addPlayerInRoom(playerId);
    server->_nbClientsInRoom++;
    server->SendToAll(message::request::INROOM, std::to_string(server->_nbClientsInRoom));
}

/**
 * @brief Execute Launch command when game start
 *
 * @param value
 * @param server
 * @param playerId
 */
static void LaunchCommand(std::string value, Server *server, size_t playerId)
{
    (void)value;
    std::cout << "Launch Command Asked" << std::endl;
    server->SendToAllInRoom(message::request::LAUNCH, playerId, "");
    server->setIsGameLaunched(true);
}

/**
 * @brief Execute ready command in room
 *
 * @param value
 * @param server
 * @param playerId
 */
static void ReadyCommand(std::string value, Server *server, size_t playerId)
{
    (void)playerId;
    (void)value;
    (void)server;
    size_t nbPlayer = server->getRoom()._idPeopleInRoom.size();

    std::cout << "Player " << playerId << " is ready" << std::endl;
    server->getClients().at(playerId).setReady(true);
    server->setPlayerReady(playerId);
    if (nbPlayer >= 2 && server->countNbPeopleReadyInRoom(server->getClients().at(playerId).getIdRoom()) == nbPlayer)
        LaunchCommand(value, server, playerId);
}
/**
 * @brief Execute disconect room command
 *
 * @param value
 * @param server
 * @param playerId
 */
static void DisconectCommand(std::string value, Server *server, size_t playerId)
{
    std::cout << "Disconect Command value = " << value << std::endl;
    server->removePlayerInRoom(playerId);
    server->_nbClientsInRoom--;
    server->SendToAll(message::request::INROOM, std::to_string(server->_nbClientsInRoom));
}

static void InRoomCommand(std::string value, Server *server, size_t playerId)
{
    (void)value;
    (void)server;
    (void)playerId;

    std::cout << "In Room Command" << std::endl;
}

HandleCommand::HandleCommand()
{
    _allCommand.emplace_back(JoinCommand);
    _allCommand.emplace_back(ReadyCommand);
    _allCommand.emplace_back(DisconectCommand);
    _allCommand.emplace_back(InRoomCommand);
    _allCommand.emplace_back(LaunchCommand);

}

void HandleCommand::findCmd(Server *server, message msg, size_t playerId)
{
    this->_allCommand[msg.type](msg.body, server, playerId);
}
/**
 * Before handle command function
 **/

Server::Server(boost::asio::io_service &io_service, int port)
    : _nbClientsInRoom(0), _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port), _nbClients(0),
      _isGameLaunched(false), _isGameInit(false), waitCommand(false)
{
    std::cout << "Server started." << std::endl;
    listen();
}

Server::~Server()
{
    this->t1.join();
}

void Server::listen()
{
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
        idClient = getOrCreateClientId(this->_remoteEndpoint);

        if (this->_isGameLaunched)
            this->gameLoop(msg, idClient);
        else
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
}

void Server::sendMessage(message::request request, udp::endpoint targetEndpoint, std::string value)
{
    _socket.async_send_to(boost::asio::buffer(createPaquet(request, value)), targetEndpoint, boost::bind(&Server::listen, this));
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

void Server::SendToAll(::Server server, message::request type, std::string body)
{
    for (auto client : server.clients)
        server.sendToClient(type, client.second.getEndpoint(), body);
}

void Server::SendToAllInRoom(message::request type, size_t playerId, std::string body)
{
    size_t actualRoom = this->clients.at(playerId).getIdRoom();
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

void Server::sendAllEntities()
{
    size_t nbEntity;
    std::string entity;
    rtype::ecs::component::Transform *transformCompo;

    while(true) {
        if (this->_clock.getElapsedTime() >= sf::seconds(1.0f / 45.0f)) {
            this->_game->destroySprites();
            this->_game->update();
            nbEntity = this->_game->getWorld()->getNbEntities();
            for (size_t i = 0; i < nbEntity; i++) {
                entity = std::to_string(i) + ";" + std::to_string(this->_game->getWorld()->getEntity(i)->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM)->getX()) + ";" + std::to_string(this->_game->getWorld()->getEntity(i)->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM)->getY());
                for (auto client : clients)
                    _socket.async_send_to(boost::asio::buffer(createPaquet(message::ENTITY, entity)), client.second.getEndpoint(), boost::bind(&Server::listen, this));
                entity.clear();
                if (this->_game->getWorld()->getEntity(i)->getEntityType() == rtype::ecs::entity::entityType::PLAYER1 || this->_game->getWorld()->getEntity(i)->getEntityType() == rtype::ecs::entity::entityType::PLAYER2 || this->_game->getWorld()->getEntity(i)->getEntityType() == rtype::ecs::entity::entityType::PLAYER3 || this->_game->getWorld()->getEntity(i)->getEntityType() == rtype::ecs::entity::entityType::PLAYER4) {
                    transformCompo = this->_game->getWorld()->getEntity(i)->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::compoType::TRANSFORM);
                    transformCompo->setSpeedY(0.0f);
                    transformCompo->setSpeedX(0.0f);
                }
            }
            this->_clock.restart();
        }
    }
}

void Server::gameLoop(message msg, size_t playerId)
{
    int ret = 0;
    if (!getIsGameInit()) {
        _game = new rtype::Game(this->getPlayersInRoom());
        _game->init();
        setIsGameInit(true);
        this->t1 = boost::thread(&Server::sendAllEntities, this);
    }
    std::cout << "Game Loop" << std::endl;
    ret = _game->handleEvents(msg.body, playerId);

    if (ret == 1) {
        SendToAll(message::request::SHOOT, std::to_string(playerId));
        _game->createShoot(playerId);
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
    std::cout << "Server received :" << std::endl;
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

size_t Server::getPlayersInRoom()
{
    return this->_room._idPeopleInRoom.size();
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
