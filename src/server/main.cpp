/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include <iostream>
#include <string>
#include "network/server.hpp"

int main()
{
  try
  {
    boost::asio::io_service io_service;
    udp_server server(io_service);
    std::cout << "server started" << std::endl;
    io_service.run();
    std::cout << "server stopped" << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
