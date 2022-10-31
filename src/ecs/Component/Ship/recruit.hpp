/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** recruit.hpp
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
             * @brief Recruit component
             *
             */
            class Recruit : public AShip {
              public:
                /**
                 * @brief Construct a new Recruit object
                 * 
                 */
                Recruit();
                /**
                 * @brief Destroy the Recruit object
                 * 
                 */
                ~Recruit() = default;
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