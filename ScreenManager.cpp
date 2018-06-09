
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "Screen_Game.h"
#include "Screen_MainMenu.h"
#include "Component.h"
#include "Map.h"
#include "ScreenManager.h"

using namespace std;

ScreenManager::ScreenManager(EventHandler* eventHandler, SDL_Renderer* r, const int w, const int h) : width(w), height(h), renderer(r) {
	currentMap = Map(10, 10); //possibly remove
	Screen_MainMenu* mainMenuScreen = new Screen_MainMenu(eventHandler, r, width, height, currentScreen, currentMap);
	Screen_Game* gameScreen = new Screen_Game(eventHandler, r, width, height, currentScreen, currentMap);
	screens = { mainMenuScreen, gameScreen };
	currentScreen = 0;
	this->eventHandler = eventHandler;
}

//Possible TO DO: Add destructor

void ScreenManager::mousePressedUp() {
	screens[currentScreen]->mousePressedUp();
}

void ScreenManager::mousePressedDown() {
	screens[currentScreen]->mousePressedDown();
}

void ScreenManager::mouseDown() {
	if (currentScreen == 1) { //possibly remove
		screens[currentScreen]->mouseDown();
	}
}

void ScreenManager::update() {
	screens[currentScreen]->update();
}

void ScreenManager::render() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	screens[currentScreen]->render();

	SDL_RenderPresent(renderer);
}
