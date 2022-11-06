#pragma once
#include <map>
#include <memory>
#include <vector>

#include "../IScreen.hpp"
#include "../../../ecs/world.hpp"
#include "../../script/Script.hpp"

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
             * @param gameEngine Game engine
             * 
             */
            void update(rtype::Game *gameEngine) override;
            /**
             * @brief Handle event for the Core Screen
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
            * @brief Init the player number
            *
            */
            void initPlayerNumber(rtype::Game *gameEngine);
            /**
            * @brief Handle all function for the player
            * 
            * @param entityId Id of the player in the _world
            * @param event Event to be handled
            * @param gameEngine Game engine
            */
            void managePlayer(size_t entityId, rtype::Event &event, rtype::Game *gameEngine);
            /**
            * @brief Handle the player movement depending of the event
            * 
            * @param transformCompo Component transform of the player
            * @param shipCompo Component ship of the player
            * @param event Event to be handled
            * @param gameEngine Game engine
            */
            void managePlayerMovement(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event, rtype::Game *gameEngine);
            /**
            * @brief Handle the player shooting depending of the event
            * 
            * @param transformCompo Component transform of the player
            * @param shipCompo Component ship of the player
            * @param event Event to be handled
            * @param gameEngine Game engine
            */
            void managePlayerShot(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event, rtype::Game *gameEngine);
            /**
            * @brief Destroy sprites who goes out of the screen
            * 
            */
            void destroySprites(void);
            /**
            * @brief Handle automatic shooting for all enemies
            * 
            */
            void manageEnemiesShooting(void);
            /**
            * @brief Generic function to create an enemy
            * 
            * @param shipType Type of the enemy
            * @param dirHor Boolean to know if the enemy is horizontal
            * @param dirVer Boolean to know if the enemy is vertical
            * @param currWave Current wave of the game
            * @param x X position of the enemy
            * @param y Y position of the enemy
            */
            void generateEnemy(int currWave, int shipType, bool dirHor, bool dirVer, float x, float y);
            /**
            * @brief Spawn enemies depending on the script
            * 
            */
           void spawnEnemiesFromScript(void);
           /**
            * @brief Return wave duration based on current wave nbr
            * 
            */
           sf::Time getWaveDuration(void);
           /**
            * @brief Print on the middle of the screen the wave number.
            * 
            */
           void printWaveNumber(void);
            /**
            * @brief Handle player position when he is out of the screen
            * 
            */
            void handleWindowBorder(void);
            /**
            * @brief Create a particle sprite when called
            * 
            * @param x Position x
            * @param y Position y
            */
            void createParticle(float x, float y);

          private:
            /**
             * @brief World object will contain all the entities and system
             * 
             */
            rtype::ecs::world::World _world;
            /**
             * @brief Script object to make enemies spawn
             * 
             */
            rtype::Script _script;
            /**
             * @brief Store which ship does this client control
             *
             */
            rtype::ecs::entity::entityType _playerNumber;
            /**
             * @brief Check if the player number is initialised
             *
             */
            bool _isPlayerNumInit;
            /**
             * @brief Current wave in game
             * 
             */
            int _currWave;
            void updateEntities(rtype::Game *gameEngine);
        };
    }
}