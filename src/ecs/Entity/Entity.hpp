/*
** EPITECH PROJECT, 2022
** Entity (ECS)
** File description:
** Entity (ECS)
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

namespace rtype
{
    namespace ecs
    {
        namespace entity
        {
            enum entityType { PLAYER_1, PLAYER_2, PLAYER_3, PLAYER_4, TEXT, MISSILE, UNKNOWN };
            class Entity {
                public:
                    Entity();
                    Entity(entityType type);
                    ~Entity();
                    rtype::ecs::entity::entityType getEntityType() const;

                protected:
                private:
                    entity::entityType _type;
            };
        }
    }
}


#endif /* !ENTITY_HPP_ */
