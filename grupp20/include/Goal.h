#ifndef GOAL_H
#define GOAL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"

#define GOAL_SIZE 150 //Målets storlek i pixlar

namespace grupp20{

    class Goal : public Sprite{
    public:
        Goal (int, int);
        ~Goal() { Sprite::~Sprite(); }
	    void tick();
        void collision(const GameObject*);
        static Goal* Instantiate(int, int);
        void reset();
    private:
        
    };
    
}
#endif