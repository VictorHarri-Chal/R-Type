/*
** EPITECH PROJECT, 2022
** Alive (COMPONENT)
** File description:
** Alive (COMPONENT)
*/

#ifndef ALIVE_HPP_
#define ALIVE_HPP_

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Alive component
             */
            class Alive : public IComponent {
              public:
                /**
                 * @brief Construct a new Alive object
                 *
                 */
                Alive();
                /**
                 * @brief Construct a new Alive object
                 *
                 * @param isAlive Boolean to define if object is alive or not
                 */
                Alive(bool isAlive);
                /**
                 * @brief Destroy the Alive object
                 *
                 */
                ~Alive();
                /**
                 * @brief Set the Alive object
                 *
                 * @param isAlive Boolean to define if object is alive or not
                 */
                void setAlive(bool isAlive);
                /**
                 * @brief Get the Alive object
                 *
                 * @return true True if object is alive
                 * @return false False if object is not alive
                 */
                bool getAlive() const;
                /**
                 * @brief Get the Type object
                 *
                 * @return rtype::ecs::component::compoType Type of component
                 */
                rtype::ecs::component::compoType getType() const;

              protected:
              private:
                /**
                 * @brief Boolean to define if object is alive or not
                 */
                bool _alive;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !ALIVE_HPP_ */
