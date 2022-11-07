/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** AShip.hpp
*/

#pragma once
#include "IShip.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Class for the AShip component
             * 
             */
            class AShip : public IShip {
              public:
                /**
                 * @brief Virtual constructor of AShip.
                 */
                AShip() = default;
                /**
                 * @brief Virtual destructor of AShip.
                 */
                ~AShip() = default;
                /**
                 * @brief Get type of the ship.
                 *
                 * @return rtype::ecs::component::shipType the shipType value of the component.
                 */
                virtual rtype::ecs::component::shipType getShipType() const = 0;
                /**
                 * @brief Getter for the current ship life points.
                 *
                 * @return The health amount.
                 */
                float getHealth() const;
                /**
                 * @brief Setter to set new health points.
                 * 
                 * @param health The new health amount.
                 *
                 */
                void setHealth(float health);
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
                 * @brief Getter for the current ship speed.
                 *
                 * @return The speed value.
                 */
                float getSpeed() const;
                /**
                 * @brief Setter to set new speed value.
                 * 
                 * @param speed The new speed value.
                 *
                 */
                void setSpeed(float speed);
                /**
                 * @brief Getter for the current ship shot cadency.
                 *
                 * @return The time between each shot.
                 */
                sf::Time getCadency() const;
                /**
                 * @brief Setter to set new shot cadency.
                 * 
                 * @param cadency The new shot cadency.
                 *
                 */
                void setCadency(sf::Time cadency);
                /**
                 * @brief Getter for the current clock.
                 * 
                 * @return The current clock.
                 *
                 */
                sf::Clock getClock() const;
                /**
                 * @brief Restart the current clock.
                 *
                 */
                void restartClock();
              protected:
                /// @brief True if right, false if going left
                bool _directionHorizontal;

                /// @brief True if down, false if up
                bool _directionVertical;

                /// @brief Current life points
                float _health;
                
                /// @brief Current damage per shot
                float _damage;

                /// @brief Current ship speed
                float _speed;

                /// @brief Current shots cadency
                sf::Time _cadency;

                /// @brief Clock for the current object
                sf::Clock _clock;
            };
        }
    }
}