/*
** EPITECH PROJECT, 2022
** Sound (COMPONENT)
** File description:
** Sound (COMPONENT)
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
            /**
             * @brief Sound component
             *
             */
            class Sound : public IComponent {
              public:
                /**
                 * @brief Construct a new Sound object
                 *
                 * @param soundPath Path to the sound file
                 * @param play true if the sound must be played
                 * @param volume Volume of the sound
                 */
                Sound(std::string soundPath, bool play, float volume = 1.0f);
                /**
                 * @brief Destroy Sound object
                 *
                 */
                ~Sound();
                /**
                 * @brief Get the Type object
                 *
                 * @return rtype::ecs::component::compoType Type of the component
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Sound Path of the file
                 *
                 * @return std::string Path to the sound file
                 */
                std::string getSoundPath() const;
                // rtype::raylib::Sound getSound() const;
                /**
                 * @brief Get if the sound must be played or not
                 *
                 * @return true if the sound must be played
                 * @return false if the sound must not be played
                 */
                bool getPlay() const;
                /**
                 * @brief Get the volume of the sound
                 * 
                 * @return float Volume of the sound
                 */
                float getVolume() const;
                /**
                 * @brief Set the Sound Path of the file
                 *
                 * @param soundPath Path to the sound file
                 */
                void setSoundPath(std::string soundPath);
                /**
                 * @brief Set the sound path for the sound
                 * 
                 * @param soundPath 
                 */
                void setSound(std::string soundPath);
                /**
                 * @brief Set if the sound must be played or not
                 *
                 * @param play true if the sound must be played
                 * @param play false if the sound must not be played
                 */
                void setPlay(bool play);
                /**
                 * @brief Set the volume of the sound
                 * 
                 * @param volume Volume of the sound
                 */
                void setVolume(float volume);

              private:
                /**
                 * @brief Path to the sound file
                 * 
                 */
                std::string _soundPath;
                /**
                 * @brief Boolean to define if the sound must be played or not
                 * 
                 */
                bool _play;
                /**
                 * @brief Volume of the sound
                 * 
                 */
                float _volume;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !SOUND_HPP_ */
