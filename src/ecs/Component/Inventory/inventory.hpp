/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** inventory.hpp
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

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

#endif /* !INVENTORY_HPP_ */
