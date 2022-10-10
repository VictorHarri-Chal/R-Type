/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Game.hpp
*/

#pragma once

#include "../events/Events.hpp"
#include "../screens/menu/MenuScreen.hpp"

namespace rtype
{
    /// @brief Game class
    class Game {
      public:
        /// @brief enum containing all navigable screens
        enum class Screens { Intro = 1, Menu, Options, Multiplayer, Game, Count };
        /// @brief enum containing all type of sounds
        enum Sounds {};
        /// @brief enum containing all musics
        enum Musics {};
        /// @brief Constructor
        /// @param baseFps base fps (60 by default)
        Game(size_t baseFps = 60);
        /// @brief Destructor
        ~Game();
        /// @brief Initialize the game class elements
        void init(void);
        /// @brief Run the game class
        void run(void);
        /// @brief Update game elements
        void update(rtype::Game *gameEngine);
        /// @brief Process events
        /// @return true Event has been executed
        /// @return false Event hasn't been executed
        bool processEvents(void);
        /// @brief Handle the events
        /// @return int The scene number
        int handleEvent();
        /// @brief Init all scenes
        void initScenes();
        /**
         * @brief Init all sounds
         *
         */
        void initSounds();
        /**
         * @brief Init all musics
         *
         */
        void initMusic();
        /**
         * @brief Destroy all
         *
         */
        void destroy();
        /**
         * @brief Destroy all entities
         *
         */
        // void destroyEntities();
        // /**
        //  * @brief Destroy systems
        //  *
        //  */
        // void destroySystems();

        /// @brief Swap between screens
        /// @param ret Scene number
        void handleScreensSwap(int ret);
        /// @brief Reinitialize the game class elements
        void reinitGame();
        /// @brief Set the actual screen
        /// @param newScreen The new screen
        void setActualScreen(Screens newScreen);
        /// @brief Tool for responsive
        /// @param percent The percent of the screen
        /// @param isWidth If true, the percent is for the width, else for the height
        float getPercentage(float percent, bool isWidth);
        
        // /**
        //  * @brief Set the Sound Event
        //  *
        //  * @param entititesIndex Index for entity
        //  */
        // void setSoundEvent(int entititesIndex);
        // /**
        //  * @brief Add sound entity
        //  *
        //  * @param entity Entity sound to add
        //  */
        // void addSoundEntity(std::unique_ptr<rtype::ecs::entity::Entity> entity);
        // /**
        //  * @brief Add sound system
        //  *
        //  * @param system System sound to add
        //  */
        // void addSoundSystem(std::unique_ptr<rtype::ecs::system::ISystem> system);
        /// @brief Game window
        sf::RenderWindow _window;
      private:
        /// @brief Actual screen
        Screens _actualScreen;
        /// @brief Game fps
        size_t _fps;
        /// @brief Players
        // std::vector<player::Player> _players;
        /// @brief Menu screen
        rtype::menu::MenuScreen *_menu;
        /// @brief Game screen
        // rtype::menu::GameScreen *_game;
        /// @brief Last sfml event caught
        sf::Event _sfmlEvent;
        /// @brief Event class
        rtype::Event _event;
        // std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> _sound_entities;
        // std::vector<std::unique_ptr<rtype::ecs::system::ISystem>> _sound_systems;
        // std::map<int, rtype::raylib::Sound> _musics;
    };
}
