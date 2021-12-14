#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Sprite.h"
#include "Ball.h"
#include <string>

namespace grupp20{

    class Player : public Sprite{
    public:
        Player(int x, int y, int w, int h, std::string fileName) : Sprite(x, y, w, h, fileName) { }
        ~Player() { Sprite::~Sprite(); }
	    //void draw() const;
	    void tick() {}
        void collision(const GameObject*) {}
	    void mouseDown(int x, int y);
        void ThrowBall(int, int);
    };

}

#endif