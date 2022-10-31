/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** transform.hpp
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
             * @brief Class for the Transform component
             * 
             */
            class Transform : public IComponent {
              public:
                /**
                 * @brief Construct a new Transform object
                 * 
                 */
                Transform();
                /**
                 * @brief Construct a new Transform object
                 * 
                 * @param posX  X position
                 * @param posY Y position
                 * @param speedX X speed
                 * @param speedY Y speed
                 */
                Transform(float posX, float posY, float speedX, float speedY);
                /**
                 * @brief Destroy the Transform object
                 * 
                 */
                ~Transform();

                /**
                 * @brief Get the Type object
                 * 
                 * @return rtype::ecs::component::compoType The type of the component
                 */
                rtype::ecs::component::compoType getType(void) const override;
                /**
                 * @brief Update the component
                 * 
                 * @param posX X position
                 * @param posY Y position
                 * @param speedX X speed
                 * @param speedY Y speed
                 */
                void update(float posX, float posY, float speedX, float speedY);
                /**
                 * @brief Get the X position
                 * 
                 * @return float X position
                 */
                float getX() const;
                /**
                 * @brief Get the Y position
                 * 
                 * @return float Y position
                 */
                float getY() const;
                /**
                 * @brief Set the X position
                 * 
                 * @param posX X position
                 */
                void setX(float posX);
                /**
                 * @brief Set the Y position
                 * 
                 * @param posY Y position
                 */
                void setY(float posY);
                /**
                 * @brief Get the X speed
                 * 
                 * @return float X speed
                 */
                float getSpeedX() const;
                /**
                 * @brief Get the Y speed
                 * 
                 * @return float Y speed
                 */
                float getSpeedY() const;
                /**
                 * @brief Set the Y speed
                 * 
                 * @param speed Y speed
                 */
                void setSpeedY(float speed);
                /**
                 * @brief Set the X speed
                 * 
                 * @param speed X speed
                 */
                void setSpeedX(float speed);

              private:
                /**
                 * @brief X position
                 * 
                 */
                float _posX;
                /**
                 * @brief Y position
                 * 
                 */
                float _posY;
                /**
                 * @brief X speed
                 * 
                 */
                float _speedX;
                /**
                 * @brief Y speed
                 * 
                 */
                float _speedY;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype
