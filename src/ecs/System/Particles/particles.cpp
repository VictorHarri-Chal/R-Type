/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Particles.cpp
*/

#include "particles.hpp"
#include <cmath>


void rtype::ecs::system::Particles::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{

}

rtype::ecs::system::SystemType rtype::ecs::system::Particles::getSystemType() const
{
    return (rtype::ecs::system::SystemType::PARTICLESSYSTEM);
}