#include "SceneManager.h"
#include "GameSession.h"
#include <iostream>
#include "Ball.h"
#include "System.h"
#include "GameObject.h"

namespace grupp20 {


SceneManager::SceneManager(){}

SceneManager::SceneManager(std::string bgPath){
    setBackground("pink.jpg");
}

SceneManager::~SceneManager(){}

void SceneManager::setBackground(std::string filename) {
    background = IMG_LoadTexture(System::getInstance().renderer, filename.c_str());
    if (background == nullptr) {
        std::cout << "Error: cannot load image: " << filename << std::endl;
        std::cout << SDL_GetError() << std::endl;
        exit(-1);
    }
}
void SceneManager::addObject(GameObject * go){
    gameObjects.push_back(go);
}
void SceneManager::removeObject(GameObject* go){
	remove.push_back(go);
	
}
}