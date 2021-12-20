#ifndef WALL_H
#define WALL_H

#include "Sprite.h"

namespace grupp20{

    class Wall : public Sprite{
    public:
        Wall(int x, int y, int w, int h) : Sprite(x, y, w, h, "wall.jpg") {}
        ~Wall(){ Sprite::~Sprite(); }
        void tick();
        void collision(const GameObject*);
    private:
    };
}

#endif