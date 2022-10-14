/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** ship.hpp
*/

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Ship : public IComponent {
              public:
                Ship(rtype::ecs::component::shipType type);
                ~Ship();

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;
              protected:
              private:
                /// @brief True if allies, false if enemies
                rtype::ecs::component::shipType _shipType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !SHIP_HPP_ */
