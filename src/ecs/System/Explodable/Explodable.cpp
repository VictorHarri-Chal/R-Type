/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Explodable.cpp
*/

#include "Explodable.hpp"
#include <cmath>

rtype::ecs::system::Explodable::Explodable()
{
}

rtype::ecs::system::Explodable::~Explodable()
{
}

float rtype::ecs::system::Explodable::getValue(float position, float index, char operand)
{
    while (1) {
        float test = std::fmod(static_cast<float>(position), 2.0f);
        if (test >= 0.01 || test <= -0.01) {
            if (operand == '+') {
                position += 0.01f;
            } else {
                position -= 0.01f;
            }
        } else {
            break;
        }
    }
    return (position);
}

float rtype::ecs::system::Explodable::getNewValue(float bombPos)
{
    float position = 0.0;
    float position2 = 0.0;
    float newPosition = bombPos;
    if (std::fmod(bombPos, 0.5f) != 0.0) {
        position = getValue(bombPos, 0.5, '+');
        position2 = getValue(bombPos, -0.5, '-');
        float f;
        float f2;
        f2 = std::modf(position, &f);
        if (std::abs(f2) <= 0.1) {
            position = position - f2;
        }
        f2 = std::modf(position2, &f);
        if (std::abs(f2) <= 0.1) {
            position2 = position2 - f2;
        }
        if ((std::abs(bombPos - position)) < (std::abs(bombPos - position2))) {
            newPosition = position;
        } else {
            newPosition = position2;
        }
    }
    return (newPosition);
}

std::map<size_t, rtype::ecs::entity::Entity *> rtype::ecs::system::Explodable::getEntityByPosition(
    std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> &entities, float x, float y)
{
    size_t count = 0;
    std::map<size_t, rtype::ecs::entity::Entity *> map;
    for (auto &entity : entities) {
        if (entity->hasCompoType(rtype::ecs::component::TRANSFORM) == true
            && entity->hasCompoType(rtype::ecs::component::COLLECTABLE) == false) {
            if (entity->hasCompoType(rtype::ecs::component::ALIVE)
                && entity->getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE)->getAlive()
                    == false) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM);
            float xPosition = getNewValue(transformCompo->getX());
            float yPosition = getNewValue(transformCompo->getY());
            if (xPosition == x && yPosition == y) {
                map.emplace(count, entity.get());
                return (map);
            }
        }
        count++;
    }
    return (map);
}

void rtype::ecs::system::Explodable::destroyBoxes(std::vector<int> &compoToRemove,
    std::vector<std::unique_ptr<rtype::ecs::entity::Entity>> &entities,
    rtype::ecs::component::Explodable *explodableCompo, rtype::ecs::component::Transform *bombTransformCompo)
{
    float xPosition = getNewValue(bombTransformCompo->getX());
    float yPosition = getNewValue(bombTransformCompo->getY());

    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, rtype::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, (xPosition - i), yPosition);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            rtype::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(rtype::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityXPosition >= xPosition + (-i - 2.0) && entityXPosition <= xPosition)
                && entityYPosition == yPosition) {
                entity->getComponent<rtype::ecs::component::Destroyable>(rtype::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    size_t count = 0;
    for (auto &index : compoToRemove) {
        auto type = entities.at(index - count)->getEntityType();
        if (type == rtype::ecs::entity::PLAYER_1 || type == rtype::ecs::entity::PLAYER_2
            || type == rtype::ecs::entity::PLAYER_3 || type == rtype::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index - count);
            }
        }
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, rtype::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, (xPosition + i), yPosition);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            rtype::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(rtype::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityXPosition <= xPosition + (i + 2.0) && entityXPosition >= xPosition)
                && entityYPosition == yPosition) {
                entity->getComponent<rtype::ecs::component::Destroyable>(rtype::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    count = 0;
    for (auto &index : compoToRemove) {
        auto type = entities.at(index - count)->getEntityType();
        if (type == rtype::ecs::entity::PLAYER_1 || type == rtype::ecs::entity::PLAYER_2
            || type == rtype::ecs::entity::PLAYER_3 || type == rtype::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index - count);
                count++;
            }
        }
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, rtype::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, xPosition, yPosition + i);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            rtype::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(rtype::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityYPosition <= yPosition + (i + 2.0) && entityYPosition >= yPosition)
                && entityXPosition == xPosition) {
                entity->getComponent<rtype::ecs::component::Destroyable>(rtype::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    for (auto &index : compoToRemove) {
        auto type = entities.at(index - count)->getEntityType();
        if (type == rtype::ecs::entity::PLAYER_1 || type == rtype::ecs::entity::PLAYER_2
            || type == rtype::ecs::entity::PLAYER_3 || type == rtype::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index);
            }
        }
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, rtype::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, xPosition, yPosition - i);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            rtype::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(rtype::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityYPosition >= yPosition + (-i - 2.0) && entityYPosition <= yPosition)
                && (entityXPosition >= xPosition)) {
                if (entity->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    count = 0;
    for (auto &index : compoToRemove) {
        auto type = entities.at(index - count)->getEntityType();
        if (type == rtype::ecs::entity::PLAYER_1 || type == rtype::ecs::entity::PLAYER_2
            || type == rtype::ecs::entity::PLAYER_3 || type == rtype::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(rtype::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index - count);
                count++;
            }
        }
    }
    compoToRemove.clear();
}

void rtype::ecs::system::Explodable::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{
    std::vector<int> compoToRemove;
    std::vector<rtype::ecs::entity::Entity *> bombVector;

    for (auto &entity : entities) {
        if (entity->hasCompoType(rtype::ecs::component::compoType::EXPLODABLE) == true) {
            bombVector.push_back(entity.get());
        }
    }
    for (auto &entity : bombVector) {
        if (entity->hasCompoType(rtype::ecs::component::compoType::EXPLODABLE) == true) {
            auto explodableCompo =
                entity->getComponent<ecs::component::Explodable>(ecs::component::compoType::EXPLODABLE);
            if (explodableCompo->getDropped() == true) {
                if (explodableCompo->getExplode() == true) {
                    explodableCompo->setExploded(true);
                    destroyBoxes(compoToRemove, entities, explodableCompo,
                        entity->getComponent<ecs::component::Transform>(rtype::ecs::component::compoType::TRANSFORM));
                } else {
                    auto t_now = std::chrono::system_clock::now();
                    std::chrono::seconds elapsed =
                        std::chrono::duration_cast<std::chrono::seconds>(t_now - explodableCompo->getTStart());
                    if (explodableCompo->getSeconds() <= elapsed) {
                        explodableCompo->setExplode(true);
                    }
                }
            }
        }
    }
}

rtype::ecs::system::SystemType rtype::ecs::system::Explodable::getSystemType() const
{
    return (rtype::ecs::system::SystemType::EXPLODABLESYSTEM);
}