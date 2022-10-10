/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** OptionsScreen.hpp
*/

#pragma once
#include <map>
#include <memory>
#include <vector>

#include "../IScreen.hpp"
#include "../../../ecs/world.hpp"

namespace rtype
{
    class Game;
    namespace menu
    {
        /**
         * @brief Class for the Menu Screen
         *
         */
        class OptionsScreen : public IScreen {
          public:
            /**
             * @brief Cursor enum for the option choice (New game, Load game or exit game)
             *
             */
            enum cursorPosition { FULLSCREEN = 0,  FPS = 1, SOUND = 2 , DEVICE = 3, SAVE = 4, BACK = 5 };
            /**
             * @brief Construct a new Menu Screen object
             *
             */
            OptionsScreen();
            /**
             * @brief Destroy the Menu Screen object
             *
             */
            ~OptionsScreen() = default;
            /**
             * @brief Init the Menu Screen
             *
             */
            void init() override;
            /**
             * @brief Draw the Menu Screen
             *
             */
            void draw(rtype::Game *gameEngine) override;
            /**
             * @brief Update the Menu Screen
             *
             */
            void update() override;
            /**
             * @brief Handle event for the Menu Screen
             *
             * @param event Event to be handled
             * @return int The Scene Number
             */
            int handleEvent(rtype::Event &event, rtype::Game *gameEngine) override;

            bool isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event) override;

            bool isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event) override;

          private:
            /**
             * @brief World object will contain all the entities and system
             *
             */
            rtype::ecs::world::World _world;
            /**
             * @brief Vector to check if the mouse is on a button
             *
             */
            std::vector<bool> _buttons;
        };
    }
}
