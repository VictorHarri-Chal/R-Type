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
            /**
             * @brief Inventory component
             *
             */
            class Inventory : public IComponent {
              public:
                /**
                 * @brief Construct a new Inventory object
                 *
                 */
                Inventory();
                /**
                 * @brief Destroy the Inventory object
                 *
                 */
                ~Inventory();
                /**
                 * @brief Get the Type of the component
                 * 
                 * @return rtype::ecs::component::compoType Type of the component
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Set the Bonus type of the component
                 * 
                 * @param type Bonus type of the component
                 */
                void setBonus(rtype::ecs::component::bonusType type);

              private:

            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype
