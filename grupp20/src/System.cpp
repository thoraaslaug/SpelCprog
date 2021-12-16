#include "System.h"
#include <SDL2/SDL.h>

#include <iostream>

namespace grupp20
{
	//std::string resPath = "./resources/";

    System::System() {
	    SDL_Init(SDL_INIT_EVERYTHING); //starta allt
	    window = SDL_CreateWindow("PROJEKT 20", 10, 10, WINDOW_X, WINDOW_Y, 0); //fönster + storlek + fönsternamn
	    renderer = SDL_CreateRenderer(window, -1, 0); //rendrera innehållet i fönstret
	    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	    music = Mix_LoadWAV( (resPath + "sounds/bgMusic.wav").c_str() ); //sätter igång musiken vid start
		//std::cout << music << std::endl;
	    Mix_PlayChannel(-1, music, -1); //sätter loopar och L/R audio
    }

    System::~System() {
	    Mix_FreeChunk(music);
	    Mix_CloseAudio();
	    SDL_DestroyWindow(window);
	    SDL_DestroyRenderer(renderer);
	    SDL_Quit();
    }

    System sys;
}