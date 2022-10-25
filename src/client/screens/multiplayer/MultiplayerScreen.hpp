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
         * @brief Class for the Multiplayer Screen
         *
         */
        class MultiplayerScreen : public IScreen {
          public:
            /**
             * @brief Room struct
             * 
             * @param id Room id
             * @param slot Room slot
             * @param name Room name
             * @param currPlayers Room current players
             * @param isOpen Boolean if room is open
             * 
             */
            struct room_t {
                /**
                 * @brief Room id
                 * 
                 */
                int id;
                /**
                 * @brief Room slot
                 * 
                 */
                int slot;
                /**
                 * @brief Room name
                 * 
                 */
                std::string name;
                /**
                 * @brief Room current players
                 * 
                 */
                unsigned int currPlayers;
                /**
                 * @brief Boolean if room is open
                 * 
                 */
                bool isOpen;
            };
            /**
             * @brief Construct a new Multiplayer Screen object
             *
             */
            MultiplayerScreen();
            /**
             * @brief Destroy the Multiplayer Screen object
             *
             */
            ~MultiplayerScreen() = default;
            /**
             * @brief Init the Multiplayer Screen
             *
             */
            void init() override;
            /**
             * @brief Update the Multiplayer Screen
             * @param gameEngine Game engine
             */
            void update(rtype::Game *gameEngine) override;
            /**
             * @brief Handle event for the Multiplayer Screen
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
             * @brief Add room to the list
             * 
             * @param slot Number of slots
             * @return int The room id
             */
            int addRoom(float slot);
            /**
             * @brief Check for free slot in the room
             * 
             * @return float The free slot
             */
            float checkForFreeSlot();
            /**
             * @brief Create a Room 
             * 
             * @param event Event to be handled
             * @param gameEngine Game engine
             */
            void createRoom(rtype::Event &event, rtype::Game *gameEngine);

            bool joinRoom(int slotPos, float offset, rtype::Event &event, rtype::Game *gameEngine);

            /**
             * @brief Delete a Room
             * 
             * @param slotPos Position of the slot
             * @param offset Offset of the slot
             * @param event Event to be handled
             * @param gameEngine Game engine
             */
            void deleteRoom(int slotPos, float offset, rtype::Event &event, rtype::Game *gameEngine);
            /**
             * @brief Check if room is hovered
             * 
             * @param event Event to be handled
             * @param gameEngine Game engine
             */
            void hooverOnButton(rtype::Event &event, rtype::Game *gameEngine);

          private:
            void initRoom(rtype::Event &event, rtype::Game *gameEngine);
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
            size_t _actualNbRooms;
            bool _roomInit;
        };
    }
}
