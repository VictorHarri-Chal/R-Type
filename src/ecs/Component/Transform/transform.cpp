/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** transform.cpp
*/

#include "transform.hpp"

rtype::ecs::component::Transform::Transform()
{
    this->_posX = 0.0;
    this->_posY = 0.0;
    this->_posZ = 0.0;
    this->_speedX = 0.0;
    this->_speedY = 0.0;
}

rtype::ecs::component::Transform::Transform(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_posZ = 0.0;
    this->_speedX = speedX;
    this->_speedY = speedY;
}

rtype::ecs::component::Transform::~Transform()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Transform::getType(void) const
{
    return (rtype::ecs::component::compoType::TRANSFORM);
}

void rtype::ecs::component::Transform::update(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_speedX = speedX;
    this->_speedY = speedY;
}

float rtype::ecs::component::Transform::getX() const
{
    return (this->_posX);
}

float rtype::ecs::component::Transform::getY() const
{
    return (this->_posY);
}

void rtype::ecs::component::Transform::setX(float posX)
{
    this->_posX = posX;
}

void rtype::ecs::component::Transform::setY(float posY)
{
    this->_posY = posY;
}

float rtype::ecs::component::Transform::getSpeedX() const
{
    return (this->_speedX);
}

float rtype::ecs::component::Transform::getSpeedY() const
{
    return (this->_speedY);
}

void rtype::ecs::component::Transform::setSpeedY(float speed)
{
    this->_speedY = speed;
}

void rtype::ecs::component::Transform::setSpeedX(float speed)
{
    this->_speedX = speed;
}

void rtype::ecs::component::Transform::setZ(float posZ)
{
    this->_posZ = posZ;
}

float rtype::ecs::component::Transform::getZ() const
{
    return (this->_posZ);
}