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
            class Transform : public IComponent {
              public:
                Transform();
                Transform(float posX, float posY, float speedX, float speedY);
                ~Transform();

                rtype::ecs::component::compoType getType(void) const override;
                void update(float posX, float posY, float speedX, float speedY);
                float getX() const;
                float getY() const;
                float getZ() const;
                void setX(float posX);
                void setY(float posY);
                void setZ(float posZ);
                float getSpeedX() const;
                float getSpeedY() const;
                void setSpeedY(float speed);
                void setSpeedX(float speed);

              private:
                float _posX;
                float _posY;
                float _posZ;
                float _speedX;
                float _speedY;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !TRANSFORM_HPP_ */
