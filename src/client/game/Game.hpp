/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Game.hpp
*/

#pragma once

#include "../events/Events.hpp"
#include "../screens/intro/IntroScreen.hpp"
#include "../screens/menu/MenuScreen.hpp"
#include "../screens/htp/HtpScreen.hpp"
#include "../screens/options/OptionsScreen.hpp"
#include "../screens/multiplayer/MultiplayerScreen.hpp"
#include "../screens/room/RoomScreen.hpp"
#include "../screens/core/CoreScreen.hpp"
#include "../screens/solo/SoloScreen.hpp"
#include "../network/Client.hpp"

namespace rtype
{
    /// @brief Game class
    class Game {
      public:
        /// @brief enum containing all navigable screens
        enum class Screens { Intro = 1, Menu, Htp, Options, Multiplayer, Room, Core, Solo, Count };
        /// @brief Constructor
        /// @param baseFps base fps (60 by default)
        Game(size_t baseFps = 60);
        /// @brief Destructor
        ~Game();
        /// @brief Initialize the game class elements
        /// @param flag launch flag
        void init(std::string flag);
        /// @brief Run the game class
        void run(void);
        /// @brief Update game elements
        /// @param gameEngine Game engine
        void update(rtype::Game *gameEngine);
        /// @brief Process events
        /// @param gameEngine Game engine
        /// @return true Event has been executed
        /// @return false Event hasn't been executed
        bool processEvents(rtype::Game *gameEngine);
        /// @brief Handle the events
        /// @param gameEngine Game engine
        /// @return int The scene number
        int handleEvent(rtype::Game *gameEngine);
        /**
         * @brief Destroy all
         *
         */
        void destroy();

        /// @brief Swap between screens
        /// @param ret Scene number
        void handleScreensSwap(int ret);
        /// @brief Destroy last active scene
        void destroyLastScene();
        /// @brief Set the actual screen
        /// @param newScreen The new screen
        void setActualScreen(Screens newScreen);

        /// @brief Game client
        Client *_client;

        /// @brief Game window
        sf::RenderWindow _window;

        /// @brief Class type
        rtype::ecs::component::shipType _classType;

      private:
        /// @brief Actual screen
        Screens _actualScreen;
        /// @brief Game fps
        size_t _fps;
        /// @brief Local clock
        sf::Clock _clock;
        /// @brief Intro screen
        rtype::menu::IntroScreen *_intro;
        /// @brief Menu screen
        rtype::menu::MenuScreen *_menu;
        /// @brief Htp screen
        rtype::menu::HtpScreen *_htp;
        /// @brief Options screen
        rtype::menu::OptionsScreen *_options;
        /// @brief Multiplayer screen
        rtype::menu::MultiplayerScreen *_multiplayer;
        /// @brief Room screen
        rtype::menu::RoomScreen *_room;
        /// @brief Core screen
        rtype::menu::CoreScreen *_core;
        /// @brief Solo screen
        rtype::menu::SoloScreen *_solo;
        /// @brief Last sfml evecaught
        sf::Event _sfmlEvent;
        /// @brief Event class
        rtype::Event _event;
        /// @brief Last active scene
        Screens _lastScene;
        boost::asio::io_service _ioService;
        /// @brief Event class
        Events _eventClass;
    };
}
