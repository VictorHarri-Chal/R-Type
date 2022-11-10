/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Game.hpp
*/

#pragma once
#include <map>
#include <memory>
#include <vector>

#include "../ecs/world.hpp"
#include "network/Server.hpp"

namespace rtype
{    class Game {
        public:
        /**
         * @brief Construct a new Core Screen object
         * 
         * @param nbPlayers Number of players
         *
         */
        Game(size_t nbPlayers);
        /**
         * @brief Destroy the Core Screen object
         *
         */
        ~Game() = default;
        /**
         * @brief Init the Core Screen
         *
         */
        void init();
        /**
         * @brief Init Player's entities
         * 
         */
        void initPlayersEntities();
        /**
         * @brief Update for the server loop
         *
         */
        void update();
        int handleEvents(std::string direction, size_t playerId);
        void createShoot(size_t playerId);
        /**
         * @brief Handle event for the game
         *
         * @param direction Direction of the player
         * @param playerId Id of the player
         *
         */
        void handleEvents(std::string direction, size_t playerId);
        /**
         * @brief Run the game
         * 
         */
        void run();
        /**
         * @brief Get the World object
         * 
         * @return rtype::ecs::world::World* The world object 
         */
        rtype::ecs::world::World *getWorld() const { return _world; };
        void destroySprites(void);
        private:
        /**
         * @brief Clock for the game
         * 
         */
        sf::Clock _clock;
        // Server *_server;
        /**
         * @brief Number of players in the game
         * 
         */
        size_t _nbPlayers;
        /**
         * @brief World object for the game
         * 
         */
        rtype::ecs::world::World *_world;
        // Server *_server;
    };
}
