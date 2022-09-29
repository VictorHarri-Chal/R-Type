/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <string>
#include "network/Server.hpp"

int main()
{
  try
  {
    boost::asio::io_service io_service;
    Server server(io_service, 4242);

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
