/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** turret.hpp
*/

#pragma once

#include "AShip.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Turret : public AShip {
              public:
                Turret(int currWave = 1);
                ~Turret() = default;

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;

              protected:
              private:                
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype