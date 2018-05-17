
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

//~ScreenManager() {
//  delete renderer;
//  delete eventHandler;
//}

void ScreenManager::mousePressedUp() {
	//cout << "Clicked01" << endl;
	screens[currentScreen]->mousePressedUp();
}

void ScreenManager::mousePressedDown() {
	//cout << "Clicked01" << endl;
	screens[currentScreen]->mousePressedDown();
}

void ScreenManager::mouseDown() {
	//cout << "Clicked01" << endl;
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
	//SDL_Rect rect = {0, 0, width, height};
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
	//SDL_SetRenderDrawColor( renderer, 100, 0, 100, 255 );
	//SDL_RenderFillRect( renderer, &rect);
	//cout <<  currentScreen << endl;

	SDL_RenderPresent(renderer);
}
