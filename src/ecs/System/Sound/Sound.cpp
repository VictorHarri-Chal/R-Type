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

indie::ecs::system::Sound::Sound()
{
}

indie::ecs::system::Sound::~Sound()
{
}

indie::ecs::system::SystemType indie::ecs::system::Sound::getSystemType() const
{
    return (indie::ecs::system::SystemType::SOUNDSYSTEM);
}

void indie::ecs::system::Sound::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::SOUND)) {
            auto soundComponent = entity->getComponent<indie::ecs::component::Sound>(indie::ecs::component::SOUND);
            if (soundComponent->getPlay() == true) {
                float volume = soundComponent->getVolume();

                indie::raylib::Sound sound(soundComponent->getSoundPath());
                // sound.setVolume(sound.getVolume());
                sound.setVolume(volume);
                sound.play();
            }
        }
    }
}
