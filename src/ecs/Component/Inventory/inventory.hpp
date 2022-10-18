/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** inventory.hpp
*/

#pragma once

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Inventory component
            class Inventory : public IComponent {
              public:
                Inventory();
                ~Inventory();

                rtype::ecs::component::compoType getType() const;
                void setBonus(rtype::ecs::component::bonusType type);

              private:

            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype
