#include "DangerousWall.h"
#include "GameSession.h"
#include "Player.h"
#include "System.h"
#include "Ball.h"
#include <iostream>
#include <string>
#include <vector>



namespace grupp20{

    std::vector<DangerousWall*> DangerousWall::wallList;

    const std::vector<DangerousWall*> DangerousWall::getWallList() { return wallList; }

    DangerousWall::DangerousWall(int x = 0, int y = 0) : Sprite(x, y, GOAL_SIZE, GOAL_SIZE, "wall.jpg"){
        wallList.push_back(this);
    }

    DangerousWall::~DangerousWall(){
        for(std::vector<DangerousWall*>::iterator i = wallList.begin(); i != wallList.end();)
        {
            if(*i == this){
                i = wallList.erase(i);
                break;
            }
            else{
                i++;
            }
        }

        Sprite::~Sprite();
    }

    void DangerousWall::respawn(){
        int x = rand()% 210 + 200;
        int y = rand()% 210 + 200;

        std::cout << "Goal X:" << x << "Goal Y:" << y << std::endl;

        rect.x = x;
        rect.y = y;
    }

    DangerousWall* DangerousWall::Instantiate(int x = 0, int y = 0) {
        DangerousWall* game = new DangerousWall(x,y);
        ses.add(game);
		return game;
	}

    void DangerousWall::destroy_balls(){
        for(Ball* ball : Ball::getBalls()){
            ball->reset();
        }
    }

    void DangerousWall::collision(const GameObject* other){
        
        GameObject* gameO = const_cast<GameObject*>(other);
        Ball* ball = dynamic_cast<Ball*>(gameO);

        if(ball != nullptr)
            ball->reset();
        destroy_balls();
        respawn();
    }

    void DangerousWall::tick() {
        //check collision
        const GameObject* other = GameObject::check_collision();
        if(other != nullptr)
            collision(other);
        
	}
}