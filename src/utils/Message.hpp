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
    /*public access is required for the class member which are to be saved/loaded*/
    /**
     * @brief Request type enum
     *
     * @param JOIN Join room
     * @param READY Ready in room
     * @param DISCONNECT Disconnect from room
     * @param INROOM In room message
     * @param LAUNCH Launch game
     * @param MOVE Move command
     * @param ENTITY Entity command
     *
     */
    enum request { JOIN, READY, DISCONNECT, INROOM, LAUNCH, MOVE, ENTITY, SHOOT  };
    /**
     * @brief Request variable
     * 
     */
    request type;
    /**
     * @brief Body variable
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
     * @param t Type of the request
     * @param b Body of the request
     */
    message(request t, std::string b) : type(t), body(b) {}
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
