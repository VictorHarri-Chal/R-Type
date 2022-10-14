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

// Vector3 Vector3Add(Vector3 v1, Vector3 v2)
// {
//     Vector3 result = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};

//     return result;
// }

// bool rtype::ecs::system::CollideSystem::checkCollision(std::unique_ptr<rtype::ecs::entity::Entity> &entity,
//     std::unique_ptr<rtype::ecs::entity::Entity> &otherEntity, rtype::ecs::component::Collide *collide,
//     rtype::ecs::component::Collide *otherEntityCollide, std::vector<int> &compoToRemove, int &count)
// {
//     auto transform = entity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM);
//     auto otherTransform = otherEntity->getComponent<rtype::ecs::component::Transform>(rtype::ecs::component::TRANSFORM);

//     if (otherEntity->hasCompoType(rtype::ecs::component::ANIMATED)
//         && entity->hasCompoType(rtype::ecs::component::MODEL)) {
//         BoundingBox box1 = rtype::raylib::BoundingBox::getModelBox(
//             entity->getComponent<rtype::ecs::component::Object>(rtype::ecs::component::MODEL)->getModel());
//         BoundingBox box2 = rtype::raylib::BoundingBox::getModelBox(
//             otherEntity->getComponent<rtype::ecs::component::Object>(rtype::ecs::component::ANIMATED)->getModel());
//         box1.min = {transform->getX() - 0.2f, transform->getY() - 0.2f, 0.0f};
//         box1.max = {transform->getX() + 0.2f, transform->getY() + 0.2f, 0.0f};
//         box2.min = {otherTransform->getX() - 0.2f, otherTransform->getY() - 0.2f, 0.0f};
//         box2.max = {otherTransform->getX() + 0.2f, otherTransform->getY() + 0.2f, 0.0f};
//         if (rtype::raylib::BoundingBox::checkCollisionBoxes(box1, box2) == true) {
//             if (entity->hasCompoType(rtype::ecs::component::COLLECTABLE) == true) {
//                 otherEntity->getComponent<rtype::ecs::component::Inventory>(rtype::ecs::component::INVENTORY)
//                     ->setBonus(
//                         entity->getComponent<rtype::ecs::component::Collectable>(rtype::ecs::component::COLLECTABLE)
//                             ->getBonusType());
//                 compoToRemove.push_back(count);
//             }
//         }
//     }
//     if (otherEntity->hasCompoType(rtype::ecs::component::ANIMATED)
//         && entity->hasCompoType(rtype::ecs::component::DRAWABLE3D)) {
//         auto drawable = entity->getComponent<rtype::ecs::component::Drawable3D>(rtype::ecs::component::DRAWABLE3D);
//         Vector3 min = {transform->getX() - drawable->getWidth() / static_cast<float>(2.0),
//             transform->getY() - drawable->getHeight() / static_cast<float>(2.0),
//             -(drawable->getLength() / static_cast<float>(2.0))};
//         Vector3 max = {transform->getX() + drawable->getWidth() / static_cast<float>(2.0),
//             transform->getY() + drawable->getHeight() / static_cast<float>(2.0),
//             drawable->getLength() / static_cast<float>(2.0)};
//         rtype::raylib::BoundingBox box1(min, max);
//         BoundingBox box2 = GetModelBoundingBox(
//             otherEntity->getComponent<rtype::ecs::component::Object>(rtype::ecs::component::ANIMATED)->getModel());
//         Vector3 min2 = {otherTransform->getX(), otherTransform->getY(), 0.0f};
//         Vector3 max2 = {otherTransform->getX(), otherTransform->getY() - 2.0f, 0.0f};
//         if (otherEntity->getComponent<rtype::ecs::component::Object>(rtype::ecs::component::ANIMATED)->getOrientation()
//             == static_cast<float>(rtype::ecs::component::Object::NORTH)) {
//             min2.y = min2.y - 0.5f;
//         }
//         if (otherEntity->getComponent<rtype::ecs::component::Object>(rtype::ecs::component::ANIMATED)->getOrientation()
//             == static_cast<float>(rtype::ecs::component::Object::SOUTH)) {
//             max2.y = max2.y + 0.5f;
//         }
//         box2.min = Vector3Add(box2.min, min2);
//         box2.max = Vector3Add(box2.max, max2);
//         if (rtype::raylib::BoundingBox::checkCollisionBoxes(box2, box1.getBoundingBox()) == true) {
//             collide->setCollide(true);
//             otherEntityCollide->setCollide(true);
//             if (otherTransform->getSpeedX() > 0.0)
//                 otherTransform->setX(otherTransform->getX() - otherTransform->getSpeedX());
//             if (otherTransform->getSpeedX() < 0.0)
//                 otherTransform->setX(otherTransform->getX() - otherTransform->getSpeedX());
//             if (otherTransform->getSpeedY() > 0.0)
//                 otherTransform->setY(otherTransform->getY() - otherTransform->getSpeedY());
//             if (otherTransform->getSpeedY() < 0.0)
//                 otherTransform->setY(otherTransform->getY() - otherTransform->getSpeedY());
//             return (true);
//         }
//     }
//     return (false);
// }

void rtype::ecs::system::CollideSystem::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{
    // int count = 0;
    // std::vector<int> compoToRemove;

    // for (auto &entity : entities) {
    //     if (entity->hasCompoType(ecs::component::compoType::COLLIDE) == true) {
    //         rtype::ecs::component::Collide *collide =
    //             entity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
    //         auto transformCompo = entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
    //         for (auto &otherEntity : entities) {
    //             if (otherEntity != entity && otherEntity->hasCompoType(rtype::ecs::component::compoType::COLLIDE)) {
    //                 checkCollision(entity, otherEntity,
    //                     entity->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::COLLIDE),
    //                     otherEntity->getComponent<rtype::ecs::component::Collide>(rtype::ecs::component::COLLIDE),
    //                     compoToRemove, count);
    //             }
    //         }
    //     }
    //     count++;
    // }

    // size_t i = 0;
    // for (auto &index : compoToRemove) {
    //     entities.erase(entities.begin() + index - i);
    //     i++;
    // }
    (void) entities;
    (void) gameEngine;
}
