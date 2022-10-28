/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** kamikaze.hpp
*/

#pragma once

#include "AShip.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Kamikaze : public AShip {
              public:
                Kamikaze(int currWave = 1);
                ~Kamikaze() = default;

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;

              protected:
              private:                
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype