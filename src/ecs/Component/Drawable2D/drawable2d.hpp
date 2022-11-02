/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** drawable2d.hpp
*/

#pragma once

#include "../IComponent.hpp"
#include <string>

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Class for the Drawable2D component
             * 
             */
            class Drawable2D : public IComponent {
              public:
                /**
                 * @brief Construct a new Drawable 2D object
                 * 
                 */
                Drawable2D();
                /**
                 * @brief Construct a new Drawable 2D object
                 * 
                 * @param text text to draw
                 * @param fontSize Size of the font for the text
                 * @param color Color of the text
                 * @param bold Boolean to know if the text is bold
                 */
                Drawable2D(std::string text, float fontSize, sf::Color color, bool bold);
                /**
                 * @brief Construct a new Drawable 2D object
                 * 
                 * @param texturePath Path to the texture
                 * @param isRect True if the texture is a rectangle
                 * @param scale Scale of the texture
                 * @param rotation Rotation of the texture
                 * @param rect Rectangle of the texture
                 */
                Drawable2D(std::string texturePath, bool isRect, sf::Vector2f scale, int rotation, sf::IntRect rect = sf::IntRect(0, 0, 0, 0));
                /**
                 * @brief Construct a new Drawable 2D object
                 * 
                 * @param width Width of the rectangle
                 * @param height Height of the rectangle
                 * @param color Color of the rectangle
                 * @param outline Boolean to know if the rectangle has an outline
                 * @param thickness Thickness of the rectangle
                 * @param outline_color Color of the outline
                 */
                Drawable2D(float width, float height, sf::Color color, bool outline, float thickness = float(0.0f),
                  sf::Color outline_color = sf::Color(sf::Color::Transparent));
                /**
                 * @brief Destroy the Drawable 2D object
                 * 
                 */
                ~Drawable2D();

                /**
                 * @brief Set the Height of the component
                 * 
                 * @param height Height of the component
                 */
                void setHeight(float height);
                /**
                 * @brief Set the Width of the component
                 * 
                 * @param width Width of the component
                 */
                void setWidth(float width);
                /**
                 * @brief Set the font size of the component
                 * 
                 * @param fontSize Font size of the component
                 */
                void setFontSize(float fontSize);
                /**
                 * @brief Set the Text of the component
                 * 
                 * @param text Text of the component
                 */
                void setText(std::string text);
                /**
                 * @brief Set the texture path of the component
                 * 
                 * @param texturePath Path of the texture
                 */
                void setTexturePath(std::string texturePath);
                /**
                 * @brief Set the font of the component
                 * 
                 * @param fontPath Path of the font
                 */
                void setFont(std::string fontPath);
                /**
                 * @brief Set the Color of the component
                 * 
                 * @param color Color of the component
                 */
                void setColor(sf::Color color);
                /**
                 * @brief Set the Spe of the component
                 * 
                 * @param spe Spe of the component
                 */
                void setSpe(bool spe);
                /**
                 * @brief Set the Thickness of the component
                 * 
                 * @param thickness Thickness of the component
                 */
                void setThickness(float thickness);
                /**
                 * @brief Set the Outline Color of the component
                 * 
                 * @param color Outline Color of the component
                 */
                void setOutlineColor(sf::Color color);
                /**
                 * @brief Set the Rect of the component
                 * 
                 * @param rect Rect of the component
                 */
                void setRect(sf::IntRect rect);
                /**
                 * @brief Get the component type
                 * 
                 * @return rtype::ecs::component::compoType The type of the component
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Draw Type of the component
                 * 
                 * @return rtype::ecs::component::drawableType The draw type of the component 
                 */
                rtype::ecs::component::drawableType getDrawType();
                /**
                 * @brief Get the Height of the component
                 * 
                 * @return float The height of the component
                 */
                float getHeight();
                /**
                 * @brief Get the Width of the component
                 * 
                 * @return float The width of the component
                 */
                float getWidth();
                /**
                 * @brief Get the Font Size of the component
                 * 
                 * @return float The font size of the component
                 */
                float getFontSize();
                /**
                 * @brief Get the Font of the component
                 * 
                 * @return std::string The font of the component
                 */
                std::string getFont();
                /**
                 * @brief Get the Color of the component
                 * 
                 * @return sf::Color The color of the component
                 */
                sf::Color getColor();
                /**
                 * @brief Get the Outline Thickness of the component
                 * 
                 * @return float The outline thickness of the component
                 */
                float getOutlineThickness();
                /**
                 * @brief Get the Outline Color of the component
                 * 
                 * @return sf::Color The outline color of the component
                 */
                sf::Color getOutlineColor();
                /**
                 * @brief Get the Text of the component
                 * 
                 * @return std::string The text of the component
                 */
                std::string getText();
                /**
                 * @brief Get the Texture Path of the component
                 * 
                 * @return std::string The texture path of the component
                 */
                std::string getTexturePath() const;
                /**
                 * @brief Get the Texture of the component
                 * 
                 * @return sf::Texture The texture of the component
                 */
                sf::Texture getTexture() const;
                /**
                 * @brief Get the Sprite of the component
                 * 
                 * @return sf::Sprite The sprite of the component
                 */
                sf::Sprite getSprite() const;
                /**
                 * @brief Get the Spe of the component
                 * 
                 * @return true If the component is a spe
                 * @return false If the component is not a spe
                 */
                bool getSpe() const;
                /**
                 * @brief Get if the component is a rectangle
                 * 
                 * @return true If the component is a rectangle
                 * @return false If the component is not a rectangle
                 */
                bool getIsRect() const;
                /**
                 * @brief Get the Rect of the component
                 * 
                 * @return sf::IntRect The rect of the component
                 */
                sf::IntRect getRect() const;
                /**
                 * @brief Get the Scale of the component
                 * 
                 * @return sf::Vector2f The scale of the component
                 */
                sf::Vector2f getScale() const;
                /**
                 * @brief Get the Rotation of the component
                 * 
                 * @return int The rotation of the component
                 */
                int getRotation() const;

              private:
                /**
                 * @brief Boolean to define if the component is a rectangle
                 * 
                 */
                bool _isRect;
                /**
                 * @brief Rect for the component
                 * 
                 */
                sf::IntRect _rect;
                /**
                 * @brief Scale of the component
                 * 
                 */
                sf::Vector2f _scale;
                /**
                 * @brief Rotation of the component
                 * 
                 */
                int _rotation;
                /**
                 * @brief Height of the component
                 * 
                 */
                float _height;
                /**
                 * @brief Width of the component
                 * 
                 */
                float _width;
                /**
                 * @brief Text of the component
                 * 
                 */
                std::string _text;
                /**
                 * @brief Font size of the component
                 * 
                 */
                float _fontSize;
                /**
                 * @brief Font of the component
                 * 
                 */
                std::string _font;
                /**
                 * @brief Color of the component
                 * 
                 */
                sf::Color _color;
                /**
                 * @brief Boolean to define if the component is a spe
                 * 
                 */
                bool _spe;
                /**
                 * @brief Thickness of the component
                 * 
                 */
                float _thickness;
                /**
                 * @brief Outline color of the component
                 * 
                 */
                sf::Color _outline_color;
                /**
                 * @brief Texture path of the component
                 * 
                 */
                std::string _texturePath;
                /**
                 * @brief Texture of the component
                 * 
                 */
                sf::Texture _texture;
                /**
                 * @brief Sprite of the component
                 * 
                 */
                sf::Sprite _sprite;
                /**
                 * @brief Type of the component
                 * 
                 */
                rtype::ecs::component::compoType _compoType;
                /**
                 * @brief Draw type of the component
                 * 
                 */
                rtype::ecs::component::drawableType _drawableType;
            };
        }
    }
}
