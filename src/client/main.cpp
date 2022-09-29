/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "network/client.hpp"
#include "game/Game.hpp"

// int main()
// {
//     boost::asio::io_service io_service;
//     UDPClient client(io_service, "localhost", "4242");
//     std::string message;

//   while (message != "quit") {
//     message.clear();
//     std::cout << "message = ";
// 	  std::getline(std::cin >> std::ws, message);
//     client.send(message);
//     io_service.run_one();
//   }
// }

int main()
{
  try {
        rtype::Game Game(60);

        Game.init();
        Game.run();
        Game.destroy();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}