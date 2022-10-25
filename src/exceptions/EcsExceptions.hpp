/*
** EPITECH PROJECT, 2022
** EcsExceptions
** File description:
** EcsExceptions
*/

#pragma once

#include "Exceptions.hpp"

/**
 * @brief Esc Exception class
 *
 */
class EcsExceptions : public Exceptions {
  public:
    /**
     * @brief Construct a new Ecs Exceptions object
     *
     */
    EcsExceptions()
    {
    }
    /**
     * @brief Construct a new Ecs Exceptions object
     *
     * @param msg Message to throw when the exception is catch
     */
    EcsExceptions(std::string msg) : _message(msg)
    {
    }
    /**
     * @brief Destroy the Ecs Exceptions object
     *
     */
    ~EcsExceptions()
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