# ECS

## Getting started -> World

First, you have to create a rtype::ecs::world::World object. It will represent the object that contains all your Entities.

A world have 3 methodes :

- void addComponent(entity::Entity *entity); Add entity to world
- rtype::ecs::entity::Entity *getEntity(size_t id) const; Get the Entity of the given id
- std::vector<rtype::ecs::entity::Entity*> getEntities() const; Get the Entities vector with all entities

Example with simple world :

```
int main()
{
    rtype::ecs::world::World w;
    rtype::ecs::entity::Entity *e = new rtype::ecs::entity::Entity(rtype::ecs::entity::PLAYER);
    rtype::ecs::entity::Entity *b;
    rtype::ecs::entity::Entity *c;
    e->addComponent<rtype::ecs::component::Alive>(rtype::ecs::component::compoType::ALIVE, true);
    w.addComponent(e);
    b = w.getEntity(0);
    if (b->hasCompoType(rtype::ecs::component::compoType::ALIVE))
        std::cout << "B je suis vivant" << std::endl;
    b->remove(rtype::ecs::component::ALIVE);
    c = w.getEntity(0);
    if (!c->hasCompoType(rtype::ecs::component::compoType::ALIVE))
        std::cout << "C je suis mort" << std::endl;
    std::cout << "L'univers est un espace infini où s'entrechoque tous les hasards." << std::endl;
    return 0;
}
```

result :

B i'm alive

C i'm dead

## Next the Entity with her component

Next you will need rtype::ecs::entity::Entity object. It will represent the object that contains all your componenent.

A Entity have 5 methodes :

- bool hasCompoType(rtype::ecs::component::compoType type); Check if the entity have a component of the given type.
- void addComponent(component::compoType type, Args... args); Add component to entity.
- void remove(rtype::ecs::component::compoType type); Remove component to entity.
- T *getComponent(rtype::ecs::component::compoType type); Get the Component of the given type.
- rtype::ecs::entity::entityType getEntityType() const; Get the Entity Type

Components definition :


A Component must inherite from IComponent and have a method rtype::ecs::component::compoType getType() const ->
```
class ExampleComponent : public IComponent {
    public:
    ExampleComponent();
    ~ExampleComponent();

    rtype::ecs::component::compoType getType() const;

    protected:
    private:
};
```
Example :
```
#include <iostream>
#include "Entity.hpp"
#include "IComponent.hpp"

int main()
{
    rtype::ecs::entity::Entity Player;
    
    Player.addComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE, true);
    if (Player.hasCompoType(rtype::ecs::component::ALIVE))
        std::cout << "I have the alive component" << std::endl;
    std::cout << "Hp = " << Player.getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE) ->getAlive() << std::endl;
    std::cout << "Im setting alive to false" << std::endl;
    Player.getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::compoType::ALIVE)->setAlive(false);
    std::cout << "Hp = " << Player.getComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE) ->getAlive() << std::endl;
    std::cout << "I try to add an other alive component" << std::endl;
    Player.addComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE, true);
    if (Player.hasCompoType(rtype::ecs::component::ALIVE))
        std::cout << "It already exists" << std::endl;
    Player.remove(rtype::ecs::component::compoType::ALIVE);
    std::cout << "I removed the alive component" << std::endl;
    if (Player.hasCompoType(rtype::ecs::component::ALIVE))
        std::cout << "I still have the alive component" << std::endl;
    else
        std::cout << "I don't have anymore the alive component" << std::endl;
    std::cout << "I'm adding a new alive component" << std::endl;
    Player.addComponent<rtype::ecs::component::Alive>(rtype::ecs::component::ALIVE, true);
    if (Player.hasCompoType(rtype::ecs::component::ALIVE))
        std::cout << "I have the alive component" << std::endl;
    return 0;
}
```
result :

I have the alive component

Hp = 1

Im setting alive to false

Hp = 0

I try to add an other alive component

It already exists

I removed the alive component

I still have the alive component

I don't have anymore the alive component

I'm adding a new alive component

I have the alive component
