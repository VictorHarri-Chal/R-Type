#pragma once
#include <map>
#include <memory>
#include <vector>

#include "../IScreen.hpp"
#include "../../../ecs/world.hpp"
#include "../../../script/Script.hpp"

namespace rtype
{
    class Game;
    namespace menu
    {
        /**
         * @brief Class for the Core Screen
         * 
         */
        class SoloScreen : public IScreen {
          public:
            /**
             * @brief Construct a new Core Screen object
             * 
             */
            SoloScreen();
            /**
             * @brief Destroy the Core Screen object
             * 
             */
            ~SoloScreen() = default;
            /**
             * @brief Init the Core Screen
             * 
             */
            void init() override;
            /**
             * @brief Init the ally ship with the right class
             * 
             * @param gameEngine Game engine
             * 
             */
            void initAllyShip(rtype::Game *gameEngine);
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
            * @brief Handle all function for the player
            * 
            * @param entityId Id of the player in the _world
            * @param event Event to be handled
            */
            void managePlayer(size_t entityId, rtype::Event &event);
            /**
            * @brief Handle the player movement depending of the event
            * 
            * @param transformCompo Component transform of the player
            * @param shipCompo Component ship of the player
            * @param event Event to be handled
            */
            void managePlayerMovement(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event);
            /**
            * @brief Handle the player shooting depending of the event
            * 
            * @param transformCompo Component transform of the player
            * @param shipCompo Component ship of the player
            * @param event Event to be handled
            */
            void managePlayerShot(ecs::component::Transform *transformCompo, ecs::component::IShip *shipCompo, rtype::Event &event);
            /**
            * @brief Handle the player class skill
            * 
            * @param entityId Id of the player in the _world
            * @param shipCompo Component ship of the player
            * @param event Event to be handled
            */
            void manageSkill(size_t entityId, ecs::component::IShip *shipCompo, rtype::Event &event);
            /**
            * @brief Handle skill duration and end
            * 
            */
            void handleSkillEnd(void);
            /**
            * @brief Destroy sprites who goes out of the screen
            * 
            */
            void destroySprites(void);
            /**
            * @brief End screen on defeat or win
            * 
            */
            void manageGameEnd(void);
            /**
            * @brief Handle automatic shooting for all enemies
            * 
            */
            void manageEnemiesShooting(void);
            /**
            * @brief Generic function to create an enemy
            * 
            * @param shipType Type of the enemy
            * @param currWave Current wave of the game
            * @param x X position of the enemy
            * @param y Y position of the enemy
            */
            void generateEnemy(int currWave, int shipType, float x, float y);
            /**
            * @brief Spawn enemies depending on the script
            * 
            */
           void spawnEnemiesFromScript(void);
           /**
            * @brief Return wave duration based on current wave nbr
            * 
            * @return sf::Time Wave duration
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
            * @param scale Size of the particle
            * @param type 1 = death particle, 2 = hit particle from enemies, 3 = hit particle from allies
            */
            void createParticle(float x, float y, float scale, int type);
            /**
            * @brief Handle hud display
            * 
            */
            void handleHud(void);
            /**
            * @brief Create a collectable health bonus
            * 
            * @param x Position x
            * @param y Position y
            */
            void releaseHealthBonus(float x, float y);

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
             * @brief Current wave in game
             * 
             */
            int _currWave;
            /**
             * @brief Is the game ended ?
             * 
             */
            bool _isGameEnded;
            /**
             * @brief Boolean to init some things with the gameEngine
             * 
             */
            bool _condInit;
            /**
             * @brief Clock to read the script
             * 
             */
            sf::Clock _clockScriptCall;
            /**
             * @brief Clock for the skill duration
             * 
             */
            sf::Clock _clockSkillDuration;
            /**
             * @brief Clock for the skill cooldown
             * 
             */
            sf::Clock _clockSkillCooldown;

        };
    }
}