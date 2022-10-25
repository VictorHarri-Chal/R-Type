/*
** EPITECH PROJECT, 2022
** Exceptions
** File description:
** Exceptions
*/

#pragma once

#include <exception>
#include <string>

/**
 * @brief Exceptions class
 *
 */
class Exceptions : public std::exception {
  public:
    /**
     * @brief Construct a new Exceptions object
     *
     */
    Exceptions()
    {
    }
    /**
     * @brief Construct a new Exceptions object
     *
     * @param msg Message to throw when the exception is catch
     */
    Exceptions(std::string msg) : _message(msg)
    {
    }
    /**
     * @brief Destroy the Exceptions object
     *
     */
    ~Exceptions()
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