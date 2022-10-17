/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "network/Server.hpp"

int main() {
    try
    {
        boost::asio::io_context io_context;
        rtype::network::Server(io_context, 4242);
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
