/*
** EPITECH PROJECT, 2022
** Destroyable (COMPONENT)
** File description:
** Destroyable (COMPONENT)
*/

#include "Destroyable.hpp"

rtype::ecs::component::Destroyable::Destroyable()
{
}

rtype::ecs::component::Destroyable::~Destroyable()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Destroyable::getType() const
{
    return (rtype::ecs::component::compoType::DESTROYABLE);
}
