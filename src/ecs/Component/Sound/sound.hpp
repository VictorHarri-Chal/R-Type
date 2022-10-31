/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** sound.hpp
*/

#pragma once

#include <string>
#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Class for the Sound component
             *
             */
            class Sound : public IComponent {
              public:
                /**
                 * @brief Construct a new Sound object
                 *
                 * @param soundPath Path to the sound file
                 * @param play True if the sound should be played
                 * @param volume Volume of the sound
                 */
                Sound(std::string soundPath, bool play, float volume = 1.0f);
                /**
                 * @brief Destroy the Sound object
                 *
                 */
                ~Sound();

                /**
                 * @brief Get the Type object
                 *
                 * @return rtype::ecs::component::compoType The type of the component
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Get the Sound Path object
                 *
                 * @return std::string The path to the sound file
                 */
                std::string getSoundPath() const;
                // rtype::raylib::Sound getSound() const;
                /**
                 * @brief Get if the sound is played
                 *
                 * @return bool True if the sound is played
                 */
                bool getPlay() const;
                /**
                 * @brief Get the volume of the sound
                 *
                 * @return float The volume of the sound
                 */
                float getVolume() const;
                /**
                 * @brief Set the Sound Path
                 *
                 * @param soundPath path to the sound file
                 */
                void setSoundPath(std::string soundPath);
                /**
                 * @brief Set the sound to be played
                 *
                 * @param soundPath Sound to be played
                 */
                void setSound(std::string soundPath);
                /**
                 * @brief Set if the sound is played
                 *
                 * @param play True if the sound is played, false otherwise
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
                 * @brief Boolean if the sound is played or not
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
