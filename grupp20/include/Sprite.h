//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#ifndef SPRITE_H
#define SPRITE_H

#include "GameObject.h"
#include "SDL2/SDL_image.h"
#include <string>

namespace grupp20{

    class Sprite : public GameObject{
    public:
        ~Sprite() { SDL_DestroyTexture(texture); }
        virtual void draw() const;
        virtual void tick() = 0;
        virtual void collision(const GameObject*) {}
    protected:
        Sprite(int, int, int, int, std::string);
        SDL_Texture* texture;
    };

}

#endif