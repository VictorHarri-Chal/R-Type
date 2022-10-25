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
            class Zigzag : public AShip {
              public:
                Zigzag(bool dirHor = false, bool dirVer = false, int currWave = 1);
                ~Zigzag() = default;

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;

              protected:
              private:                
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype