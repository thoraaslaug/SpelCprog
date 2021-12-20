#include "Goal.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"
#include "Ball.h"
#include <iostream>
#include <string>
#include <vector>



namespace grupp20{

    std::vector<Goal*> Goal::goalList;

    const std::vector<Goal*> Goal::getGoalList() { return goalList; }

    Goal::Goal(int x = 0, int y = 0) : Sprite(x, y, GOAL_SIZE, GOAL_SIZE, "hoop.jpg"){
        goalList.push_back(this);
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
        int x = rand()% 210 + 200;
        int y = rand()% 210 + 200;

        std::cout << "Goal X:" << x << "Goal Y:" << y << std::endl;

        rect.x = x;
        rect.y = y;
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
        std::cout << "GOOOOOOAL!" << std::endl;
        
        GameObject* a = const_cast<GameObject*>(other);
        Ball* b = dynamic_cast<Ball*>(a);

        if(b != nullptr)
            b->reset();
        //destroy_balls();
        respawn();
    }

    void Goal::tick() {
        //check collision
        const GameObject* other = GameObject::check_collision();
        if(other != nullptr)
            collision(other);
        
	}
}