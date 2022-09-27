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
                Drawable2D(float radius);
                Drawable2D(std::string text, float fontSize);
                Drawable2D(std::string texturePath, float height, float width);
                ~Drawable2D();

                rtype::ecs::component::compoType getType() const;
                rtype::ecs::component::drawableType getDrawType();
                float getRadius();
                float getHeight();
                float getWidth();
                void setRadius(float radius);
                void setHeight(float height);
                void setWidth(float width);
                float getFontSize();
                void setFontSize(float fontSize);
                std::string getText();
                void setText(std::string text);
                std::string getTexturePath() const;
                void setTexturePath(std::string texturePath);
                sf::Sprite getSprite() const;

              private:
                float _radius;
                float _height;
                float _width;
                std::string _text;
                float _fontSize;
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
