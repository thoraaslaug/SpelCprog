//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#ifndef WALL_H
#define WALL_H
#include <string>

#include "Sprite.h"

namespace grupp20{

    class Wall : public Sprite{
    public:
        Wall(int x, int y, int w, int h) : Sprite(x, y, w, h, "Wall.png") {}
        Wall(int x, int y, int w, int h, std::string s) : Sprite(x, y, w, h, s) {}
        ~Wall(){ Sprite::~Sprite(); }
        virtual void collision(const GameObject*);
    private:
        void tick();
    };
}

#endif