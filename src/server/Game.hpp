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
        void initPlayersEntities();
        /**
         * @brief Update for the server loop
         *
         */
        void update();
        int handleEvents(std::string direction, size_t playerId);
        void createShoot(size_t playerId);

        void run();
        rtype::ecs::world::World *getWorld() const { return _world; };
        void destroySprites(void);
        private:
        /**
         * @brief World object will contain all the entities and system
         *
         */
        // rtype::ecs::world::World _world;

        /// @brief Clock
        sf::Clock _clock;

        // Server *_server;

        size_t _nbPlayers;
        rtype::ecs::world::World *_world;
        // Server *_server;
    };
}
