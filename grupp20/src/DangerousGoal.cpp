#include "DangerousGoal.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"
#include "Ball.h"
#include <iostream>
#include <string>
#include <vector>



namespace grupp20{

    std::vector<DangerousGoal*> DangerousGoal::goalList;

    const std::vector<DangerousGoal*> DangerousGoal::getGoalList() { return goalList; }

    DangerousGoal::DangerousGoal(int x = 0, int y = 0) : Sprite(x, y, GOAL_SIZE, GOAL_SIZE, "wall.jpg"){
        goalList.push_back(this);
    }

    DangerousGoal::~DangerousGoal(){
        for(std::vector<DangerousGoal*>::iterator i = goalList.begin(); i != goalList.end();)
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

    void DangerousGoal::respawn(){
        int x = rand()% 210 + 200;
        int y = rand()% 210 + 200;

        std::cout << "Goal X:" << x << "Goal Y:" << y << std::endl;

        rect.x = x;
        rect.y = y;
    }

    DangerousGoal* DangerousGoal::Instantiate(int x = 0, int y = 0) {
        DangerousGoal* g = new DangerousGoal(x,y);
        ses.add(g);
		return g;
	}

    void DangerousGoal::destroy_balls(){
        for(Ball* b : Ball::getBalls()){
            b->reset();
        }
    }

   /* void DangerousGoal::collision(const GameObject* other){
        std::cout << "GOOOOOOAL!" << std::endl;
        //std::cout << "Score !"  << playerScore << std::endl;
        GameObject* a = const_cast<GameObject*>(other);
        Ball* b = dynamic_cast<Ball*>(a);

        if(b != nullptr)
            playerScore++;
            b->reset();
        
        //destroy_balls();
        respawn();
    }*/

    void DangerousGoal::tick() {
        //check collision
        const GameObject* other = GameObject::check_collision();
        if(other != nullptr)
            collision(other);
        
	}
}