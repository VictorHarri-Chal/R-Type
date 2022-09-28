/**
 * @file Draw2D.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Draw2D system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Draw2D.hpp"

void rtype::ecs::system::Draw2DSystem::drawText(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo)
{
    sf::Text text;

    text.setFont(drawableCompo.getFont());
    text.setString(drawableCompo.getText());
    text.setCharacterSize(drawableCompo.getFontSize());
    text.setPosition(sf::Vector2f(transformCompo.getX(), transformCompo.getY()));
    text.setFillColor(drawableCompo.getColor());
    if (drawableCompo.getSpe())
        text.setStyle(sf::Text::Bold);
}

void rtype::ecs::system::Draw2DSystem::drawRectangle(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo)
{
    sf::RectangleShape rectangle(sf::Vector2f(drawableCompo.getWidth(), drawableCompo.getHeight()));

    rectangle.setPosition(sf::Vector2f(transformCompo.getX(), transformCompo.getY()));
    if (drawableCompo.getSpe())
        rectangle.setOutlineColor(drawableCompo.getColor());
    else
        rectangle.setFillColor(drawableCompo.getColor());

}

void rtype::ecs::system::Draw2DSystem::drawSprite(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo)
{
    drawableCompo.getSprite().setPosition(sf::Vector2f(transformCompo.getX(), transformCompo.getY()));
}

rtype::ecs::system::SystemType rtype::ecs::system::Draw2DSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::DRAWABLE2DSYSTEM);
}

void rtype::ecs::system::Draw2DSystem::update(std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> &entities)
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
                    case rtype::ecs::component::drawableType::RECTANGLE: drawRectangle(*compo, *transformCompo); break;
                    case rtype::ecs::component::drawableType::TEXT: drawText(*compo, *transformCompo); break;
                    case rtype::ecs::component::drawableType::SPRITE: drawSprite(*compo, *transformCompo); break;
                    default: continue;
                }
            }
        }
    }
}