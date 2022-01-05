#ifndef GOAL_H
#define GOAL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"

#define GOAL_SIZE 150 //Målets storlek i pixlar

namespace grupp20{

    class Goal : public Sprite{
    public:
        ~Goal();
	    void tick();
        void collision(const GameObject*);
        static Goal* Instantiate(int, int);
        void respawn();
        void destroy_balls();
        void randomize_respawn(bool check) { randomizeRespawn = check; }
        const static std::vector<Goal*> getGoalList();
    private:
        Goal (int, int);
        static std::vector<Goal*> goalList;
        bool randomizeRespawn = false;
    };
    
}
#endif