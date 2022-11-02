/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** message
*/

#pragma once

#include <iostream>
#include <string>

/**
 * @brief Message class
 * 
 */
class message {
  public:
    /**
     * @brief Request type enum
     * 
     * @param CREATE Create room
     * @param JOIN Join room
     * @param DELETE Delete room
     * @param READY Ready in room
     * @param DISCONNECT Disconnect from room
     * @param ROOM Room message
     * @param INROOM In room message
     * @param LAUNCH Launch game
     * 
     */
    enum request { CREATE, JOIN, DELETE, READY, DISCONNECT, ROOM, INROOM, LAUNCH };
    /**
     * @brief Type of request
     * 
     */
    request type;
    /**
     * @brief Body of the message
     * 
     */
    std::string body;
    /**
     * @brief Construct a new message object
     * 
     */
    message(){};
    /**
     * @brief Construct a new message object
     * 
     * @param t Request type
     * @param b Body of the message
     */
    message(request t, std::string b) : type(t), body(b)
    {
    }
    /**
     * @brief Print the message
     * 
     */
    void print()
    {
        std::cout << "(" << type << ", " << body << ")" << std::endl;
    }
};

namespace boost
{
    namespace serialization
    {
        /**
         * @brief Serialize message
         * 
         * @tparam Archive Archive type
         * @param archive Archive
         * @param object Message to serialize
         * @param version Version of the message
         */
        template <class Archive> void serialize(Archive &archive, message &object, const unsigned int version)
        {
            archive &object.type;
            archive &object.body;
            (void)version;
        }
    } // namespace serialization
} // namespace boost
