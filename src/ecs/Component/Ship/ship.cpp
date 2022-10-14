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
