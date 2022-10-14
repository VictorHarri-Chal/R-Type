/*
** EPITECH PROJECT, 2022
** Explodable (COMPONENT)
** File description:
** Explodable (COMPONENT)
*/

#ifndef EXPLODABLE_HPP_
#define EXPLODABLE_HPP_

#pragma once

#include <chrono>
#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            /**
             * @brief Explodable component
             */
            class Explodable : public IComponent {
              public:
                /**
                 * @brief Construct a new Explodable object
                 *
                 */
                Explodable();
                /**
                 * @brief Construct a new Explodable object
                 * 
                 * @param range Range of explosion
                 * @param explosionTime Time before explosion
                 */
                Explodable(float range, int explosionTime);
                /**
                 * @brief Destroy the Explodable object
                 *
                 */
                ~Explodable();
                /**
                 * @brief Get the Component Type object
                 * 
                 * @return rtype::ecs::component::compoType Type of component 
                 */
                rtype::ecs::component::compoType getType() const;
                /**
                 * @brief Set the range of explosion
                 * 
                 * @param range Range of explosion
                 */
                void setRange(float range);
                /**
                 * @brief Set the Explosion Time 
                 * 
                 * @param explosionTime Time before explosion
                 */
                void setExplosionTime(int explosionTime);
                /**
                 * @brief Set if component has exploded
                 * 
                 * @param exploded Boolean to define if component has exploded
                 */
                void setExploded(bool exploded);
                /**
                 * @brief Set if component explode on contact
                 * 
                 * @param explode Boolean to define if component explode on contact
                 */
                void setExplode(bool explode);
                /**
                 * @brief Set the Player Id
                 * 
                 * @param player Player Id
                 */
                void setPlayer(int player);
                /**
                 * @brief Get the range of explosion
                 * 
                 * @return float Range of explosion
                 */
                float getRange() const;
                /**
                 * @brief Get the Explosion Time
                 * 
                 * @return int Time before explosion
                 */
                int getExplosionTime() const;
                /**
                 * @brief Get if component has exploded
                 * 
                 * @return true True if component has exploded
                 * @return false False if component has not exploded
                 */
                bool getExploded() const;
                /**
                 * @brief Get if component explode on contact
                 * 
                 * @return true True if component explode on contact
                 * @return false False if component does not explode on contact
                 */
                bool getExplode() const;
                /**
                 * @brief Get the Player Id
                 * 
                 * @return int Player Id
                 */
                int getPlayer() const;
                /**
                 * @brief Get the start time of explosion
                 * 
                 * @return std::chrono::time_point<std::chrono::system_clock> 
                 */
                std::chrono::time_point<std::chrono::system_clock> getTStart() const;
                /**
                 * @brief Get the Seconds since explosion
                 * 
                 * @return std::chrono::seconds Seconds since explosion
                 */
                std::chrono::seconds getSeconds() const;

              private:
                /**
                 * @brief Range of explosion
                 * 
                 */
                float _range;
                /**
                 * @brief Time before explosion
                 * 
                 */
                int _explosionTime;
                /**
                 * @brief Boolean to define if component explode on contact
                 * 
                 */
                bool _explode;
                /**
                 * @brief Boolean to define if component has exploded
                 * 
                 */
                bool _exploded;
                /**
                 * @brief Chrono for explosion
                 * 
                 */
                std::chrono::time_point<std::chrono::system_clock> _tStart;
                /**
                 * @brief Seconds since explosion
                 * 
                 */
                std::chrono::seconds _seconds;
                /**
                 * @brief Player Id
                 * 
                 */
                int _player;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype

#endif /* !EXPLODABLE_HPP_ */
