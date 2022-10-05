/*
** EPITECH PROJECT, 2022
** Inventory (COMPONENT)
** File description:
** Inventory (COMPONENT)
*/

#include "Inventory.hpp"

rtype::ecs::component::Inventory::Inventory()
{
    this->_bombUp = false;
    this->_fireUp = false;
    this->_speedUp = false;
    this->_wallPass = false;
}

rtype::ecs::component::Inventory::~Inventory()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Inventory::getType() const
{
    return (rtype::ecs::component::compoType::INVENTORY);
}

bool rtype::ecs::component::Inventory::getBombUp() const
{
    return (this->_bombUp);
}

bool rtype::ecs::component::Inventory::getFireUp() const
{
    return (this->_fireUp);
}

bool rtype::ecs::component::Inventory::getSpeedUp() const
{
    return (this->_speedUp);
}

bool rtype::ecs::component::Inventory::getWallPass() const
{
    return (this->_wallPass);
}

void rtype::ecs::component::Inventory::setBombUp(bool bonus)
{
    this->_bombUp = bonus;
}

void rtype::ecs::component::Inventory::setFireUp(bool bonus)
{
    this->_fireUp = bonus;
}

void rtype::ecs::component::Inventory::setSpeedUp(bool bonus)
{
    this->_speedUp = bonus;
}

void rtype::ecs::component::Inventory::setWallPass(bool bonus)
{
    this->_wallPass = bonus;
}

void rtype::ecs::component::Inventory::setBonus(rtype::ecs::component::bonusType type)
{

}
