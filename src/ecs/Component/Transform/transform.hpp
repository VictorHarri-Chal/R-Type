/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** transform.hpp
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
                void setX(float posX);
                void setY(float posY);
                float getSpeedX() const;
                float getSpeedY() const;
                void setSpeedY(float speed);
                void setSpeedX(float speed);

              private:
                float _posX;
                float _posY;
                float _speedX;
                float _speedY;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !TRANSFORM_HPP_ */
