/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** main
*/

#include "game/Game.hpp"
#include "../exceptions/Exceptions.hpp"
#include "../exceptions/EcsExceptions.hpp"
#include "../exceptions/GameExceptions.hpp"
#include "../exceptions/ScreensExceptions.hpp"

int main(int argc, char **argv)
{
  try {
        // sf::Music music;
        // if (!music.openFromFile("assets/music.ogg"))
        //     throw GameExceptions("Game init: Error while loading the music");
        // music.play();
        // music.setLoop(true);
        rtype::Game Game(60);

        if ((argc == 2) && (strcmp(argv[1], "-g") == 0))
            Game.init("-g");
        else if ((argc == 2) && (strcmp(argv[1], "-w") == 0))
            Game.init("-w");
        else if ((argc == 2) && (strcmp(argv[1], "-gw") == 0))
            Game.init("-gw");
        else
            Game.init("");
        Game.run();
        Game.destroy();
    } catch (EcsExceptions &e) {
        std::cerr << "Ecs Exception -> " << e.what() << std::endl;
    } catch (GameExceptions &e) {
        std::cerr << "Game Exception -> " << e.what() << std::endl;
    } catch (ScreensExceptions &e) {
        std::cerr << "Screen Exception -> " << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Global Exception -> " << e.what() << std::endl;
    }
    return 0;
}
