/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** IShip.hpp
*/

#pragma once
#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Transform;
            /**
             * @brief Enum for ship type
             * @param RECRUIT Basic ally ship
             * @param SNIPER Class 1 ally ship
             * @param TANK Class 2 ally ship
             * @param STEALTY Class 3 ally ship
             * @param SUPPORT Class 4 ally ship
             * @param ZIGZAG Type 1 enemy ship
             * @param RUSHER Type 2 enemy ship
             * @param TURRET Type 3 enemy ship
             * @param KAMIKAZE Type 4 enemy ship
             */
            enum shipType { RECRUIT,
                            SNIPER,
                            TANK,
                            STEALTY,
                            SUPPORT,
                            ZIGZAG,
                            RUSHER,
                            TURRET,
                            KAMIKAZE,
                            UNKNOWNSHIP
                        };

            /// @brief Component interface
            class IShip : public IComponent {
              public:
                /**
                 * @brief  Virtual destructor of IShip.
                 */
                virtual ~IShip() = default;

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
                virtual bool getDirectionHorizontal() const = 0;
                /**
                 * @brief Getter for the current vertical direction.
                 *
                 * @return True if going right, False if going left.
                 */
                virtual bool getDirectionVertical() const = 0;
                /**
                 * @brief Setter for the current horizontal direction.
                 *
                 */
                virtual void setDirectionHorizontal(bool dir) = 0;
                /**
                 * @brief Setter for the current vertical direction.
                 *
                 */
                virtual void setDirectionVertical(bool dir) = 0;
                /**
                 * @brief Getter for the current ship life points.
                 *
                 * @return The health amount.
                 */
                virtual float getHealth() const = 0;
                /**
                 * @brief Setter to set new health points.
                 *
                 */
                virtual void setHealth(float health) = 0;
                /**
                 * @brief Getter for the current ship damage.
                 *
                 * @return The damage per shot.
                 */
                virtual float getDamage() const = 0;
                /**
                 * @brief Setter to set new damage per shot.
                 *
                 */
                virtual void setDamage(float damage) = 0;
                /**
                 * @brief Getter for the current ship speed.
                 *
                 * @return The speed value.
                 */
                virtual float getSpeed() const = 0;
                /**
                 * @brief Setter to set new speed value.
                 *
                 */
                virtual void setSpeed(float speed) = 0;
                /**
                 * @brief Getter for the current ship shot cadency.
                 *
                 * @return The time between each shot.
                 */
                virtual sf::Time getCadency() const = 0;
                /**
                 * @brief Setter to set new shot cadency.
                 *
                 */
                virtual void setCadency(sf::Time cadency) = 0;
                /**
                 * @brief Getter for the current clock.
                 *
                 */
                virtual sf::Clock getClock() const = 0;
                /**
                 * @brief Restart the current clock.
                 *
                 */
                virtual void restartClock() = 0;
              protected:
            };
        }
    }
}
