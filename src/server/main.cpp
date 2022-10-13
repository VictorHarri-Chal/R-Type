/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

// #include "network/server.hpp"
// #include "network/SafeQueue.hpp"

#include <string>
#include <bitset>
#include <iostream>

int main() {
    std::string myString = "Hello World";

    for (std::size_t i = 0; i < myString.size(); ++i)
    {
      std::cout << std::bitset<8>(myString.c_str()[i]) << std::endl;
    }
    // try
    // {
    //     boost::asio::io_context io_context;
    //     Server server(io_context, 4242);
    //     io_context.run();
    // }
    // catch (std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    // return 0;
}
