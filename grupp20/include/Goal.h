#ifndef GOAL_H
#define GOAL_H

#include "GameObject.h"
#include "ObjSpawner.h"
#include "Sprite.h"
#include "Player.h"

#define GOAL_SIZE 150 //Målets storlek i pixlar

namespace grupp20{

    class Goal : public Sprite{
    public:
        Goal (int, int);
        ~Goal();
	    void tick();
        void collision(const GameObject*);
        static Goal* Instantiate(int, int);
        void reset();
        const static std::vector<Goal*> getGoalList();
    private:
        static std::vector<Goal*> goalList;
    };
    
}
#endif