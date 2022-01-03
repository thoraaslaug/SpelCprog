#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include <string>
#include <list>
#include "GameObject.h"
#include "GameSession.h"
#include "Sprite.h"

namespace grupp20 {
class SceneManager{
public:
	SceneManager();
	SceneManager(std::string);
	~SceneManager();
	void setBackground(std::string path);
	void addObject(GameObject* go);
	void removeObject(GameObject* go);
	bool run();
    void draw();
	std::list<GameObject*> *seeGameObjects() { return &gameObjects; }
private:
	SDL_Texture *background;
	std::list<GameObject*> gameObjects;
	std::list<GameObject*> remove;

};
}

#endif