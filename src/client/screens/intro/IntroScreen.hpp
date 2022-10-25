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
         * @brief Class for the Intro Screen
         * 
         */
        class IntroScreen : public IScreen {
          public:
            /**
             * @brief Construct a new Intro Screen object
             * 
             */
            IntroScreen();
            /**
             * @brief Destroy the Intro Screen object
             * 
             */
            ~IntroScreen() = default;
            /**
             * @brief Init the Intro Screen
             * 
             */
            void init() override;
            /**
             * @brief Update the Intro Screen
             * @param gameEngine Game engine
             */
            void update(rtype::Game *gameEngine) override;
            /**
             * @brief Handle event for the Intro Screen
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
            /**
            * @brief Save the paralax assets x and y throught scenes
            * 
            */
            void saveParalax(void) override;
            /**
            * @brief Handle the background paralax
            * 
            */
            void paralax(void) override;
            /**
             * @brief Check if surface is clicked
             * 
             * @param x X position of the surface
             * @param y Y position of the surface
             * @param width Width of the surface
             * @param height Height of the surface
             * @param event Event to be handled
             * @param gameEngine Game engine
             * @return true If surface is clicked
             * @return false If surface is not clicked
             */
            bool isSurfaceClicked(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine);
            /**
             * @brief Check if surface is hovered
             * 
             * @param x X position of the surface
             * @param y Y position of the surface
             * @param width Width of the surface
             * @param height Height of the surface
             * @param event Event to be handled
             * @param gameEngine Game engine
             * @return true If surface is hovered
             * @return false If surface is not hovered
             */
            bool isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine);
            /**
             * @brief Check if hoover on button
             * 
             * @param event Event to be handled
             * @param gameEngine Game engine
             */
            void hooverOnButton(rtype::Event &event, rtype::Game *gameEngine);
            /**
             * @brief Check if isAlpha
             * 
             * @param event Event to be handled
             * @return true If isAlpha
             * @return false If is not Alpha
             */
            bool isAlpha(rtype::Event &event);
            /**
             * @brief Handle the player keyboard to fill the nickname
             * 
             * @param event Event to be handled
             */
            void handleNickname(rtype::Event &event);

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
            /**
             * @brief String for the name of the player
             * 
             */
            std::string _pseudo;
            /**
             * @brief Map to check if on writing frame
             * 
             */
            bool _onWritingFrame;
        };
    }
}
