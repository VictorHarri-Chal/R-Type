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
            class Rusher : public AShip {
              public:
                Rusher(int currWave = 1);
                ~Rusher() = default;

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;

              protected:
              private:                
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype