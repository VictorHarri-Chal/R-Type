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
                Ship(rtype::ecs::component::shipType type, bool dirHor = false, bool dirVer = false);
                ~Ship();

                rtype::ecs::component::compoType getType() const;

                rtype::ecs::component::shipType getShipType() const;

                bool getDirectionHorizontal() const;
                bool getDirectionVertical() const;
                
                void setDirectionHorizontal(bool dir);
                void setDirectionVertical(bool dir);

              protected:
              private:
                /// @brief True if allies, false if enemies
                rtype::ecs::component::shipType _shipType;

                /// @brief True if right, false if going left
                bool _directionHorizontal;

                /// @brief True if down, false if up
                bool _directionVertical;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !SHIP_HPP_ */
