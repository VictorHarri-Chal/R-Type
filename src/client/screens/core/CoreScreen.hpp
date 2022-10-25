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
         * @brief Class for the Core Screen
         * 
         */
        class CoreScreen : public IScreen {
          public:
            /**
             * @brief Construct a new Core Screen object
             * 
             */
            CoreScreen();
            /**
             * @brief Destroy the Core Screen object
             * 
             */
            ~CoreScreen() = default;
            /**
             * @brief Init the Core Screen
             * 
             */
            void init() override;
            /**
             * @brief Update the Core Screen
             * 
             */
            void update(rtype::Game *gameEngine) override;
            /**
             * @brief Handle event for the Core Screen
             * 
             * @param event Event to be handled
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

            void managePlayer(size_t entityId, rtype::Event &event);

            void managePlayerMovement(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event);

            void managePlayerShot(ecs::component::IShip *shipCompo, rtype::Event &event);

            void destroySprites(rtype::Event &event, rtype::Game *gameEngine);

            void manageEnemiesShooting(void);

            void generateEnemy(rtype::ecs::component::shipType shipType, bool dirHor, bool dirVer, int currWave, float x, float y, 
              std::string asset, bool isRect, sf::Vector2f scale, int rotation, sf::IntRect rect);

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
            *  @brief Clock for ally shot delay
            *
            */
            sf::Clock _clockAllyShot;
            /**
            *  @brief Clock for enemy shot delay
            *
            */
            sf::Clock _clockEnemyShot;

        };
    }
}