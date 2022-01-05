#ifndef DANGEROUSWALL_H
#define DANGEROUSWALL_H

#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include "Ball.h"

#define GOAL_SIZE 100 //Målets storlek i pixlar

namespace grupp20{

    class DangerousWall : public Sprite{
    public:
        ~DangerousWall();
	    void tick();
        void collision(const GameObject*);
        static DangerousWall* Instantiate(int, int);
        void respawn();
        void destroy_balls();
        const static std::vector<DangerousWall*> getWallList();
    private:
        DangerousWall (int, int);
        static std::vector<DangerousWall*> wallList;
    };
    
}
#endif