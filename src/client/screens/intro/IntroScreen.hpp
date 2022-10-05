/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** IntroScreen.hpp
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
        class IntroScreen : public IScreen {
          public:
            /**
             * @brief Construct a new Menu Screen object
             * 
             */
            IntroScreen();
            /**
             * @brief Destroy the Menu Screen object
             * 
             */
            ~IntroScreen() = default;
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
            
            bool isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event);

            bool isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event);

            bool isSurfaceClicked(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine);

            bool isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine);

            void hooverOnButton(rtype::Event &event, rtype::Game *gameEngine);

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
