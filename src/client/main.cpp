/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "game/Game.hpp"
#include "network/client.hpp"

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
