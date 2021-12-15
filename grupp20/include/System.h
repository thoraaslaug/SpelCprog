#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <string>
#include "Ball.h"

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
    
    extern std::string resPath;
    extern System sys;
}

#endif