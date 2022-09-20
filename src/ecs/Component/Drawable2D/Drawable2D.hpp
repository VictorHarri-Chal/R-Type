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
                // Drawable2D(float radius, Color color);
                // Drawable2D(std::string text, float fontSize, Color color);
                // Drawable2D(std::string texturePath, float height, float width, Color color);
                ~Drawable2D();

                rtype::ecs::component::compoType getType() const;
                rtype::ecs::component::drawableType getDrawType();
                // Color getColor();
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
                // Texture2D getTexture() const;
                void setTexture(std::string texturePath);

              private:
                float _radius;
                float _height;
                float _width;
                std::string _text;
                float _fontSize;
                // Color _color;
                std::string _texturePath;
                // Texture2D _texture;
                rtype::ecs::component::compoType _compoType;
                rtype::ecs::component::drawableType _drawableType;
            };
        }
    }
}
#endif /* !DRAWABLE2D_HPP_ */
