/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Tools.cpp
*/

#include "Tools.hpp"

float rtype::Tools::getPercentage(float percent, bool isWidth, rtype::Game *gameEngine)
{
    sf::Vector2u size = gameEngine->_window.getSize();
    float windowDim = isWidth ? static_cast<float>(size.x)
                              : static_cast<float>(size.y);

    return (windowDim * percent / 100.f);
}
