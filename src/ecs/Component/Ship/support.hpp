/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** support.hpp
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
             * @brief Support component
             *
             */
            class Support : public AShip {
              public:
                /**
                 * @brief Construct a new Support object
                 * 
                 */
                Support();
                /**
                 * @brief Destroy the Support object
                 * 
                 */
                ~Support() = default;
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