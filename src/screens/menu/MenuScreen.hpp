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
             * @brief Cursor enum for the option choice (New game, Load game or exit game)
             * 
             */
            enum cursorPosition { NEW_GAME = 0, LOAD_GAME = 1, EXIT = 2 };
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
             * @brief Draw the Menu Screen
             * 
             */
            void draw(rtype::Game *gameEngine) override;
            /**
             * @brief Update the Menu Screen
             * 
             */
            void update(rtype::Game *gameEngine) override;
            /**
             * @brief Handle event for the Menu Screen
             * 
             * @param event Event to be handled
             * @return int The Scene Number
             */
            int handleEvent(rtype::Event &event) override;
            /**
             * @brief Add entity for the Menu Screen
             * 
             * @param entity Entity to add for the Menu Screen
             */
            void addEntity(std::unique_ptr<rtype::ecs::entity::Entity> entity) override;
            /**
             * @brief Add system for the Menu Screen
             * 
             * @param system System to add for the Menu Screen
             */
            void addSystem(std::unique_ptr<rtype::ecs::system::ISystem> system) override;
            /**
             * @brief Set the size of the Menu Screen
             * 
             * @param where Position
             * @param height Height  
             * @param width Width
             */
            void setSize(int where, float height, float width);
            /**
             * @brief Check where the cursor is
             * 
             * @param direction True is UP and False is DOWN
             * @return int The index for the button
             */
            int checkCursorPosition(bool direction);

          private:
            /**
             * @brief Vector of entities for the Menu Screen
             * 
             */
            std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of systems for the Menu Screen
             * 
             */
            std::vector<std::unique_ptr<rtype::ecs::system::ISystem>> _systems;
            /**
             * @brief Map of positions of the cursor
             * 
             */
            std::map<int, float> _positionsCursor;
            /**
             * @brief Index of the cursor position
             * 
             */
            int _cursorPosition;
        };
    }
}
