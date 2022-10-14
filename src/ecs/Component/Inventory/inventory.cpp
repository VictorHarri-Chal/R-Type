/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Inventory.cpp
*/

#include "inventory.hpp"

rtype::ecs::component::Inventory::Inventory()
{
}

rtype::ecs::component::Inventory::~Inventory()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Inventory::getType() const
{
    return (rtype::ecs::component::compoType::INVENTORY);
}

void rtype::ecs::component::Inventory::setBonus(rtype::ecs::component::bonusType type)
{
    (void) type;
}
