/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Game.cpp
*/

#include "Game.hpp"
#include "../ecs/System/Movement/movement.hpp"
#include "../ecs/System/Collide/collide.hpp"
#include "../ecs/System/Enemypath/enemypath.hpp"
#include "../ecs/System/Particles/particles.hpp"
#include "../exceptions/ScreensExceptions.hpp"

rtype::Game::Game()
{

}

void rtype::Game::init()
{
    rtype::ecs::system::ISystem *movementSystem = new rtype::ecs::system::MovementSystem();
    if (movementSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating MovementSystem");
    this->_world.addSystem(movementSystem);
    rtype::ecs::system::ISystem *collideSystem = new rtype::ecs::system::CollideSystem();
    if (collideSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating CollideSystem");
    this->_world.addSystem(collideSystem);
    rtype::ecs::system::ISystem *enemypathSystem = new rtype::ecs::system::EnemypathSystem();
    if (enemypathSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating EnemypathSystem");
    this->_world.addSystem(enemypathSystem);
    rtype::ecs::system::ISystem *particleSystem = new rtype::ecs::system::ParticlesSystem();
    if (particleSystem == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating ParticleSystem");
    this->_world.addSystem(particleSystem);


    rtype::ecs::entity::Entity *ship = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER1);
    if (ship == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
    ship->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 50.f, 0.0f, 0.0f);
    ship->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    ship->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    ship->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
    ship->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 0, 33, 17));
    this->_world.addEntity(ship);
    rtype::ecs::entity::Entity *ship2 = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER2);
    if (ship2 == nullptr)
        throw ScreensExceptions("CoreScreen: Error while creating Entity (5)");
    ship2->addComponent<ecs::component::Transform>(rtype::ecs::component::TRANSFORM, 500.f, 200.f, 0.0f, 0.0f);
    ship2->addComponent<ecs::component::Collide>(rtype::ecs::component::COLLIDE);
    ship2->addComponent<ecs::component::Alive>(rtype::ecs::component::ALIVE);
    ship2->addComponent<ecs::component::Recruit>(rtype::ecs::component::SHIP);
    ship2->addComponent<ecs::component::Drawable2D>(rtype::ecs::component::DRAWABLE2D, "assets/ships.png", true, sf::Vector2f(4.f, 4.f), 0, sf::IntRect(0, 17, 33, 17));
    this->_world.addEntity(ship2);
}

void rtype::Game::update(void)
{
    this->_world.update();
}