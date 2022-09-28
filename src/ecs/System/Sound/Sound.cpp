/**
 * @file Sound.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Sound system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Sound.hpp"

rtype::ecs::system::Sound::Sound()
{
}

rtype::ecs::system::Sound::~Sound()
{
}

rtype::ecs::system::SystemType rtype::ecs::system::Sound::getSystemType() const
{
    return (rtype::ecs::system::SystemType::SOUNDSYSTEM);
}

void rtype::ecs::system::Sound::update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(rtype::ecs::component::compoType::SOUND)) {
            auto soundComponent = entity->getComponent<rtype::ecs::component::Sound>(rtype::ecs::component::SOUND);
            if (soundComponent->getPlay() == true) {
                float volume = soundComponent->getVolume();

                // rtype::raylib::Sound sound(soundComponent->getSoundPath());
                // sound.setVolume(sound.getVolume());
                sound.setVolume(volume);
                sound.play();
            }
        }
    }
}
