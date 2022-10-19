/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "network/Server.hpp"
#include "network/SafeQueue.hpp"

int main() {
    try
    {
        boost::asio::io_context io_context;
        Server server(io_context, 4242);
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
