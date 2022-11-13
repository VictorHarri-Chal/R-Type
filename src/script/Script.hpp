/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Script.hpp
*/

#pragma once

#include "../sfml/Sfml.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

namespace rtype
{
    /// \file Docs/how_to_use_script.md
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
        Script() = default;
        /**
         * @brief Construct a new Script object with a custom difficulty
         *
         */
        Script(bool difficulty);
        /**
         * @brief Destroy the Script object
         *
         */
        ~Script() = default;
        /**
        * @brief Getter for the current clock.
        *
        * @return sf::Clock The current clock.
        */
        sf::Clock getClock() const;
        /**
        * @brief Restart the current clock.
        *
        */
       void restartClock();
        /**
        * @brief Set the current sprite to "printed".
        * 
        * @param wave Index of the wave.
        * @param i Index of the sprite to set.
        *
        */
        void spriteIsPrinted(int wave, size_t i);
        /**
        * @brief Getter for the script parsed vector.
        * 
        * @param wave Index of the wave.
        * 
        * @return std::vector<std::vector<int> The script parsed vector.
        *
        */
        std::vector<std::vector<int>> getWave(int wave) const;
        /**
        * @brief Parse the script to define ennemy spawning
        *
        */
        void parseScript(bool difficulty);
        /**
        * @brief Getter for the script parsed vector.
        * 
        * @return std::vector<std::vector<int> The script parsed vector.
        *
        */
        std::vector<std::vector<int>> getLines() const;
        /**
        * @brief Parse the script to define ennemy spawning
        *
        */
        void parseScriptOld();
        /**
        * @brief Set the current sprite to "printed".
        * 
        * @param i Index of the sprite to set.
        *
        */
        void spriteIsPrintedOld(size_t i);
        private:
            std::vector<std::vector<int>> _waveOne;
            std::vector<std::vector<int>> _waveTwo;
            std::vector<std::vector<int>> _waveThree;
            std::vector<std::vector<int>> _waveFour;
            std::vector<std::vector<int>> _waveFive;
            std::vector<std::vector<int>> _waveSix;
            std::vector<std::vector<int>> _waveSeven;
            std::vector<std::vector<int>> _waveEight;
            std::vector<std::vector<int>> _waveNine;
            std::vector<std::vector<int>> _waveTen;
            std::vector<std::vector<int>> _lines;
            sf::Clock _clock;

    };
}
