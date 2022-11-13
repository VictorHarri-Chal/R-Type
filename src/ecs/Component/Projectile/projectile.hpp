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
                 * @param damage Damage of the projectile
                 * @param isPoweredUp Is the projectile powered up
                 */
                Projectile(rtype::ecs::component::projectileType type, float damage, bool isPoweredUp);
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
                /**
                 * @brief Getter for the current ship damage.
                 *
                 * @return The damage per shot.
                 */
                float getDamage() const;
                /**
                 * @brief Setter to set new damage per shot.
                 * 
                 * @param damage The new damage per shot.
                 *
                 */
                void setDamage(float damage);
                /**
                 * @brief Get if the projectile powered up.
                 *
                 * @return value.
                 */
                bool getIsPoweredUp() const;
                /**
                 * @brief Setter to set if the projectile is powered up.
                 * 
                 * @param isPoweredUp value.
                 *
                 */
                void setIsPoweredUp(bool isPoweredUp);


              private:
                /**
                 * @brief Type of the projectile
                 * 
                 */
                rtype::ecs::component::projectileType _projectileType;
                /**
                 * @brief Damage of the projectile
                 * 
                 */
                float _damage;
                /**
                 * @brief Is shot powered up ?
                 * 
                 */
                bool _isPoweredUp;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !PROJECTILE_HPP_ */
