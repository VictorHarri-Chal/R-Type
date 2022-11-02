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
#include <fstream>
#include "../../utils/Message.hpp"
#include "../../utils/Rooms.hpp"
#include "Client.hpp"
#include "SafeQueue.hpp"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/shared_ptr.hpp>

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
     * @param type Type of the request
     * @param body Body of the request
     */
    void sendMessage(message::request type, std::string body = 0);
    /**
     * @brief Send Message to particular client
     *
     * @param type Type of the request
     * @param target_endpoint Client endpoint
     * @param body Body of the request
     */
    void sendToClient(message::request type, udp::endpoint target_endpoint, std::string body = 0);
    /**
     * @brief Send Message to all Client
     *
     * @param type Type of the request
     * @param body Body of the request
     */
    void SendToAll(message::request type, std::string body = 0);
    /**
     * @brief Send Message to all Client in the same room
     *
     * @param type Type of the request
     * @param actualId Id of the room
     * @param body Body of the request
     */
    void SendToAllInRoom(message::request type, size_t actualId, std::string body = 0);
    /**
     * @brief Get the Buffer object
     *
     * @return std::array<char, 64>
     */
    std::array<char, 64> getBuffer() const;
    /**
     * @brief Get the Room Id object
     *
     * @return size_t
     */
    size_t getRoomId() const;
    /**
     * @brief Count nb room available
     *
     * @return size_t
     */
    size_t countRoom();
    /**
     * @brief Set the Room Id object
     *
     * @param roomId
     */
    void setRoomId(size_t roomId);
    /**
     * @brief Get the Rooms object
     *
     * @return std::vector<room_t> List of all the rooms
     */
    std::vector<room_t> getRooms() const;
    /**
     * @brief Add rooms
     *
     * @param room Room to add
     */
    void addRooms(room_t room);
    /**
     * @brief Remove a room
     *
     * @param id Id of the room to remove
     */
    void removeRooms(int id);
    /**
     * @brief Add player in the room
     *
     * @param idRoom Id of the room
     * @param idPlayer Id of the player
     */
    void addPlayerInRoom(size_t idRoom, size_t idPlayer);
    /**
     * @brief Remove player from the room
     *
     * @param idRoom Id of the room
     * @param idPlayer Id of the player
     */
    void removePlayerInRoom(size_t idRoom, size_t idPlayer);
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
     * @param request Type of the request
     * @param body Body of the request
     * @return std::string Binary packet
     */
    std::string createPaquet(message::request request, std::string body);
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
     * @brief Vector to store all rooms infos
     *
     */
    std::vector<room_t> _rooms;
    /**
     * @brief Count number of room created
     *
     */
    size_t _roomId;
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
