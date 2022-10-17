/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Tools.hpp
*/

#pragma once

#include "../../sfml/Sfml.hpp"
#include "../game/Game.hpp"

namespace rtype
{
    /**
     * @brief Class for some useful tools
     *
     */
    class Tools {
      public:
        /**
         * @brief Construct a new Tools object
         *
         */
        Tools();
        /**
         * @brief Destroy the Tools object
         *
         */
        ~Tools();
        /**
        * @brief Get the position of the center (for alignement)
        *
        * @param percent Percentage for alignement
        * @param isWidth True for width, False for height
        * @return float Position of the center alignement
        */
        static float getPercentage(float percent, bool isWidth, rtype::Game *gameEngine);

    };
}
