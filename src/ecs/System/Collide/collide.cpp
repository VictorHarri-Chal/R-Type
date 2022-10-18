/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** collide.cpp
*/

#include "collide.hpp"

rtype::ecs::system::SystemType rtype::ecs::system::CollideSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::COLLIDESYSTEM);
}

void rtype::ecs::system::CollideSystem::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game *gameEngine)
{
    (void) gameEngine;
    for (size_t x = 0; x < entities.size(); x++) {
        if (entities[x]->hasCompoType(ecs::component::compoType::COLLIDE)) {
            auto transformCompo1 = entities[x]->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            auto drawableCompo1 = entities[x]->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
            sf::Sprite sprite;
            sprite.setPosition(transformCompo1->getX(), transformCompo1->getY());
            sprite.setScale(drawableCompo1->getScale());
            sprite.setRotation(drawableCompo1->getRotation());
            if (drawableCompo1->getIsRect())
                sprite.setTextureRect(drawableCompo1->getRect());
            for (size_t y = 0; y < entities.size(); y++) {
                if (entities[y] != entities[x] && entities[y]->hasCompoType(rtype::ecs::component::compoType::COLLIDE)) {
                    auto transformCompo2 = entities[y]->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                    auto drawableCompo2 = entities[y]->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                    sf::Sprite otherSprite;
                    otherSprite.setPosition(transformCompo2->getX(), transformCompo2->getY());
                    otherSprite.setScale(drawableCompo2->getScale());
                    otherSprite.setRotation(drawableCompo2->getRotation());
                    if (drawableCompo2->getIsRect())
                        otherSprite.setTextureRect(drawableCompo2->getRect());
                    if (sprite.getGlobalBounds().intersects(otherSprite.getGlobalBounds())) {
                        if ((entities[x]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE && entities[y]->getEntityType() == rtype::ecs::entity::ENEMY) || 
                        (entities[y]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE && entities[x]->getEntityType() == rtype::ecs::entity::ENEMY)) {
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        }
                        else if ((entities[x]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && entities[y]->getEntityType() == rtype::ecs::entity::PLAYER) || 
                        (entities[y]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && entities[x]->getEntityType() == rtype::ecs::entity::PLAYER)) {
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        }
                        else if ((entities[x]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && entities[y]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE) || 
                        (entities[y]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && entities[x]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE)) {
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        }
                       
                    }
                }
            }
        }
    }
}
