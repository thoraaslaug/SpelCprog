//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#include "Sprite.h"
#include "System.h"
#include <string>

namespace grupp20{

    Sprite::Sprite(int x, int y, int w, int h, std::string fileName) : GameObject(x, y, w, h) {
            // Path to your own 'images' folder.
            //texture = IMG_LoadTexture(sys.ren, "/Users/kjellna/dev/cpp21/f13b/images/dot40x40.bmp");
            texture = IMG_LoadTexture(sys.renderer, (resPath + "images/" + fileName).c_str() );
        }

    void Sprite::draw() const{
        const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.renderer, texture, NULL, &rect);
    }
}