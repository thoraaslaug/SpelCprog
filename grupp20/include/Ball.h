#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Sprite.h"
#include <string>

namespace grupp20{

    class Ball : public Sprite{

        public:
        Ball (int x, int y, int w, int h, std::string fileName) : Sprite(x, y, w, h, fileName) {}
        ~Ball() { Sprite::~Sprite(); }
	    //void draw() const;
	    void tick() {}
	    void mouseDown(int x, int y);
        static Ball* getInstance(int x, int y, int w, int h, std::string fileName);
    };
    
}
#endif
