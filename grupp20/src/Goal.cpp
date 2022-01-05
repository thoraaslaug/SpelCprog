#include "Goal.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"
#include "Ball.h"
#include <iostream>
#include <string>
#include <vector>

#define RESPAWN_AREA 200

namespace grupp20{

    std::vector<Goal*> Goal::goalList;

    const std::vector<Goal*> Goal::getGoalList() { return goalList; }

    Goal::Goal(int x = 0, int y = 0) : Sprite(x, y, GOAL_SIZE, GOAL_SIZE, "hoop.jpg"){
        goalList.push_back(this);
        XOrigin = x;
        YOrigin = y;
    }

    Goal::~Goal(){
        for(std::vector<Goal*>::iterator i = goalList.begin(); i != goalList.end();)
        {
            if(*i == this){
                i = goalList.erase(i);
                break;
            }
            else{
                i++;
            }
        }

        Sprite::~Sprite();
    }

    void Goal::respawn(){
        int x = rect.x;
        int y = rect.y;

        

        if(randomizeRespawn){
            int Xrangemin = XOrigin - RESPAWN_AREA;
            int Yrangemin = YOrigin - RESPAWN_AREA;
            int Xrangemax = XOrigin + RESPAWN_AREA;
            int Yrangemax = YOrigin + RESPAWN_AREA;

            x = rand()% Xrangemax + Xrangemin;
            y = rand()% Yrangemax + Yrangemin;

            std::cout << "Goal X:" << x << "Goal Y:" << y << std::endl;
            rect.x = x;
            rect.y = y;
        }
        else{
            rect.x = XOrigin;
            rect.y = YOrigin;
        }

    }

    Goal* Goal::Instantiate(int x = 0, int y = 0) {
        Goal* g = new Goal(x,y);
        ses.add(g);
		return g;
	}

    void Goal::destroy_balls(){
        for(Ball* b : Ball::getBalls()){
            b->reset();
        }
    }

    void Goal::collision(const GameObject* other){
        
        GameObject* a = const_cast<GameObject*>(other);
        Ball* b = dynamic_cast<Ball*>(a);

        if(b != nullptr){
            b->reset();
            std::cout << "GOOOOOOAL!" << std::endl;
            }
        //destroy_balls();
        respawn();
    }

    void Goal::tick() {
        //check collision
        const GameObject* other = GameObject::check_collision();
        if(other != nullptr)
            collision(other);

        move();
	}
}