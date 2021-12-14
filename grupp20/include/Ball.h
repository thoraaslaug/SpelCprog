#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Sprite.h"
#include <string>

#define BALL_SIZE 50 //bollstorlek i pixlar

namespace grupp20{

    class Ball : public Sprite{

    public:
        Ball (int x, int y) : Sprite(x, y, BALL_SIZE, BALL_SIZE, "ball.jpg") {}
        ~Ball() { Sprite::~Sprite(); }
	    void tick();
        void collision(const GameObject*);
        static Ball* Instatiate(int x, int y) { return new Ball(x, y); }

    private:
        int counter;
    };
    
}
#endif
