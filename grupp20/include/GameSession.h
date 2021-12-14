#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <vector>
#include "GameObject.h"

namespace grupp20
{
    class GameSession
    {
    public:
        void run();
        void add(GameObject*);
        void remove(GameObject*);
    private:
        std::vector<GameObject*> gameObjects;
        std::vector<GameObject*> added, removed;

        friend const GameObject* GameObject::check_collision();
    };

    extern GameSession ses;
}

#endif