/*
** EPITECH PROJECT, 2022
** Drawable2D (COMPONENT)
** File description:
** Drawable2D (COMPONENT)
*/

#include "Drawable2D.hpp"

rtype::ecs::component::Drawable2D::Drawable2D()
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::UNKNOWNDRAWABLE;
}

rtype::ecs::component::Drawable2D::Drawable2D(float radius)
{
    this->_radius = radius;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::CIRCLE;
}

rtype::ecs::component::Drawable2D::Drawable2D(std::string texturePath, float height, float width)
{
    this->_radius = 0.0;
    this->_height = height;
    this->_width = width;
    this->_texturePath = texturePath;
    if (!texturePath.empty())
        _texture.loadFromFile(texturePath.c_str());
    _sprite = sf::Sprite(_texture);
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::RECTANGLE;
}

rtype::ecs::component::Drawable2D::Drawable2D(std::string text, float fontSize)
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_text = text;
    this->_fontSize = fontSize;
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::TEXT;
}

std::string rtype::ecs::component::Drawable2D::getText()
{
    return (this->_text);
}

float rtype::ecs::component::Drawable2D::getFontSize()
{
    return (this->_fontSize);
}

rtype::ecs::component::Drawable2D::~Drawable2D()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Drawable2D::getType() const
{
    return (this->_compoType);
}

rtype::ecs::component::drawableType rtype::ecs::component::Drawable2D::getDrawType()
{
    return (this->_drawableType);
}

float rtype::ecs::component::Drawable2D::getRadius()
{
    return (this->_radius);
}

float rtype::ecs::component::Drawable2D::getHeight()
{
    return (this->_height);
}

float rtype::ecs::component::Drawable2D::getWidth()
{
    return (this->_width);
}

std::string rtype::ecs::component::Drawable2D::getTexturePath() const
{
    return (this->_texturePath);
}

void rtype::ecs::component::Drawable2D::setTexturePath(std::string texturePath)
{
    this->_texturePath = texturePath;
}

sf::Sprite rtype::ecs::component::Drawable2D::getSprite() const
{
    return (this->_sprite);
}

void rtype::ecs::component::Drawable2D::setText(std::string text)
{
    this->_text = text;
}

void rtype::ecs::component::Drawable2D::setFontSize(float fontSize)
{
    this->_fontSize = fontSize;
}

void rtype::ecs::component::Drawable2D::setRadius(float radius)
{
    this->_radius = radius;
}

void rtype::ecs::component::Drawable2D::setHeight(float height)
{
    this->_height = height;
}

void rtype::ecs::component::Drawable2D::setWidth(float width)
{
    this->_width = width;
}
