/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MultiplayerScreen.hpp
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
        class MultiplayerScreen : public IScreen {
          public:
            struct room_t {
                int id;
                int slot;
                std::string name;
                unsigned int currPlayers;
                bool isOpen;
            };
            /**
             * @brief Construct a new Menu Screen object
             *
             */
            MultiplayerScreen();
            /**
             * @brief Destroy the Menu Screen object
             *
             */
            ~MultiplayerScreen() = default;
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

            bool isSurfaceClicked(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine);

            bool isMouseOnSurface(float x, float y, float width, float height, rtype::Event &event, rtype::Game *gameEngine);

            int addRoom(float slot);

            float checkForFreeSlot();

            void createRoom(rtype::Event &event, rtype::Game *gameEngine);

            void deleteRoom(int slotPos, float offset, rtype::Event &event, rtype::Game *gameEngine);

            void hooverOnButton(rtype::Event &event, rtype::Game *gameEngine);

          private:
            /**
             * @brief World object will contain all the entities and system
             *
             */
            rtype::ecs::world::World _world;
            /**
             * @brief Vector to store all rooms infos
             *
             */
            std::vector<room_t> _rooms;
            /**
             * @brief Vector to check if the mouse is on a button
             *
             */
            std::vector<bool> _buttons;
            /**
             * @brief Vector to check if rooms slots are empty or not
             *
             */
            std::vector<bool> _slots;
            /**
             * @brief Int who is being incremented everytime a room is created
             *
             */
            int _roomId;

        };
    }
}
