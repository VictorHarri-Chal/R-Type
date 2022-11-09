/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(boost::asio::io_service &io_service, const std::string &host, const std::string &port): _ioService(io_service), _socket(io_service, udp::endpoint(udp::v4(), 0))
{
    udp::resolver resolver(_ioService);
    udp::resolver::query query(udp::v4(), host, port);
    udp::resolver::iterator iter = resolver.resolve(query);
    _endpoint = *iter;
    _actualNbRooms = 0;
    _actualNbPeopleInRoom = 0;
    _gameStart = false;
    std::cout << "Client started." << std::endl;
    listen();
}

Client::~Client()
{
    _socket.close();
}

void Client::listen()
{
    _socket.async_receive_from(boost::asio::buffer(_recvBuffer), _endpoint,
        boost::bind(&Client::handleReceive, this, boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Client::handleReceive(const boost::system::error_code &error, std::size_t bytesTransferred)
{
    if (!error || error == boost::asio::error::message_size) {
        message msg = getStreamData(bytesTransferred);
        if (msg.type == message::INROOM)
            this->_actualNbPeopleInRoom = std::stoi(msg.body);
        if (msg.type == message::LAUNCH) {
            this->_gameStart = true;
            this->_playerNumber = msg.body;
        }
        if (msg.type == message::ENTITY)
            addEntity(msg.body);
        listen();
    }
}

void Client::send(message::request request, std::string body)
{
    _socket.send_to(boost::asio::buffer(createPaquet(request, body)), _endpoint);
}

message Client::getStreamData(std::size_t bytesTransferred)
{
    message msg;
    std::string recvStr(_recvBuffer.data(), _recvBuffer.data() + bytesTransferred);

    boost::iostreams::basic_array_source<char> source(recvStr.data(), recvStr.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char>> ss(source);
    boost::archive::binary_iarchive ia(ss);
    ia >> msg;
    std::cout << "Client received: ";
    msg.print();

    return msg;
}

std::string Client::createPaquet(message::request request, std::string body)
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

size_t Client::getNbRoom() const
{
    return (this->_actualNbRooms);
}

size_t Client::getNbPeopleInRoom() const
{
    return (this->_actualNbPeopleInRoom);
}

bool Client::getGameStart() const
{
    return (this->_gameStart);
}

std::string Client::getPlayerNumber() const
{
    return (this->_playerNumber);
}

entitiesReceive Client::getEntities() const
{
    return(this->entities);
}

entityTmp Client::getEntitiesAt(size_t pos) const
{
    return(this->entities.at(pos));
}

void Client::popEntity()
{
    this->entities.erase(this->entities.begin());
}

void Client::addEntity(std::string body)
{
    std::regex playerTemplate("(\\d);(([+-]?[0-9]*[.])?[0-9]+);(([+-]?[0-9]*[.])?[0-9]+)");
    std::smatch sm;

    std::regex_search(body, sm, playerTemplate);
    entityTmp newEntity;
    newEntity.id = std::stoi(sm.str(1)) + 4;
    newEntity.posX = std::stof(sm.str(2));
    newEntity.posY = std::stof(sm.str(4));
    this->entities.push_back(newEntity);
}