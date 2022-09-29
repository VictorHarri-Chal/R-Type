/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <string>
// #include "network/buffer/ClientBuffer.hpp"
#include "network/Client.hpp"

int main()
{
  boost::asio::io_service io_service;
  Client client(io_service, "localhost", "4242");
  std::string message;

  ClientPayload data = {
    1,
    11,
    "helloWorld",
  };
  // ClientBuffer gameData(data);

  while (message != "quit") {
    message.clear();
    std::cout << "message = ";
	  std::getline(std::cin >> std::ws, message);
    client.send(data);
    // client.send(message);
    io_service.run_one();
  }
  return 0;
}
