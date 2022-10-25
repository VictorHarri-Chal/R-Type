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

int main()
{
  try {
        rtype::Game Game(60);

        Game.init();
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
