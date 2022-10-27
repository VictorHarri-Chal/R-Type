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
            /// @brief Component interface
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
                 * @return the shipType value of the component.
                 */
                virtual rtype::ecs::component::shipType getShipType() const = 0;
                /**
                 * @brief Getter for the current horizontal direction.
                 *
                 * @return True if going down, False if going up.
                 */
                bool getDirectionHorizontal() const;
                /**
                 * @brief Getter for the current vertical direction.
                 *
                 * @return True if going right, False if going left.
                 */
                bool getDirectionVertical() const;
                /**
                 * @brief Setter for the current horizontal direction.
                 *
                 */
                void setDirectionHorizontal(bool dir);
                /**
                 * @brief Setter for the current vertical direction.
                 *
                 */
                void setDirectionVertical(bool dir);
                /**
                 * @brief Getter for the current ship life points.
                 *
                 * @return The health amount.
                 */
                float getHealth() const;
                /**
                 * @brief Setter to set new health points.
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
                 */
                void setCadency(sf::Time cadency);
                /**
                 * @brief Getter for the current clock.
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