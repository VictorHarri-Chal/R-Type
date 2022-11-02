/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** rusher.hpp
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
             * @brief Rusher component
             *
             */
            class Rusher : public AShip {
              public:
                /**
                 * @brief Construct a new Rusher object
                 * 
                 * @param currWave Current wave
                 */
                Rusher(int currWave = 1);
                /**
                 * @brief Destroy the Rusher object
                 * 
                 */
                ~Rusher() = default;
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