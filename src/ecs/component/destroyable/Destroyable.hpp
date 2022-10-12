/*
** EPITECH PROJECT, 2022
** Destroyable (COMPONENT)
** File description:
** Destroyable (COMPONENT)
*/

#ifndef DESTROYABLE_HPP_
#define DESTROYABLE_HPP_

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Destroyable : public IComponent {
              public:
                Destroyable();
                ~Destroyable();

                rtype::ecs::component::compoType getType() const;

              protected:
              private:
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !DESTROYABLE_HPP_ */
