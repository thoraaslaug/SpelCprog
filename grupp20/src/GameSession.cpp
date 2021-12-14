#include "GameSession.h"
#include "System.h"
#include "GameObject.h"
#include <SDL2/SDL.h>
#include <vector>
#include "Ball.h"
#include "typeinfo.h"

using namespace std;

#define FPS 60

namespace grupp20
{
    void GameSession::add(GameObject* go){
        added.push_back(go);
    }

    void GameSession::remove(GameObject* go){
        removed.push_back(go);
    }

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
                    case SDL_MOUSEBUTTONDOWN:
				        for (GameObject* go : gameObjects)
					        go->mouseDown(event.button.x, event.button.y);
				        break;
                    case SDL_MOUSEBUTTONUP:
				        for (GameObject* go : gameObjects)
					        go->mouseUp(event.button.x, event.button.y);
				        break;
                }
            }//inre while
        

            for (GameObject* go : gameObjects)
			    go->tick();

		    for (GameObject* go : added)
			    gameObjects.push_back(go);
		    added.clear();

		    for (GameObject* go : removed)
			    for (vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end();)
				    if (*i == go) {
					    i = gameObjects.erase(i);
				    }
				    else
					    i++;
		    removed.clear();

            SDL_SetRenderDrawColor(sys.renderer, 255, 255, 255, 255); //sätt bakgrundfärg
            SDL_RenderClear(sys.renderer); //rensa rendreraren (crazy?! ang ^^^)

            for(GameObject* go : gameObjects)
                go->draw();

            SDL_RenderPresent(sys.renderer);

            int delay = nextTick - SDL_GetTicks();
            if(delay > 0){
                SDL_Delay(delay);
            }
        }
    }

    GameSession ses;
}