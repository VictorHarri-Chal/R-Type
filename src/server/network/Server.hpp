/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#pragma once

#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/shared_ptr.hpp>
#include <fstream>
#include "../../utils/Message.hpp"
#include "../../utils/Rooms.hpp"
#include "Client.hpp"
#include "SafeQueue.hpp"
#include "../Game.hpp"


/**
 * @brief map of all the clients
 *
 */
typedef std::map<uint32_t, Client> ClientList;

/**
 * @brief Server class
 *
 */
class Server {
  public:
    /**
     * @brief Construct a new Server object
     *
     * @param io_service Boost io_service
     * @param port Port to listen
     */
    Server(boost::asio::io_service &io_service, int port);
    /**
     * @brief Send a message to client
     *
     * @param type of the request
     * @param value a std::string value if is needed
     */
    void sendMessage(message::request type, std::string value = "");

    room_t getRoom() const;

    /**
     * @brief Send Message to particular client
     *
     * @param type
     * @param target_endpoint
     * @param value
     */
    void sendToClient(message::request type, udp::endpoint target_endpoint, std::string value = "");
    /**
     * @brief Send Message to all Client
     *
     * @param type
     * @param value
     */
    void SendToAll(message::request type, std::string value = "");
    /**
     * @brief Send Message to all Client in the same room
     *
     * @param type
     * @param value
     */
    void SendToAllInRoom(message::request type, size_t acutalId, std::string value = "");
    /**
     * @brief Handle the server loop
     *
     */
    void gameLoop();
    /**
     * @brief Get the Buffer object
     *
     * @return std::array<char, 64>
     */
    std::array<char, 64> getBuffer() const;
    /**
     * @brief add one to nb player in room
     *
     * @param id
     */
    void addPlayerInRoom(size_t idPlayer);
    /**
     * @brief remove one to nb player in room
     *
     * @param id
     */
    void removePlayerInRoom(size_t idPlayer);
    /**
     * @brief Get the Clients object
     *
     * @return ClientList List of all the clients
     */
    ClientList getClients() const;
    /**
     * @brief Count who is ready in room
     *
     * @param idRoom Id of the room
     *
     * @return size_t The number of people ready in room
     */
    size_t countNbPeopleReadyInRoom(size_t idRoom);
    /**
     * @brief Set the Player Ready object in map of client in room
     *
     * @param idClient Id of the client
     */
    void setPlayerReady(size_t idClient);
    /**
     * @brief Get the Stream Data object
     *
     * @param bytesTransferred Number of bytes received
     * @return message Message received
     */
    message getStreamData(std::size_t bytesTransferred);
    bool getIsGameLaunched(void);
    bool getIsGameInit(void);
    void setIsGameLaunched(bool value);
    void setIsGameInit(bool value);
    /**
     * @brief nb client connect in room
     *
     */
    size_t _nbClientsInRoom;

    /**
     * @brief Game class
     *
     */
    rtype::Game *_game;

    size_t getPlayersInRoom();

    private:
    /**
        * @brief Start receiving
        *
        */
    void listen();
    /**
     * @brief Handle receive
     *
     * @param error Error
     * @param bytesTransferred Bytes transferred
     */
    void handleReceive(const boost::system::error_code &error, std::size_t /*bytesTransferred*/);
    /**
     * @brief Get the or create client id object
     *
     * @param endpoint Client endpoint
     * @return uint32_t Id of the client
     */
    uint32_t getOrCreateClientId(udp::endpoint endpoint);
    /**
     * @brief Create binary packet ready to be send
     *
     * @param request
     * @param value
     * @return std::string
     */
    std::string createPaquet(message::request request, std::string value);
    /**
     * @brief Socket
     *
     */
    udp::socket _socket;
    /**
     * @brief Endpoint
     *
     */
    udp::endpoint _remoteEndpoint;
    /**
     * @brief Buffer for data
     *
     */
    std::array<char, 64> _recvBuffer;
    /**
     * @brief Port
     *
     */
    int _port;
    /**
     * @brief Message queue with all command receive
     *
     */
    SafeQueue<message> _queue;

    room_t _room;
    /**
     * @brief Client connect to server
     *
     */
    ClientList clients;
    /**
     * @brief Number of client connect to server
     *
     */
    size_t _nbClients;
    /**
     * @brief Is game launched ?
     *
     */
    bool _isGameLaunched;
    /**
     * @brief Is game initialised ?
     *
     */
    bool _isGameInit;
};
/**
 * @brief HandleCommand class who execut command
 *
 */
class HandleCommand {
  private:
    /**
     * @brief Vector of function pointer
     *
     */
    std::vector<std::function<void(std::string, Server *, size_t)>> _allCommand;

  public:
    /**
     * @brief Construct a new Handle Command object
     *
     */
    HandleCommand();
    /**
     * @brief Destroy the Handle Command object
     *
     */
    ~HandleCommand() = default;
    /**
     * @brief Exectut the command ask
     *
     * @param server Server
     * @param msg Message received
     * @param actualId Id of the client
     */
    void findCmd(Server *server, message msg, size_t actualId);
};
