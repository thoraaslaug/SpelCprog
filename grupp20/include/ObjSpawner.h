#ifndef OBJSPAWNER_H
#define OBJSPAWNER_H

#include "GameObject.h"
#include "Sprite.h"
#include "Goal.h"
#include <string>
#include <vector>

namespace grupp20{

    class ObjSpawner : public Sprite{
    public:
        ObjSpawner();
        ~ObjSpawner() { Sprite::~Sprite(); }
        static void SpawnGoal();
        void tick();
        int const getGoalList();
        
    private:
        static std::vector<Goal*> goalList;
    
};
}

#endif