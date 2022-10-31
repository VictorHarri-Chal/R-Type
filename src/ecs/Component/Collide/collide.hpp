/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** collide.hpp
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
             * @brief Collide component
             *
             */
            class Collide : public IComponent {
              public:
                /**
                 * @brief Construct a new Collide object
                 *
                 */
                Collide();
                /**
                 * @brief Destroy the Collide object
                 *
                 */
                ~Collide();
                /**
                 * @brief Set if the component is colliding
                 * 
                 * @param collide Boolean to define if colliding or not
                 */
                void setCollide(bool collide);
                /**
                 * @brief Get if the component is colliding
                 * 
                 * @return true If colliding
                 * @return false If not colliding
                 */
                bool getCollide() const;
                /**
                 * @brief Get the Type of the component
                 * 
                 * @return rtype::ecs::component::compoType Type of the component
                 */
                rtype::ecs::component::compoType getType() const;

              protected:
              private:
                /**
                 * @brief Boolean to define if colliding or not
                 * 
                 */
                bool _collide;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype
