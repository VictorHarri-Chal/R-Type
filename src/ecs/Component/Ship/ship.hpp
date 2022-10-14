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
                Ship(bool type);
                ~Ship();

                rtype::ecs::component::compoType getType() const;

                bool getShipType() const;
              protected:
              private:
                /// @brief True if allies, false if enemies
                bool _type;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !SHIP_HPP_ */
