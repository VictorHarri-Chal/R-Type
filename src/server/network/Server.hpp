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
#include <boost/thread/thread.hpp>


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
     * @brief Destroy the Server object
     *
     */
    ~Server();
    /**
     * @brief Send a message to client
     *
     * @param type Type of the request
     * @param targetEndpoint endpoint of the client
     * @param value a std::string value if is needed
     */
    void sendMessage(message::request type, udp::endpoint targetEndpoint, std::string value = "");
    /**
     * @brief Get the Room object
     * 
     * @return room_t The room object
     */
    room_t getRoom() const;

    /**
     * @brief Send Message to particular client
     *
     * @param type Type of the request
     * @param target_endpoint endpoint of the client
     * @param value a std::string value if is needed
     */
    void sendToClient(message::request type, udp::endpoint target_endpoint, std::string value = "");
    /**
     * @brief Send Message to all Client
     *
     * @param type Type of the request
     * @param value a std::string value if is needed
     */
    void SendToAll(message::request type, std::string value = "");
    /**
     * @brief Send Message to all Client
     * 
     * @param server Server class
     * @param type Type of the request
     * @param value a std::string value if is needed
     */
    static void SendToAll(::Server server, message::request type, std::string value = "");
    /**
     * @brief Send Message to all Client in the same room
     *
     * @param type Type of the request
     * @param actualId Id of the client
     * @param value a std::string value if is needed
     */
    void SendToAllInRoom(message::request type, size_t actualId, std::string value = "");
    /**
     * @brief Handle the server loop
     * 
     * @param msg Message received
     * @param actualId Id of the client
     */
    void gameLoop(message msg, size_t actualId);
    /**
     * @brief Get the Buffer object
     *
     * @return std::array<char, 64> The buffer
     */
    std::array<char, 64> getBuffer() const;
    /**
     * @brief Add player in room
     *
     * @param idPlayer Id of the player
     */
    void addPlayerInRoom(size_t idPlayer);
    /**
     * @brief Remove player from a room
     *
     * @param idPlayer Id of the player
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
    /**
     * @brief Get the Is Game Launched object
     *
     * @return true
     * @return false
     */
    bool getIsGameLaunched(void);
    /**
     * @brief Get the Is Game Init object
     *
     * @return true
     * @return false
     */
    bool getIsGameInit(void);
    /**
     * @brief Set the Is Game Launched object
     *
     * @param value Value to set to determine if game is launched or not
     */
    void setIsGameLaunched(bool value);
    /**
     * @brief Set the Is Game Init object
     *
     * @param value Value to set to determine if the game is init or not
     */
    void setIsGameInit(bool value);
    /**
     * @brief Number of clients connected in room
     *
     */
    size_t _nbClientsInRoom;
    /**
     * @brief Start the game
     * 
     */
    void startGame();
    /**
     * @brief Game object
     *
     */
    rtype::Game *_game;
  private:
    /**
     * @brief Get all the players in the room
     * 
     * @return size_t Number of players in the room
     */
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
     * @param request Request to send
     * @param value Value to send
     * @return std::string Binary packet
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
    /**
     * @brief Room object
     * 
     */
    room_t _room;
    /**
     * @brief List of clients
     *
     */
    ClientList clients;
    /**
     * @brief Number of client connected to server
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
    bool waitCommand;
    /**
     * @brief send all information about entities to all client
     *
     */
    void sendAllEntities();
    /**
     * @brief Clock for game
     * 
     */
    sf::Clock _clock;
    /**
     * @brief Thread for game
     * 
     */
    boost::thread t1;
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
     * @param server Server object
     * @param msg Message received
     * @param actualId Id of the client
     */
    void findCmd(Server *server, message msg, size_t actualId);
};
