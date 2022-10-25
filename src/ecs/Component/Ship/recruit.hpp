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
            class Recruit : public AShip {
              public:
                Recruit();
                ~Recruit() = default;

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;

              protected:
              private:

            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype