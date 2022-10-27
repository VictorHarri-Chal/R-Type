/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** sound.cpp
*/

#include "sound.hpp"

void rtype::ecs::system::SoundSystem::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{
    // for (auto &entity : entities) {
    //     if (entity->hasCompoType(rtype::ecs::component::compoType::SOUND)) {
    //         auto soundComponent = entity->getComponent<rtype::ecs::component::Sound>(rtype::ecs::component::SOUND);
    //         if (soundComponent->getPlay() == true) {
    //             float volume = soundComponent->getVolume();

    //             // rtype::raylib::Sound sound(soundComponent->getSoundPath());
    //             // sound.setVolume(sound.getVolume());
    //             sound.setVolume(volume);
    //             sound.play();
    //         }
    //     }
    // }
}

rtype::ecs::system::SystemType rtype::ecs::system::SoundSystem::getSystemType() const
{
    return (rtype::ecs::system::SystemType::SOUNDSYSTEM);
}
