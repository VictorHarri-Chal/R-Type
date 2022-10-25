/*
** EPITECH PROJECT, 2022
** ScreensExceptions
** File description:
** ScreensExceptions
*/

#pragma once

#include "Exceptions.hpp"

/**
 * @brief Screens Exception class
 *
 */
class ScreensExceptions : public Exceptions {
  public:
    /**
     * @brief Construct a new Screens Exceptions object
     *
     */
    ScreensExceptions()
    {
    }
    /**
     * @brief Construct a new Screens Exceptions object
     *
     * @param msg Message to throw when the exception is catch
     */
    ScreensExceptions(std::string msg) : _message(msg)
    {
    }
    /**
     * @brief Destroy the Screens Exceptions object
     *
     */
    ~ScreensExceptions()
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