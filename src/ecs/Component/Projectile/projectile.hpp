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
                Projectile(bool origin);
                ~Projectile();

                rtype::ecs::component::compoType getType() const;
                bool getProjectileType() const;


              private:
                /// @brief True if allies, false if enemies
                bool _type;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !PROJECTILE_HPP_ */
