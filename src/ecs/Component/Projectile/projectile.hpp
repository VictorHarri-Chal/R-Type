/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** projectile.hpp
*/

#ifndef PROJECTILE_HPP_
#define PROJECTILE_HPP_

#pragma once

#include <chrono>
#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Projectile : public IComponent {
              public:
                Projectile(rtype::ecs::component::projectileType type);
                ~Projectile();

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::projectileType getProjectileType() const;

              private:
                /// @brief True if allies, false if enemies
                rtype::ecs::component::projectileType _projectileType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !PROJECTILE_HPP_ */
