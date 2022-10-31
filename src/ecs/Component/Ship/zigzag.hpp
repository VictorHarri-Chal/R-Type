/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** zigzag.hpp
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
             * @brief Zigzag component
             *
             */
            class Zigzag : public AShip {
              public:
                /**
                 * @brief Construct a new Zigzag object
                 * 
                 * @param dirHor Boolean to define if the ship is moving horizontally or not
                 * @param dirVer Boolean to define if the ship is moving vertically or not
                 * @param currWave Current wave of the ship
                 */
                Zigzag(bool dirHor = false, bool dirVer = false, int currWave = 1);
                /**
                 * @brief Destroy the Zigzag object
                 * 
                 */
                ~Zigzag() = default;
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