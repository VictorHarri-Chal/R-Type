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
                 * @brief Create a new IShip.
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
              protected:
                /// @brief True if right, false if going left
                bool _directionHorizontal;

                /// @brief True if down, false if up
                bool _directionVertical;

                /// @brief Current life points
                float _health;
            };
        }
    }
}
