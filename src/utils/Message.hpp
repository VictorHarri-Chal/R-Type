/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** message
*/

#pragma once

#include <iostream>
#include <string>

class message {
  public:
    enum request { JOIN, READY, DISCONNECT, INROOM, LAUNCH };
    /*public access is required for the class member which are to be saved/loaded*/
    request type;
    std::string body;

    /*default constructor for class*/
    message(){};
    /*parameterized constructor for class*/
    message(request t, std::string b) : type(t), body(b)
    {
    }

    /*this function prints the details of class object*/
    void print()
    {
        std::cout << "(" << type << ", " << body << ")" << std::endl;
    }
};

namespace boost
{
    namespace serialization
    {
        template <class Archive> void serialize(Archive &archive, message &object, const unsigned int version)
        {
            archive &object.type;
            archive &object.body;
            (void)version;
        }
    } // namespace serialization
} // namespace boost
