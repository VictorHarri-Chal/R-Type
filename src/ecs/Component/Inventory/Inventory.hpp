/*
** EPITECH PROJECT, 2022
** Inventory (COMPONENT)
** File description:
** Inventory (COMPONENT)
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
                bool getBombUp() const;
                bool getFireUp() const;
                bool getSpeedUp() const;
                bool getWallPass() const;
                void setBombUp(bool bonus);
                void setFireUp(bool bonus);
                void setSpeedUp(bool bonus);
                void setWallPass(bool bonus);
                void setBonus(rtype::ecs::component::bonusType type);

              private:
                bool _bombUp;
                bool _fireUp;
                bool _speedUp;
                bool _wallPass;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype
