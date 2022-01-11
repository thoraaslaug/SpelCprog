//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Sprite.h"
#include "Ball.h"
#include <string>
#include <vector>

namespace grupp20{

    class Player : public Sprite{
    public:
        Player(int x, int y, int w, int h, std::string fileName);
        ~Player();
        static const std::vector<Player*> getPlayers();
    private:
	    void mouseDown(int x, int y);
	    void tick() {}
        void collision(const GameObject*) {}
        void ThrowBall();
        static std::vector<Player*> players;
        int getCenterX(){
            return rect.w/2 + rect.x;
        }
        int getCenterY(){
            return rect.h/2 + rect.y;
        }
    };
}

#endif