/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** boss.hpp
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
             * @brief Boss component
             *
             */
            class Boss : public AShip {
              public:
                /**
                 * @brief Construct a new Boss object
                 * 
                 * @param currWave Current wave
                 */
                Boss(int currWave = 5);
                /**
                 * @brief Destroy the Boss object
                 * 
                 */
                ~Boss() = default;
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