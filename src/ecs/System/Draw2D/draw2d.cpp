/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** draw2d.cpp
*/

#include "draw2d.hpp"

void rtype::ecs::system::Draw2DSystem::drawText(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine)
{
    sf::Text text;
    sf::Font font;

    font.loadFromFile(drawableCompo.getFont());
    text.setFont(font);
    text.setString(drawableCompo.getText());
    text.setCharacterSize(drawableCompo.getFontSize());
    text.setPosition(sf::Vector2f(transformCompo.getX(), transformCompo.getY()));
    text.setFillColor(drawableCompo.getColor());
    if (drawableCompo.getSpe())
        text.setStyle(sf::Text::Bold);
    gameEngine->_window.draw(text);
}

void rtype::ecs::system::Draw2DSystem::drawRectangle(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine)
{
    sf::RectangleShape rectangle(sf::Vector2f(drawableCompo.getWidth(), drawableCompo.getHeight()));

    rectangle.setPosition(sf::Vector2f(transformCompo.getX(), transformCompo.getY()));
    if (drawableCompo.getSpe()) {        
        rectangle.setOutlineThickness(drawableCompo.getOutlineThickness());
        rectangle.setOutlineColor(drawableCompo.getOutlineColor());
        rectangle.setFillColor(drawableCompo.getColor());
    } else
        rectangle.setFillColor(drawableCompo.getColor());
    gameEngine->_window.draw(rectangle);
}

void rtype::ecs::system::Draw2DSystem::drawSprite(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine)
{
    sf::Sprite sprite = drawableCompo.getSprite();
    if (drawableCompo.getIsRect())
        sprite.setTextureRect(drawableCompo.getRect());
    sprite.scale(drawableCompo.getScale());
    sprite.setRotation(drawableCompo.getRotation());
    sprite.setPosition(sf::Vector2f(transformCompo.getX(), transformCompo.getY()));
    gameEngine->_window.draw(sprite);
}

rtype::ecs::system::SystemType rtype::ecs::system::Draw2DSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::DRAWABLE2DSYSTEM);
}

void rtype::ecs::system::Draw2DSystem::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game *gameEngine)
{
    for (auto &entity : entities) {
        std::vector<rtype::ecs::component::Drawable2D *> compoVector = entity->getDrawableVector();
        if (entity->hasCompoType(rtype::ecs::component::compoType::ALIVE)
            && entity->getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::compoType::ALIVE)->getAlive()
                == false) {
            continue;
        }
        for (auto &compo : compoVector) {
            if (compo->getType() == rtype::ecs::component::compoType::DRAWABLE2D) {
                rtype::ecs::component::Transform *transformCompo =
                    entity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::compoType::TRANSFORM);
                switch (compo->getDrawType()) {
                    case rtype::ecs::component::drawableType::RECTANGLE: drawRectangle(*compo, *transformCompo, gameEngine); break;
                    case rtype::ecs::component::drawableType::TEXT: drawText(*compo, *transformCompo, gameEngine); break;
                    case rtype::ecs::component::drawableType::SPRITE: drawSprite(*compo, *transformCompo, gameEngine); break;
                    default: continue;
                }
            }
        }
    }
    animations(entities);
}

void rtype::ecs::system::Draw2DSystem::animations(std::vector<rtype::ecs::entity::Entity*> entities)
{
    if (_allyClock.getElapsedTime() >= sf::seconds(1.0/8.0f)) {
        for (auto &entity : entities) {
            if (entity->getEntityType() == rtype::ecs::entity::PLAYER) {
                rtype::ecs::component::Drawable2D *drawable2dCompo =
                entity->getComponent<rtype::ecs::component::Drawable2D>(rtype::ecs::component::compoType::DRAWABLE2D);
                sf::IntRect rect = drawable2dCompo->getRect();
                if (rect.left == 33)
                    rect.left = 0;
                else
                    rect.left += 33;
                drawable2dCompo->setRect(rect);
            }
            _allyClock.restart();
        }
    } else if (_enemyClock.getElapsedTime() >= sf::seconds(1.0/6.0f)) {
        for (auto &entity : entities) {
            if (entity->getEntityType() == rtype::ecs::entity::ENEMY) {
                rtype::ecs::component::Drawable2D *drawable2dCompo =
                entity->getComponent<rtype::ecs::component::Drawable2D>(rtype::ecs::component::compoType::DRAWABLE2D);
                sf::IntRect rect = drawable2dCompo->getRect();
                if (rect.left == 66)
                    rect.left = 34;
                else
                    rect.left += 32;
                drawable2dCompo->setRect(rect);
            }
            _enemyClock.restart();
        }
    }
}