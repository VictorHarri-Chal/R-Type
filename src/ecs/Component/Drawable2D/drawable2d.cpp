/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** drawable2d.cpp
*/

#include "drawable2d.hpp"
#include <iostream>

rtype::ecs::component::Drawable2D::Drawable2D()
{
    this->_height = 0.0;
    this->_width = 0.0;
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::UNKNOWNDRAWABLE;
}

rtype::ecs::component::Drawable2D::Drawable2D(std::string text, float fontSize, sf::Color color, bool bold)
{
    this->_height = 0.0;
    this->_width = 0.0;
    this->_text = text;
    this->_fontSize = fontSize;
    this->_font = "assets/font.ttf";
    this->_color = color;
    this->_spe = bold;
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::TEXT;
}

rtype::ecs::component::Drawable2D::Drawable2D(std::string texturePath, bool isRect, sf::Vector2f scale, int rotation, sf::IntRect rect)
{
    this->_texturePath = texturePath;
    this->_isRect = isRect;
    this->_rect = rect;
    this->_scale = scale;
    this->_rotation = rotation;
    if (!texturePath.empty())
        _texture.loadFromFile(texturePath.c_str());
    _sprite = sf::Sprite(_texture);
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::SPRITE;
}

rtype::ecs::component::Drawable2D::Drawable2D(float width, float height, sf::Color color, bool outline, float thickness, sf::Color outline_color)
{
    this->_height = height;
    this->_width = width;
    this->_color = color;
    this->_spe = outline;
    this->_thickness = thickness;
    this->_outline_color = outline_color;
    this->_compoType = rtype::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = rtype::ecs::component::drawableType::RECTANGLE;
}

rtype::ecs::component::Drawable2D::~Drawable2D()
{
}

std::string rtype::ecs::component::Drawable2D::getText()
{
    return (this->_text);
}

float rtype::ecs::component::Drawable2D::getFontSize()
{
    return (this->_fontSize);
}

std::string rtype::ecs::component::Drawable2D::getFont()
{
    return (this->_font);
}

sf::Color rtype::ecs::component::Drawable2D::getColor()
{
    return (this->_color);
}
float rtype::ecs::component::Drawable2D::getOutlineThickness()
{
    return (this->_thickness);
}

sf::Color rtype::ecs::component::Drawable2D::getOutlineColor()
{
    return (this->_outline_color);
}

rtype::ecs::component::compoType rtype::ecs::component::Drawable2D::getType() const
{
    return (this->_compoType);
}

rtype::ecs::component::drawableType rtype::ecs::component::Drawable2D::getDrawType()
{
    return (this->_drawableType);
}

float rtype::ecs::component::Drawable2D::getHeight()
{
    return (this->_height);
}

float rtype::ecs::component::Drawable2D::getWidth()
{
    return (this->_width);
}

bool rtype::ecs::component::Drawable2D::getSpe() const
{
    return (this->_spe);
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

bool rtype::ecs::component::Drawable2D::getIsRect() const
{
    return (this->_isRect);
}

sf::IntRect rtype::ecs::component::Drawable2D::getRect() const
{
    return (this->_rect);
}

sf::Vector2f rtype::ecs::component::Drawable2D::getScale() const
{
    return (this->_scale);
}

int rtype::ecs::component::Drawable2D::getRotation() const
{
    return (this->_rotation);
}

void rtype::ecs::component::Drawable2D::setText(std::string text)
{
    this->_text = text;
}

void rtype::ecs::component::Drawable2D::setFontSize(float fontSize)
{
    this->_fontSize = fontSize;
}

void rtype::ecs::component::Drawable2D::setHeight(float height)
{
    this->_height = height;
}

void rtype::ecs::component::Drawable2D::setWidth(float width)
{
    this->_width = width;
}

void rtype::ecs::component::Drawable2D::setFont(std::string fontPath)
{
    this->_font = fontPath;
}

void rtype::ecs::component::Drawable2D::setColor(sf::Color color)
{
    this->_color = color;
}

void rtype::ecs::component::Drawable2D::setSpe(bool bold)
{
    this->_spe = bold;
}

void rtype::ecs::component::Drawable2D::setThickness(float thickness)
{
    this->_thickness = thickness;
}

void rtype::ecs::component::Drawable2D::setOutlineColor(sf::Color color)
{
    this->_outline_color = color;
}