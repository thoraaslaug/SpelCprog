#ifndef DANGEROUSGOAL_H
#define DANGEROUSGOAL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"

#define GOAL_SIZE 150 //Målets storlek i pixlar

namespace grupp20{

    class DangerousGoal : public Sprite{
    public:
        ~DangerousGoal();
	    void tick();
        void collision(const GameObject*);
        static DangerousGoal* Instantiate(int, int);
        void respawn();
        void destroy_balls();
        const static std::vector<DangerousGoal*> getGoalList();
    private:
        DangerousGoal (int, int);
        int playerScore = 0;
        static std::vector<DangerousGoal*> goalList;
    };
    
}
#endif