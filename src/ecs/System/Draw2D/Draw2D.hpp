/**
 * @file Draw2D.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Draw2D system header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../../game/Game.hpp"
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
                 */
                void drawText(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine);

                /**
                 * @brief Draw rectangle with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the size and color.
                 * @param transformCompo the transform component of the entity with his position.
                 */
                void drawRectangle(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine);

                /**
                 * @brief Draw sprite with given properties.
                 *
                 * @param drawableCompo the drawable component of the entity with the size and color.
                 * @param transformCompo the transform component of the entity with his position.
                 */
                void drawSprite(rtype::ecs::component::Drawable2D drawableCompo, rtype::ecs::component::Transform transformCompo, rtype::Game *gameEngine);

                /**
                 * @brief Draw all given entities with Drawable2D component.
                 *
                 * @param entities all entities to draw.
                 */
                void update(std::vector<rtype::ecs::entity::Entity*> entities, rtype::Game*gameEngine) override;

                /**
                 * @brief Get the type of system.
                 *
                 * @return rtype::ecs::system::SystemType SystemType
                 */
                rtype::ecs::system::SystemType getSystemType() const override;

              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace rtype
