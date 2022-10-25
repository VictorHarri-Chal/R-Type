/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** recruit.hpp
*/

#pragma once

#include "IShip.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Recruit : public IShip {
              public:
                Recruit();
                ~Recruit() = default;

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;

                bool getDirectionHorizontal() const override;
                bool getDirectionVertical() const override;
                
                void setDirectionHorizontal(bool dir) override;
                void setDirectionVertical(bool dir) override;

                void setHealth(float health) override;
                float getHealth() const override;
              protected:
              private:

            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype