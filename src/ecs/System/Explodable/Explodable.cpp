/**
 * @file Explodable.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Explodable system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Explodable.hpp"
#include <cmath>

indie::ecs::system::Explodable::Explodable()
{
}

indie::ecs::system::Explodable::~Explodable()
{
}

float indie::ecs::system::Explodable::getValue(float position, float index, char operand)
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

float indie::ecs::system::Explodable::getNewValue(float bombPos)
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

std::map<size_t, indie::ecs::entity::Entity *> indie::ecs::system::Explodable::getEntityByPosition(
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities, float x, float y)
{
    size_t count = 0;
    std::map<size_t, indie::ecs::entity::Entity *> map;
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::TRANSFORM) == true
            && entity->hasCompoType(indie::ecs::component::COLLECTABLE) == false) {
            if (entity->hasCompoType(indie::ecs::component::ALIVE)
                && entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)->getAlive()
                    == false) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
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

void indie::ecs::system::Explodable::destroyBoxes(std::vector<int> &compoToRemove,
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
    indie::ecs::component::Explodable *explodableCompo, indie::ecs::component::Transform *bombTransformCompo)
{
    float xPosition = getNewValue(bombTransformCompo->getX());
    float yPosition = getNewValue(bombTransformCompo->getY());

    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, (xPosition - i), yPosition);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(indie::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityXPosition >= xPosition + (-i - 2.0) && entityXPosition <= xPosition)
                && entityYPosition == yPosition) {
                entity->getComponent<indie::ecs::component::Destroyable>(indie::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
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
        if (type == indie::ecs::entity::PLAYER_1 || type == indie::ecs::entity::PLAYER_2
            || type == indie::ecs::entity::PLAYER_3 || type == indie::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index - count);
            }
        }
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, (xPosition + i), yPosition);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(indie::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityXPosition <= xPosition + (i + 2.0) && entityXPosition >= xPosition)
                && entityYPosition == yPosition) {
                entity->getComponent<indie::ecs::component::Destroyable>(indie::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
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
        if (type == indie::ecs::entity::PLAYER_1 || type == indie::ecs::entity::PLAYER_2
            || type == indie::ecs::entity::PLAYER_3 || type == indie::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index - count);
                count++;
            }
        }
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, xPosition, yPosition + i);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(indie::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityYPosition <= yPosition + (i + 2.0) && entityYPosition >= yPosition)
                && entityXPosition == xPosition) {
                entity->getComponent<indie::ecs::component::Destroyable>(indie::ecs::component::DESTROYABLE);
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                    compoToRemove.push_back(index);
                } else {
                    break;
                }
            }
        }
    }
    for (auto &index : compoToRemove) {
        auto type = entities.at(index - count)->getEntityType();
        if (type == indie::ecs::entity::PLAYER_1 || type == indie::ecs::entity::PLAYER_2
            || type == indie::ecs::entity::PLAYER_3 || type == indie::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index);
            }
        }
    }
    compoToRemove.clear();
    for (float i = 0, counter = 0.0; i < explodableCompo->getRange() + 2.0f; i += 2.0, counter += 2.0) {
        std::map<size_t, indie::ecs::entity::Entity *> entityMap;
        entityMap = getEntityByPosition(entities, xPosition, yPosition - i);
        if (entityMap.empty() == false) {
            size_t index = entityMap.begin()->first;
            indie::ecs::entity::Entity *entity = entityMap.begin()->second;
            if (entity->hasCompoType(indie::ecs::component::EXPLODABLE)) {
                continue;
            }
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            float entityXPosition = getNewValue(transformCompo->getX());
            float entityYPosition = getNewValue(transformCompo->getY());
            if ((entityYPosition >= yPosition + (-i - 2.0) && entityYPosition <= yPosition)
                && (entityXPosition >= xPosition)) {
                if (entity->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
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
        if (type == indie::ecs::entity::PLAYER_1 || type == indie::ecs::entity::PLAYER_2
            || type == indie::ecs::entity::PLAYER_3 || type == indie::ecs::entity::PLAYER_4) {
            entities.at(index - count)
                ->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            if (entities.at(index - count)->hasCompoType(indie::ecs::component::DESTROYABLE) == true) {
                entities.erase(entities.begin() + index - count);
                count++;
            }
        }
    }
    compoToRemove.clear();
}

void indie::ecs::system::Explodable::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    std::vector<int> compoToRemove;
    std::vector<indie::ecs::entity::Entity *> bombVector;

    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::EXPLODABLE) == true) {
            bombVector.push_back(entity.get());
        }
    }
    for (auto &entity : bombVector) {
        if (entity->hasCompoType(indie::ecs::component::compoType::EXPLODABLE) == true) {
            auto explodableCompo =
                entity->getComponent<ecs::component::Explodable>(ecs::component::compoType::EXPLODABLE);
            if (explodableCompo->getDropped() == true) {
                if (explodableCompo->getExplode() == true) {
                    explodableCompo->setExploded(true);
                    destroyBoxes(compoToRemove, entities, explodableCompo,
                        entity->getComponent<ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM));
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

indie::ecs::system::SystemType indie::ecs::system::Explodable::getSystemType() const
{
    return (indie::ecs::system::SystemType::EXPLODABLESYSTEM);
}