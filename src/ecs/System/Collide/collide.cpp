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
        if (entities[x]->hasCompoType(ecs::component::compoType::COLLIDE) && 
            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->getCollide()) {
            auto transformCompo1 = entities[x]->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            auto drawableCompo1 = entities[x]->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
            sf::Sprite sprite;
            sprite.setPosition(transformCompo1->getX(), transformCompo1->getY());
            sprite.setScale(drawableCompo1->getScale());
            sprite.setRotation(drawableCompo1->getRotation());
            if (drawableCompo1->getIsRect())
                sprite.setTextureRect(drawableCompo1->getRect());
            for (size_t y = 0; y < entities.size(); y++) {
                if (entities[y] != entities[x] && entities[y]->hasCompoType(rtype::ecs::component::compoType::COLLIDE) && 
                    entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->getCollide()) {
                    auto transformCompo2 = entities[y]->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
                    auto drawableCompo2 = entities[y]->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
                    sf::Sprite otherSprite;
                    otherSprite.setPosition(transformCompo2->getX(), transformCompo2->getY());
                    otherSprite.setScale(drawableCompo2->getScale());
                    otherSprite.setRotation(drawableCompo2->getRotation());
                    if (drawableCompo2->getIsRect())
                        otherSprite.setTextureRect(drawableCompo2->getRect());
                    if (sprite.getGlobalBounds().intersects(otherSprite.getGlobalBounds())) {
                        if ((entities[x]->getEntityType() == rtype::ecs::entity::PLAYER1) && 
                        entities[x]->getComponent<rtype::ecs::component::IShip>(rtype::ecs::component::compoType::SHIP)->getShipType() == rtype::ecs::component::shipType::STEALTHY &&
                        entities[x]->getComponent<rtype::ecs::component::IShip>(rtype::ecs::component::compoType::SHIP)->getIfSkillActive()) {
                            return;
                        }
                        if ((entities[y]->getEntityType() == rtype::ecs::entity::PLAYER1) && 
                        entities[y]->getComponent<rtype::ecs::component::IShip>(rtype::ecs::component::compoType::SHIP)->getShipType() == rtype::ecs::component::shipType::STEALTHY &&
                        entities[y]->getComponent<rtype::ecs::component::IShip>(rtype::ecs::component::compoType::SHIP)->getIfSkillActive()) {
                            return;
                        }
                        if (entities[x]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE && entities[y]->getEntityType() == rtype::ecs::entity::ENEMY) {
                            auto projectileCompo = entities[x]->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE);
                            auto shipCompo = entities[y]->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
                            shipCompo->setHealth(shipCompo->getHealth() - projectileCompo->getDamage());
                            if (projectileCompo->getIsPoweredUp()) {
                                if (shipCompo->getHealth() <= 0) {
                                    entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                    ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                    aliveCompo2->setAlive(false);
                                }
                                return;
                            }
                            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            if (shipCompo->getHealth() <= 0) {
                                entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                aliveCompo2->setAlive(false);
                            }
                            return;
                        } else if (entities[y]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE && entities[x]->getEntityType() == rtype::ecs::entity::ENEMY) {
                            auto projectileCompo = entities[y]->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE);
                            auto shipCompo = entities[x]->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
                            shipCompo->setHealth(shipCompo->getHealth() - projectileCompo->getDamage());
                            if (projectileCompo->getIsPoweredUp()) {
                                if (shipCompo->getHealth() <= 0) {
                                    entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                    ecs::component::Alive *aliveCompo2 = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                    aliveCompo2->setAlive(false);
                                }
                                return;
                            }
                            entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            if (shipCompo->getHealth() <= 0) {
                                entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                ecs::component::Alive *aliveCompo2 = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                aliveCompo2->setAlive(false);
                            }
                            return;
                        } else if ((entities[x]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && (entities[y]->getEntityType() == rtype::ecs::entity::PLAYER1 ||
                        entities[y]->getEntityType() == rtype::ecs::entity::PLAYER2 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER4))) {
                            auto projectileCompo = entities[x]->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE);
                            auto shipCompo = entities[y]->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
                            shipCompo->setHealth(shipCompo->getHealth() - projectileCompo->getDamage());
                            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            if (shipCompo->getHealth() <= 0) {
                                entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                aliveCompo2->setAlive(false);
                            }
                            return;
                        } else if (entities[y]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && (entities[x]->getEntityType() == rtype::ecs::entity::PLAYER1 ||
                        entities[x]->getEntityType() == rtype::ecs::entity::PLAYER2 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER4)) {
                            auto projectileCompo = entities[y]->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE);
                            auto shipCompo = entities[x]->getComponent<ecs::component::IShip>(ecs::component::compoType::SHIP);
                            shipCompo->setHealth(shipCompo->getHealth() - projectileCompo->getDamage());
                            entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            if (shipCompo->getHealth() <= 0) {
                                entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                ecs::component::Alive *aliveCompo2 = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                aliveCompo2->setAlive(false);
                            }
                            return;
                        } else if (entities[x]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && entities[y]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE) {
                            auto projectileCompo = entities[y]->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE);
                            if (projectileCompo->getIsPoweredUp()) {
                                entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                aliveCompo->setAlive(false);
                                return;
                            }
                            entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            ecs::component::Alive *aliveCompo2 = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        } else if (entities[y]->getEntityType() == rtype::ecs::entity::ENEMY_PROJECTILE && entities[x]->getEntityType() == rtype::ecs::entity::ALLY_PROJECTILE) {
                            auto projectileCompo = entities[x]->getComponent<ecs::component::Projectile>(ecs::component::compoType::PROJECTILE);
                            if (projectileCompo->getIsPoweredUp()) {
                                entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                                ecs::component::Alive *aliveCompo = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                                aliveCompo->setAlive(false);
                                return;
                            }
                            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        } else if ((entities[x]->getEntityType() == rtype::ecs::entity::ENEMY && (entities[y]->getEntityType() == rtype::ecs::entity::PLAYER1 ||
                        entities[y]->getEntityType() == rtype::ecs::entity::PLAYER2 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER4)) || 
                        (entities[y]->getEntityType() == rtype::ecs::entity::ENEMY && (entities[x]->getEntityType() == rtype::ecs::entity::PLAYER1 ||
                        entities[x]->getEntityType() == rtype::ecs::entity::PLAYER2 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER4))) {
                            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        } else if ((entities[x]->getEntityType() == rtype::ecs::entity::PLAYER1 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER2 ||
                        entities[x]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER4) && entities[y]->getEntityType() == rtype::ecs::entity::PARTICLE) {
                            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            return;
                        } else if ((entities[y]->getEntityType() == rtype::ecs::entity::PLAYER1 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER2 ||
                        entities[y]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER4) && entities[x]->getEntityType() == rtype::ecs::entity::PARTICLE) {
                            entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo2 = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        } else if ((entities[x]->getEntityType() == rtype::ecs::entity::PLAYER1 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER2 ||
                        entities[x]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[x]->getEntityType() == rtype::ecs::entity::PLAYER4) && entities[y]->getEntityType() == rtype::ecs::entity::HEALTHBONUS) {
                            ecs::component::IShip *shipComponent = entities[x]->getComponent<ecs::component::IShip>(rtype::ecs::component::compoType::SHIP);
                            shipComponent->setMaxHealth(shipComponent->getMaxHealth() + 2);
                            shipComponent->setHealth(shipComponent->getHealth() + 2);
                            entities[y]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo = entities[y]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo->setAlive(false);
                            return;
                        } else if ((entities[y]->getEntityType() == rtype::ecs::entity::PLAYER1 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER2 ||
                        entities[y]->getEntityType() == rtype::ecs::entity::PLAYER3 || entities[y]->getEntityType() == rtype::ecs::entity::PLAYER4) && entities[x]->getEntityType() == rtype::ecs::entity::HEALTHBONUS) {
                            ecs::component::IShip *shipComponent = entities[y]->getComponent<ecs::component::IShip>(rtype::ecs::component::compoType::SHIP);
                            shipComponent->setMaxHealth(shipComponent->getMaxHealth() + 2);
                            shipComponent->setHealth(shipComponent->getHealth() + 2);
                            entities[x]->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::compoType::COLLIDE)->setCollide(false);
                            ecs::component::Alive *aliveCompo2 = entities[x]->getComponent<ecs::component::Alive>(ecs::component::compoType::ALIVE);
                            aliveCompo2->setAlive(false);
                            return;
                        }
                    }
                }
            }
        }
    }
}
