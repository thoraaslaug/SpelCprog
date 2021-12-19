#ifndef OBJSPAWNER_H
#define OBJSPAWNER_H

#include "GameObject.h"
#include "Sprite.h"
#include "Goal.h"
#include <string>
#include <vector>

//poänglös klass??

namespace grupp20{

    class ObjSpawner : public GameObject{
    public:
        ObjSpawner();
        ~ObjSpawner() { GameObject::~GameObject(); }
        static void SpawnGoal();
        void tick();
        void draw() const{}
        void collision(const GameObject*){}
    private:
    };
}

#endif