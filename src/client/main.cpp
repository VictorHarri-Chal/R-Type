/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "game/Game.hpp"

int main(int argc, char **argv)
{
  try {
        rtype::Game Game(60);

        if ((argc == 2) && (strcmp(argv[1], "-g") == 0))
            Game.init("-g");
        else
            Game.init("");
        Game.run();
        Game.destroy();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
