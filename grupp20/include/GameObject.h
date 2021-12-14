#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL2/SDL.h>

namespace grupp20{

    class GameObject
    {
    public:
        virtual void mouseDown(int x, int y) {}
        virtual void mouseUp(int x, int y) {}
        virtual void draw() const = 0;
        SDL_Rect getRect() const { return rect; }
        virtual void tick() = 0;
        virtual void collision(const GameObject*) = 0;
        virtual const GameObject* check_collision();
    protected:
        GameObject(int x, int y, int w, int h) : rect{ x,y,w,h } {}
        SDL_Rect rect;
    };
}

#endif