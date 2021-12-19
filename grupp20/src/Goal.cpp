#include "Goal.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"
#include "ObjSpawner.h"
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

    Goal* Goal::Instantiate(int x = 0, int y = 0) {
        x = rand()% 210 + 200;
        y = rand()% 210 + 200; 

        std::cout << "X:" << x << " Y:" << y << std::endl;

        Goal* g = new Goal(x,y);
        
		return g;
	}

    void Goal::collision(const GameObject* other){
        std::cout << "GOOOOOOAL!" << std::endl;

        reset();
        
    }

    void Goal::tick() {
        //check collision
        const GameObject* other = GameObject::check_collision();
        if(other != nullptr)
            collision(other);
        
	}

    void Goal::reset(){
        //laugh at ball
        //wacky sound effects
        std::cout << "Ball destroyed" << std::endl;
        ObjSpawner::SpawnGoal(); //borde skicka med detta objekt för att instantieras. eller ta bort objspawner
        ses.remove(this);
    }
}