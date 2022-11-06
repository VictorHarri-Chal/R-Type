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
{
    class Game {
        public:
        /**
         * @brief Construct a new Core Screen object
         *
         */
        Game();
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
         * @brief Update for the server loop
         *
         */
        void update();

        rtype::ecs::world::World *getWorld() const { return _world; };

        private:
        /**
         * @brief World object will contain all the entities and system
         *
         */
        rtype::ecs::world::World *_world;
    };
}
