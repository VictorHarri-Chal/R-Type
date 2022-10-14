/*
** EPITECH PROJECT, 2022
** Collide (COMPONENT)
** File description:
** Collide (COMPONENT)
*/

#ifndef COLLIDE_HPP_
#define COLLIDE_HPP_

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Collide component
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
                 * @brief Get the Type object
                 * 
                 * @param otherEntityCollide 
                 * @return true 
                 * @return false 
                 */
                bool checkCollision(rtype::ecs::component::Collide *otherEntityCollide);
                /**
                 * @brief Set the Collide object
                 * 
                 * @param collide Boolean to define if object is collide or not
                 */
                void setCollide(bool collide);
                /**
                 * @brief Get the Collide object
                 * 
                 * @return true True if object is collide
                 * @return false False if object is not collide
                 */
                bool getCollide() const;
                /**
                 * @brief Get the Type object
                 * 
                 * @return rtype::ecs::component::compoType Type of component
                 */
                rtype::ecs::component::compoType getType() const;

              protected:
              private:
                /**
                 * @brief Boolean to define if object is collide or not
                 */
                bool _collide;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !COLLIDE_HPP_ */
