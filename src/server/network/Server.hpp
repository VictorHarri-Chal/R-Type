/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

#pragma once

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>

#include "SafeQueue.hpp"
#include "../../utils/Message.hpp"
#include "../../utils/Rooms.hpp"

using boost::asio::ip::udp;
typedef std::map<uint32_t, udp::endpoint> ClientList;
typedef ClientList::value_type Client;

/**
 * @brief Server class
 * 
 */
class Server {
  public:
    /**
     * @brief Construct a new Server object
     * 
     * @param io_service 
     * @param port 
     */
    Server(boost::asio::io_service& io_service, int port) : _socket(io_service, udp::endpoint(udp::v4(), port)), _port(port), _roomId(0), _nbClients(0) {
      room_t room;
      room.id = -1;
      std::vector<room_t> tmp(7, room);
      _rooms = tmp;
      start_receive();
    }
    void handle_send(const boost::system::error_code& /*error*/,
        std::size_t /*bytes_transferred*/);
    /**
     * @brief Send a message to client
     * 
     * @param type of the request
     * @param value a int value if is needed
     */
    void sendMessage(message::request type, int value = 0);
    void sendToClient(message::request type, udp::endpoint target_endpoint, int value = 0);
    void SendToAll(message::request type, int value = 0);
    /**
     * @brief Get the Buffer object
     * 
     * @return boost::array<char, 64> 
     */
    boost::array<char, 64> getBuffer() const;
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
     * @return std::vector<room_t> 
     */
    std::vector<room_t> getRooms() const;
    /**
     * @brief 
     * 
     * @param room 
     */
    void addRooms(room_t room);
    /**
     * @brief Remove a room in the std::vector<room_t> _rooms
     * 
     * @param id 
     */
    void removeRooms(int id);
    /**
     * @brief add one to nb player in room
     * 
     * @param id 
     */
    void addPlayerInRoom(size_t id);
  private:
    /**
     * @brief Start receiving
     * 
     */
    void start_receive();
    /**
     * @brief Handle receive
     * 
     * @param error Error
     * @param bytes_transferred Bytes transferred
     */
    void handle_receive(const boost::system::error_code &error, std::size_t /*bytes_transferred*/);
    /**
     * @brief Handle send
     * 
     * @param error Error
     * @param bytes_transferred Bytes transferred
     */
      void handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code & /*error*/,
        std::size_t /*bytes_transferred*/);
    /**
     * @brief Get the or create client id object
     * 
     * @param endpoint 
     * @return uint32_t 
     */
    uint32_t getOrCreateClientId(udp::endpoint endpoint);
    /**
     * @brief Socket
     * 
     */
    udp::socket _socket;
    /**
     * @brief Endpoint
     * 
     */
    udp::endpoint _remote_endpoint;
    /**
     * @brief Buffer for data
     * 
     */
    boost::array<char, 64> _recv_buffer;
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
    std::vector<std::function<void(int, Server*)>> _allCommand;

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
     * @param server 
     */
    void findCmd(Server *server);
};
