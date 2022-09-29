/*
** EPITECH PROJECT, 2022
** Drawable2D (COMPONENT)
** File description:
** Drawable2D (COMPONENT)
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
                Drawable2D(float width, float height, sf::Color color, bool outline);
                Drawable2D(std::string text, float fontSize, sf::Color color, bool bold);
                Drawable2D(std::string texturePath, bool intRect, sf::IntRect rect = (sf::IntRect){0, 0, 0, 0});
                ~Drawable2D();

                void setHeight(float height);
                void setWidth(float width);
                void setFontSize(float fontSize);
                void setText(std::string text);
                void setTexturePath(std::string texturePath);
                void setFont(std::string fontPath);
                void setColor(sf::Color color);
                void setSpe(bool spe);
                rtype::ecs::component::compoType getType() const;
                rtype::ecs::component::drawableType getDrawType();
                float getHeight();
                float getWidth();
                float getFontSize();
                std::string getFont();
                sf::Color getColor();
                std::string getText();
                std::string getTexturePath() const;
                sf::Sprite getSprite() const;
                bool getSpe() const;

              private:
                sf::IntRect _rect;
                float _height;
                float _width;
                std::string _text;
                float _fontSize;
                std::string _font;
                sf::Color _color;
                std::string _texturePath;
                sf::Texture _texture;
                sf::Sprite _sprite;
                rtype::ecs::component::compoType _compoType;
                rtype::ecs::component::drawableType _drawableType;
                bool _spe;
            };
        }
    }
}
#endif /* !DRAWABLE2D_HPP_ */
