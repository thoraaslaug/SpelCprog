#include "GameSession.h"
#include "System.h"
#include <SDL2/SDL.h>

using namespace std;

#define FPS 60

namespace grupp20
{
    void GameSession::run()
    {
        bool quit = false;

        Uint32 tickInterval = 1000 / FPS;
        while(!quit)
        {
            Uint32 nextTick = SDL_GetTicks() + tickInterval;
            SDL_Event event;
            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT: quit = true; break;
                    //case SDL_MOUSEBUTTONDOWN
                    //case SDL_MOUSEBUTTONUP
                }
            }//inre while
        

            //kalla på tick() i alla objekt

            //kolla vilka objekt som lagts till och lägg över från buffer till master-vectorn

            //kolla vilka objekt som lagts till i en buffer och ta bort dem

            SDL_SetRenderDrawColor(sys.renderer, 25, 255, 255, 255); //sätt bakgrundfärg
            SDL_RenderClear(sys.renderer); //rensa rendreraren (crazy?! ang ^^^)

            //rendrera ut alla spelkomponenter

            SDL_RenderPresent(sys.renderer);

            int delay = nextTick - SDL_GetTicks();
            if(delay > 0){
                SDL_Delay(delay);
            }
        }
    }
}