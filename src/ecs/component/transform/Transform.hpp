/*
** EPITECH PROJECT, 2022
** Transform (COMPONENT)
** File description:
** Transform (COMPONENT)
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Transform component
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
                 * @param posX X position
                 * @param posY Y position
                 * @param speedX X speed
                 * @param speedY Y speed
                 */
                Transform(float posX, float posY, float speedX, float speedY);
                /**
                 * @brief Destroy Transform object
                 *
                 */
                ~Transform();
                /**
                 * @brief Get the Type object
                 *
                 * @return rtype::ecs::component::compoType Type of the component
                 */
                rtype::ecs::component::compoType getType(void) const override;                
                void update(float posX, float posY, float speedX, float speedY);
                /**
                 * @brief Get the X position
                 *
                 * @return float X position
                 */
                float getX() const;
                /**
                 * @brief Get the X position
                 *
                 * @return float X position
                 */
                float getY() const;
                /**
                 * @brief Get the Y position
                 *
                 * @return float Y position
                 */
                float getZ() const;
                /**
                 * @brief set the X position
                 * 
                 * @param posX X position
                 */
                void setX(float posX);
                /**
                 * @brief set the Y position
                 * 
                 * @param posY Y position
                 */
                void setY(float posY);
                /**
                 * @brief set the Z position
                 * 
                 * @param posZ Z position
                 */
                void setZ(float posZ);
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
                 * @brief Z position
                 * 
                 */
                float _posZ;
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

#endif /* !TRANSFORM_HPP_ */
