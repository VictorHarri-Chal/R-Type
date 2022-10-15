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
        class CoreScreen : public IScreen {
          public:
            /**
             * @brief Construct a new Menu Screen object
             * 
             */
            CoreScreen();
            /**
             * @brief Destroy the Menu Screen object
             * 
             */
            ~CoreScreen() = default;
            /**
             * @brief Init the Menu Screen
             * 
             */
            void init() override;
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
            int handleEvent(rtype::Event &event, rtype::Game *gameEngine) override;
            
            bool isButtonPressed(size_t index, rtype::Game *gameEngine, rtype::Event &event) override;

            bool isMouseOnButton(size_t index, rtype::Game *gameEngine, rtype::Event &event) override;

            void managePlayerMovement(rtype::Event &event, rtype::Game *gameEngine);

            void managePlayerShot(rtype::Event &event, rtype::Game *gameEngine);

            void destroySprites(rtype::Event &event, rtype::Game *gameEngine);

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
            *  @brief Clock for shot delay
            *
            */
            sf::Clock _clock;

        };
    }
}