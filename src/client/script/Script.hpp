/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Script.hpp
*/

#pragma once

#include "../../sfml/Sfml.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

namespace rtype
{
    /**
     * @brief Class for some useful Script
     *
     */
    class Script {
        public:
        /**
         * @brief Construct a new Script object
         *
         */
        Script();
        /**
         * @brief Destroy the Script object
         *
         */
        ~Script() = default;
        /**
        * @brief Getter for the current clock.
        *
        */
        sf::Clock getClock() const;
        /**
        * @brief Set the current sprite to "printed".
        *
        */
        void spriteIsPrinted(size_t i);
        /**
        * @brief Getter for the script parsed vector.
        *
        */
        std::vector<std::vector<int>> getLines() const;
        /**
        * @brief Parse the script to define ennemy spawning
        *
        */
        void parseScript();
        private:
            std::vector<std::vector<int>> _lines;
            sf::Clock _clock;

    };
}
