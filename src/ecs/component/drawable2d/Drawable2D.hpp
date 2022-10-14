/*
** EPITECH PROJECT, 2022
** Drawable2D (COMPONENT)
** File description:
** Drawable2D (COMPONENT)
*/

#ifndef DRAWABLE2D_HPP_
#define DRAWABLE2D_HPP_

#include <string>
#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Drawable2D component
             */
            class Drawable2D : public IComponent {
              public:
                /**
                 * @brief Construct a new Drawable2D object
                 *
                 */
                Drawable2D();
                /**
                 * @brief Construct a new Drawable2D object
                 *
                 * @param width Width of the drawable
                 * @param height Height of the drawable
                 * @param color Color of the drawable
                 * @param outline Boolean if the drawable has an outline
                 * @param thickness Thickness of the outline
                 * @param outline_color Color of the outline
                 */
                Drawable2D(float width, float height, sf::Color color, bool outline, float thickness = float(0.0f),
                    sf::Color outline_color = sf::Color(sf::Color::Transparent));
                /**
                 * @brief Construct a new Drawable2D object
                 * 
                 * @param text Text of the drawable
                 * @param fontSize Size of the text
                 * @param color Color of the text
                 * @param bold Boolean if the text is bold
                 */
                Drawable2D(std::string text, float fontSize, sf::Color color, bool bold);
                /**
                 * @brief Construct a new Drawable2D object
                 * 
                 * @param texturePath Texture path of the drawable
                 * @param intRect Boolean if the drawable has an intRect
                 * @param rect Rectangle of the drawable
                 */
                Drawable2D(std::string texturePath, bool intRect, sf::IntRect rect = sf::IntRect(0, 0, 0, 0));
                /**
                 * @brief Destroy the Drawable2D object
                 *
                 */
                ~Drawable2D();
                /**
                 * @brief Set the height of the drawable
                 * 
                 * @param height Height of the drawable
                 */
                void setHeight(float height);
                /**
                 * @brief Set the width of the drawable
                 * 
                 * @param width Width of the drawable
                 */
                void setWidth(float width);
                /**
                 * @brief Set the font size of the drawable
                 * 
                 * @param fontSize Font size of the drawable
                 */
                void setFontSize(float fontSize);
                /**
                 * @brief Set the text of the drawable
                 * 
                 * @param text Text of the drawable
                 */
                void setText(std::string text);
                /**
                 * @brief Set the Texture Path of the drawable
                 * 
                 * @param texturePath Texture Path of the drawable
                 */
                void setTexturePath(std::string texturePath);
                /**
                 * @brief Set the Font Path of the drawa
                 * 
                 * @param fontPath Font Path of the drawable
                 */
                void setFont(std::string fontPath);
                /**
                 * @brief Set the color of the drawable
                 * 
                 * @param color Color of the drawable
                 */
                void setColor(sf::Color color);
                /**
                 * @brief Set the spe of the drawable
                 * 
                 * @param spe Boolean if the drawable has a spe
                 */
                void setSpe(bool spe);
                /**
                 * @brief Set the thickness of the drawable
                 * 
                 * @param thickness Thickness of the drawable
                 */
                void setThickness(float thickness);
                /**
                 * @brief Set the outline color of the drawable
                 * 
                 * @param color Outline color of the drawable
                 */
                void setOutlineColor(sf::Color color);
                /**
                 * @brief Get the Type object
                 * 
                 * @return rtype::ecs::component::compoType Type of component
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Drawable type object
                 * 
                 * @return rtype::ecs::component::drawableType Drawable type of component
                 */
                rtype::ecs::component::drawableType getDrawType();
                /**
                 * @brief Get the height of the drawable
                 * 
                 * @return float Height of the drawable
                 */
                float getHeight();
                /**
                 * @brief Get the width of the drawable
                 * 
                 * @return float Width of the drawable
                 */
                float getWidth();
                /**
                 * @brief Get the font size of the drawable
                 * 
                 * @return float Font size of the drawable
                 */
                float getFontSize();
                /**
                 * @brief Get the font of the drawable
                 * 
                 * @return std::string Font of the drawable
                 */
                std::string getFont();
                /**
                 * @brief Get the color of the drawable
                 * 
                 * @return sf::Color Color of the drawable
                 */
                sf::Color getColor();
                /**
                 * @brief Get the outline thickness of the drawable
                 * 
                 * @return float Outline thickness of the drawable
                 */
                float getOutlineThickness();
                /**
                 * @brief Get the outline color of the drawable
                 * 
                 * @return sf::Color Outline color of the drawable
                 */
                sf::Color getOutlineColor();
                /**
                 * @brief Get the text of the drawable
                 * 
                 * @return std::string Text of the drawable
                 */
                std::string getText();
                /**
                 * @brief Get the texture path of the drawable
                 * 
                 * @return std::string Texture path of the drawable
                 */
                std::string getTexturePath() const;
                /**
                 * @brief Get the sprite of the drawable
                 * 
                 * @return sf::Sprite Sprite of the drawable
                 */
                sf::Sprite getSprite() const;
                /**
                 * @brief Get the spe of the drawable
                 * 
                 * @return bool Spe of the drawable
                 */
                bool getSpe() const;

              private:
                /**
                 * @brief Rectangle of the drawable
                 * 
                 */
                sf::IntRect _rect;
                /**
                 * @brief Height of the drawable
                 * 
                 */
                float _height;
                /**
                 * @brief Width of the drawable
                 * 
                 */
                float _width;
                /**
                 * @brief Text of the drawable
                 * 
                 */
                std::string _text;
                /**
                 * @brief Font size of the drawable
                 * 
                 */
                float _fontSize;
                /**
                 * @brief Font of the drawable
                 * 
                 */
                std::string _font;
                /**
                 * @brief Color of the drawable
                 * 
                 */
                sf::Color _color;
                /**
                 * @brief Spe of the drawable
                 * 
                 */
                bool _spe;
                /**
                 * @brief Thickness of the drawable
                 * 
                 */
                float _thickness;
                /**
                 * @brief Outline color of the drawable
                 * 
                 */
                sf::Color _outline_color;
                /**
                 * @brief Texture path of the drawable
                 * 
                 */
                std::string _texturePath;
                /**
                 * @brief Texture of the drawable
                 * 
                 */
                sf::Texture _texture;
                /**
                 * @brief Sprite of the drawable
                 * 
                 */
                sf::Sprite _sprite;
                /**
                 * @brief Compo type of the drawable
                 * 
                 */
                rtype::ecs::component::compoType _compoType;
                /**
                 * @brief Drawable type of the drawable
                 * 
                 */
                rtype::ecs::component::drawableType _drawableType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype
#endif /* !DRAWABLE2D_HPP_ */
