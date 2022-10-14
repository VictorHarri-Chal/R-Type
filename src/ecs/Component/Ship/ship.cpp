/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** ship.cpp
*/

#include "ship.hpp"

rtype::ecs::component::Ship::Ship(rtype::ecs::component::shipType type)
{
    this->_shipType = type;
    if (_shipType == rtype::ecs::component::shipType::ZIGZAG) {
        _directionHorizontal = false;
        _directionVertical = false;
    }
}

rtype::ecs::component::Ship::~Ship()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Ship::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

rtype::ecs::component::shipType rtype::ecs::component::Ship::getShipType() const
{
    return (this->_shipType);
}

bool rtype::ecs::component::Ship::getDirectionHorizontal() const
{
    return this->_directionHorizontal;
}

bool rtype::ecs::component::Ship::getDirectionVertical() const
{
    return this->_directionVertical;
}

void rtype::ecs::component::Ship::setDirectionHorizontal(bool dir)
{
    _directionHorizontal = dir;
}

void rtype::ecs::component::Ship::setDirectionVertical(bool dir)
{
    _directionVertical = dir;
}