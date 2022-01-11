//August Jansson auja6710
//Thora Magnusdottir thma8722
//Max Halling Maha1841
#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <string>

namespace grupp20
{
    struct System
    {
        System();
        ~System();

        SDL_Window* window;
	    SDL_Renderer* renderer;
	    Mix_Chunk* music;
    };
    
    extern const int WINDOW_X;
    extern const int WINDOW_Y;
    extern std::string resPath;
    extern System sys;
}

#endif