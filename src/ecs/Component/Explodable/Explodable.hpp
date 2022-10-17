/*
** EPITECH PROJECT, 2022
** Explodable (COMPONENT)
** File description:
** Explodable (COMPONENT)
*/

#pragma once

#include <chrono>
#include "../IComponent.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace component
        {
            class Explodable : public IComponent {
              public:
                Explodable();
                Explodable(float range, int explosionTime);
                ~Explodable();

                rtype::ecs::component::compoType getType() const;
                void setRange(float range);
                void setExplosionTime(int explosionTime);
                void setExploded(bool exploded);
                void setExplode(bool explode);
                void setPlayer(int player);
                float getRange() const;
                int getExplosionTime() const;
                bool getExploded() const;
                bool getExplode() const;
                int getPlayer() const;
                std::chrono::time_point<std::chrono::system_clock> getTStart() const;
                std::chrono::seconds getSeconds() const;

              private:
                float _range;
                int _explosionTime;
                bool _explode;
                bool _exploded;
                std::chrono::time_point<std::chrono::system_clock> _tStart;
                std::chrono::seconds _seconds;
                int _player;
            };
        } // namespace component
    }     // namespace ecs
} // namespace rtype
