/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** draw2d.hpp
*/

#pragma once

#include "../../../sfml/Sfml.hpp"
#include "../../../client/game/Game.hpp"
#include "../ISystem.hpp"

namespace rtype
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Draw2D system
            class Draw2DSystem : public ISystem {
              public:
                /**
                 * @brief Create new draw 2d system.
                 */
                Draw2DSystem() {}
                /**
                 * @brief Destroy draw 2d system.
                 */
                ~Draw2DSystem() {}
                /**
                 * @brief Draw text with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the text and color.
                 * @param transformCompo the transform component of the entity with his position.
                 * @param gameEngine the game engine.
                 */
                void drawText(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine);

                /**
                 * @brief Draw rectangle with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the size and color.
                 * @param transformCompo the transform component of the entity with his position.
                 * @param gameEngine the game engine.
                 */
                void drawRectangle(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine);

                /**
                 * @brief Draw sprite with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the size and color.
                 * @param transformCompo the transform component of the entity with his position.
                 * @param gameEngine the game engine.
                 */
                void drawSprite(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine);

                /**
                 * @brief Draw all given entities with Drawable2D component.
                 *
                 * @param entities all entities to draw.
                 * @param gameEngine the game engine.
                 */
                void update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine) override;
                /**
                 * @brief Handle and modify sprites rect to manage animations.
                 *
                 * @param entities Vector of entities
                 */
                void animations(std::vector<rtype::ecs::entity::Entity*> entities);
                /**
                 * @brief Get the type of system.
                 *
                 * @return rtype::ecs::system::SystemType the type of system.
                 */
                rtype::ecs::system::SystemType getSystemType() const override;

              private:
                sf::Clock _allyClock;
                sf::Clock _zigzagClock;
                sf::Clock _rusherClock;
                sf::Clock _turretClock;
                sf::Clock _kamikazeClock;

            };
        } // namespace system
    }     // namespace ecs
} // namespace rtype
