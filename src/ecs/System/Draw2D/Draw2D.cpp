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

void indie::ecs::system::Draw2DSystem::drawText(auto drawableCompo, auto transformCompo)
{
    indie::raylib::Draw text(
        transformCompo->getX(), transformCompo->getY(), drawableCompo->getFontSize(), drawableCompo->getColor());
    text.drawText(drawableCompo->getText());
}

void indie::ecs::system::Draw2DSystem::drawRectangle(auto drawableCompo, auto transformCompo)
{
    if (drawableCompo->getTexturePath() == "") {
        indie::raylib::Rectangle::draw(transformCompo->getX(), transformCompo->getY(), drawableCompo->getWidth(),
            drawableCompo->getHeight(), drawableCompo->getColor());
    } else {
        Texture2D texture = drawableCompo->getTexture();
        texture.width = drawableCompo->getWidth();
        texture.height = drawableCompo->getHeight();
        indie::raylib::Texture2D::draw(
            texture, transformCompo->getX(), transformCompo->getY(), drawableCompo->getColor());
    }
}

indie::ecs::system::SystemType indie::ecs::system::Draw2DSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::DRAWABLE2DSYSTEM);
}

void indie::ecs::system::Draw2DSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        std::vector<indie::ecs::component::Drawable2D *> compoVector = entity->getDrawableVector();
        if (entity->hasCompoType(indie::ecs::component::compoType::ALIVE)
            && entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::compoType::ALIVE)->getAlive()
                == false) {
            continue;
        }
        for (auto &compo : compoVector) {
            if (compo->getType() == indie::ecs::component::compoType::DRAWABLE2D) {
                auto transformCompo =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                if (transformCompo != nullptr) {
                    switch (compo->getDrawType()) {
                        case indie::ecs::component::drawableType::CIRCLE:
                            indie::raylib::Circle::draw(
                                transformCompo->getX(), transformCompo->getY(), compo->getRadius(), compo->getColor());
                        case indie::ecs::component::drawableType::TEXT: drawText(compo, transformCompo);
                        case indie::ecs::component::drawableType::RECTANGLE: drawRectangle(compo, transformCompo);
                        default: continue;
                    }
                }
            }
        }
        if (entity->hasCompoType(indie::ecs::component::compoType::DRAWABLE2D)) {
            auto drawableCompo =
                entity->getComponent<indie::ecs::component::Drawable2D>(indie::ecs::component::compoType::DRAWABLE2D);
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            if (drawableCompo != nullptr && transformCompo != nullptr) {
                switch (drawableCompo->getDrawType()) {
                    case indie::ecs::component::drawableType::CIRCLE:
                        indie::raylib::Circle::draw(transformCompo->getX(), transformCompo->getY(),
                            drawableCompo->getRadius(), drawableCompo->getColor());
                    case indie::ecs::component::drawableType::TEXT: drawText(drawableCompo, transformCompo);
                    case indie::ecs::component::drawableType::RECTANGLE: drawRectangle(drawableCompo, transformCompo);
                    default: continue;
                }
            }
        }
    }
}