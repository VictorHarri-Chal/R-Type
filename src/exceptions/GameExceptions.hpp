/*
** EPITECH PROJECT, 2022
** GameExceptions
** File description:
** GameExceptions
*/

#pragma once

#include "Exceptions.hpp"

/**
 * @brief Game Exception class
 *
 */
class GameExceptions : public Exceptions {
  public:
    /**
     * @brief Construct a new Game Exceptions object
     *
     */
    GameExceptions()
    {
    }
    /**
     * @brief Construct a new Game Exceptions object
     *
     * @param msg Message to throw when the exception is catch
     */
    GameExceptions(std::string msg) : _message(msg)
    {
    }
    /**
     * @brief Destroy the Game Exceptions object
     *
     */
    ~GameExceptions()
    {
    }
    /**
     * @brief Get the message to throw
     *
     * @return std::string Message to throw
     */
    const char *what() const throw()
    {
        return _message.c_str();
    }

  protected:
  private:
    /**
     * @brief Message to throw
     *
     */
    std::string _message;
};