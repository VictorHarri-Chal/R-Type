/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MenuScreen.hpp
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
        class MenuScreen : public IScreen {
          public:
            /**
             * @brief Construct a new Menu Screen object
             *
             */
            MenuScreen();
            /**
             * @brief Destroy the Menu Screen object
             *
             */
            ~MenuScreen() = default;
            /**
             * @brief Init the Menu Screen
             *
             */
            void init() override;
            /**
             * @brief Update the Menu Screen
             * @param gameEngine Game engine
             */
            void update(rtype::Game *gameEngine) override;
            /**
             * @brief Handle event for the Menu Screen
             *
             * @param event Event to be handled
             * @param gameEngine Game engine
             * @return int The Scene Number
             */
            int handleEvent(rtype::Event &event, rtype::Game *gameEngine) override;
            /**
            * @brief Check if button is pressed
            * 
            * @param index Index of the button
            * @param gameEngine Game engine
            * @param event Event to be handled
            * @return true If button is pressed
            * @return false If button is not pressed
            */
            bool isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event) override;
            /**
            * @brief Check if mouse is on button
            * 
            * @param index Index of the button
            * @param gameEngine Game engine
            * @param event Event to be handled
            * @return true If mouse is on button
            * @return false If mouse is not on button
            */
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
