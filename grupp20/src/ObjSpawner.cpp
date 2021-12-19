#include "ObjSpawner.h"
#include "GameSession.h"
#include "Goal.h"

#include <iostream>
#include <string>

namespace grupp20{

    ObjSpawner::ObjSpawner() : GameObject(0,0,0,0){
        SpawnGoal(); 
    }

    void ObjSpawner::tick() {
        if(Goal::getGoalList().size() < 1){
            SpawnGoal();
        }
    }

    void ObjSpawner::SpawnGoal(){
        Goal* goal = Goal::Instantiate(0,0);
        ses.add(goal);
    }
}