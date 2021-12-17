#include "ObjSpawner.h"
#include "GameSession.h"
#include "Goal.h"

#include <iostream>
#include <string>

namespace grupp20{

    std::vector<Goal*> ObjSpawner::goalList;


    ObjSpawner::ObjSpawner() : Sprite(0,0,0,0, ""){
        SpawnGoal(); 
    }

    int const ObjSpawner::getGoalList() { return goalList.size(); }

    void ObjSpawner::tick() {
        if(getGoalList() < 1){
            SpawnGoal();
        }
    }

    void ObjSpawner::SpawnGoal(){
        Goal* goal = Goal::Instantiate(0,0);
        goalList.push_back(goal);
        ses.add(goal);
    }
}