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
            /**
             * @brief Projectile component
             *
             */
            class Projectile : public IComponent {
              public:
                /**
                 * @brief Construct a new Projectile object
                 *
                 * @param type Type of the projectile
                 */
                Projectile(rtype::ecs::component::projectileType type);
                /**
                 * @brief Destroy the Projectile object
                 *
                 */
                ~Projectile() = default;
                /**
                 * @brief Get the Type of the component
                 * 
                 * @return rtype::ecs::component::compoType Type of the component
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Type of the projectile
                 * 
                 * @return rtype::ecs::component::projectileType Type of the projectile
                 */
                rtype::ecs::component::projectileType getProjectileType() const;

              private:
                /**
                 * @brief Type of the projectile
                 * 
                 */
                rtype::ecs::component::projectileType _projectileType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !PROJECTILE_HPP_ */
