/*
** EPITECH PROJECT, 2022
** Sound (COMPONENT)
** File description:
** Sound (COMPONENT)
*/

#include "Sound.hpp"

rtype::ecs::component::Sound::Sound(std::string soundPath, bool play, float volume) : _soundPath(soundPath)
{
    this->_play = play;
    this->_volume = volume;
}

rtype::ecs::component::Sound::~Sound()
{
}

rtype::ecs::component::compoType rtype::ecs::component::Sound::getType() const
{
    return (rtype::ecs::component::compoType::SOUND);
}

std::string rtype::ecs::component::Sound::getSoundPath() const
{
    return (this->_soundPath);
}

/*rtype::raylib::Sound rtype::ecs::component::Sound::getSound() const
{
    return (this->_sound);
}*/

bool rtype::ecs::component::Sound::getPlay() const
{
    return (this->_play);
}

float rtype::ecs::component::Sound::getVolume() const
{
    return (this->_volume);
}

void rtype::ecs::component::Sound::setSoundPath(std::string soundPath)
{
    this->_soundPath = soundPath;
}

/*void rtype::ecs::component::Sound::setSound(std::string soundPath)
{
    this->_soundPath = soundPath;
    this->_sound = rtype::raylib::Sound(soundPath.c_str());
}*/

void rtype::ecs::component::Sound::setPlay(bool play)
{
    this->_play = play;
}

void rtype::ecs::component::Sound::setVolume(float volume)
{
    this->_volume = volume;
}

