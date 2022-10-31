/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** sniper.hpp
*/

#pragma once

#include "AShip.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Sniper component
             *
             */
            class Sniper : public AShip {
              public:
                /**
                 * @brief Construct a new Sniper object
                 * 
                 */
                Sniper();
                /**
                 * @brief Destroy the Sniper object
                 * 
                 */
                ~Sniper() = default;
                /**
                 * @brief Get the Type of the component
                 * 
                 * @return rtype::ecs::component::compoType Type of the component
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Ship Type of the component
                 * 
                 * @return rtype::ecs::component::shipType  Ship Type of the component
                 */
                rtype::ecs::component::shipType getShipType() const;

              protected:
              private:

            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype