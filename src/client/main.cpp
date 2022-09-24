/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "network/client.hpp"

int main()
{
    boost::asio::io_service io_service;
    UDPClient client(io_service, "localhost", "4242");
    std::string message;

  while (message != "quit") {
    message.clear();
    std::cout << "message = ";
	  std::getline(std::cin >> std::ws, message);
    client.send(message);
    io_service.run_one();
  }
}
