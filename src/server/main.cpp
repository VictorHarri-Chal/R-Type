/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <string>
#include "network/server.hpp"
#include "network/game_data.hpp"

int main()
{
  // try
  // {
    // boost::asio::io_service io_service;
    // udp_server server(io_service, 4242);


    // data.serialize(std::cout, data, 0);

  //   std::cout << "server started" << std::endl;
  //   io_service.run();
  //   std::cout << "server stopped" << std::endl;
  // }
  // catch (std::exception& e)
  // {
  //   std::cerr << e.what() << std::endl;
  // }
  network::GameData data(network::JOIN, 5, "hello");

  std::ofstream ofile("test.txt");
  boost::archive::text_oarchive oTextArchive(ofile);
  oTextArchive << data;

  return 0;
}
