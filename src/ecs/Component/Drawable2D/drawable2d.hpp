/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** drawable2d.hpp
*/

#ifndef DRAWABLE2D_HPP_
#define DRAWABLE2D_HPP_

#include "../IComponent.hpp"
#include <string>

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Drawable2D : public IComponent {
              public:
                Drawable2D();
                Drawable2D(std::string text, float fontSize, sf::Color color, bool bold);
                Drawable2D(std::string texturePath, bool isRect, sf::Vector2f scale, int rotation, sf::IntRect rect = sf::IntRect(0, 0, 0, 0));
                Drawable2D(float width, float height, sf::Color color, bool outline, float thickness = float(0.0f),
                  sf::Color outline_color = sf::Color(sf::Color::Transparent));
                ~Drawable2D();

                void setHeight(float height);
                void setWidth(float width);
                void setFontSize(float fontSize);
                void setText(std::string text);
                void setTexturePath(std::string texturePath);
                void setFont(std::string fontPath);
                void setColor(sf::Color color);
                void setSpe(bool spe);
                void setThickness(float thickness);
                void setOutlineColor(sf::Color color);
                rtype::ecs::component::compoType getType() const;
                rtype::ecs::component::drawableType getDrawType();
                float getHeight();
                float getWidth();
                float getFontSize();
                std::string getFont();
                sf::Color getColor();
                float getOutlineThickness();
                sf::Color getOutlineColor();
                std::string getText();
                std::string getTexturePath() const;
                sf::Texture getTexture() const;
                sf::Sprite getSprite() const;
                bool getSpe() const;
                bool getIsRect() const;
                sf::IntRect getRect() const;
                sf::Vector2f getScale() const;
                int getRotation() const;

              private:
                bool _isRect;
                sf::IntRect _rect;
                sf::Vector2f _scale;
                int _rotation;
                float _height;
                float _width;
                std::string _text;
                float _fontSize;
                std::string _font;
                sf::Color _color;
                bool _spe;
                float _thickness;
                sf::Color _outline_color;
                std::string _texturePath;
                sf::Texture _texture;
                sf::Sprite _sprite;
                rtype::ecs::component::compoType _compoType;
                rtype::ecs::component::drawableType _drawableType;
            };
        }
    }
}
#endif /* !DRAWABLE2D_HPP_ */