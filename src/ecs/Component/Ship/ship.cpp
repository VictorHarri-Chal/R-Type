/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** ship.cpp
*/

#include "ship.hpp"

rtype::ecs::component::Ship::Ship(bool type)
{
    this->_type = type;
}

rtype::ecs::component::Ship::~Ship()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Ship::getType() const
{
    return (rtype::ecs::component::compoType::SHIP);
}

bool rtype::ecs::component::Ship::getShipType() const
{
    return this->_type;
}
