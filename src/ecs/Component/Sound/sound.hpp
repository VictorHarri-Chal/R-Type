/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** sound.hpp
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <string>
#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Sound : public IComponent {
              public:
                Sound(std::string soundPath, bool play, float volume = 1.0f);
                ~Sound();

                rtype::ecs::component::compoType getType() const;
                std::string getSoundPath() const;
                // rtype::raylib::Sound getSound() const;
                bool getPlay() const;
                float getVolume() const;
                void setSoundPath(std::string soundPath);
                void setSound(std::string soundPath);
                void setPlay(bool play);
                void setVolume(float volume);

              private:
                std::string _soundPath;
                bool _play;
                float _volume;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !SOUND_HPP_ */
