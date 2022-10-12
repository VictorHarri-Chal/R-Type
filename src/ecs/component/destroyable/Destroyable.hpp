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
            /**
             * @brief Destroyable component
             */
            class Destroyable : public IComponent {
              public:
                /**
                 * @brief Construct a new Destroyable object
                 *
                 */
                Destroyable();
                /**
                 * @brief Destroy the Destroyable object
                 *
                 */
                ~Destroyable();
                /**
                 * @brief Get the Destroyable object
                 *
                 */
                rtype::ecs::component::compoType getType() const;

              protected:
              private:
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !DESTROYABLE_HPP_ */
