
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Screen.h"
#include "EventHandler.h"
#include "Button_ZoomIn.h"
#include "Button_ZoomOut.h"
#include "Map.h"
#include "Screen_GameMap.h"


using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

Screen_GameMap::Screen_GameMap(EventHandler* eventHandler, SDL_Renderer* r, int x, int y, int w, int h, int& currentScreen, Map& map) : Screen(eventHandler, r, w, h), map(map), xpos(x), ypos(y), width(w),
height(h), worldposX(0), worldposY(0) {
	scaleX = width / map.width;
	scaleY = height / map.height;
	button_zoomIn = new Button_ZoomIn(xpos + width / 20, ypos + height / 20, width / 10, height / 10, r, scaleX, scaleY);
	components.push_back(button_zoomIn);
	button_zoomOut = new Button_ZoomOut(xpos + width / 20, ypos + height / 6, width / 10, height / 10, r, scaleX, scaleY);
	components.push_back(button_zoomOut);
}

//void Screen_GameMap::mousePressedUp() {
//}

void Screen_GameMap::mousePressedDown() {
	mouseInitX = eventHandler->xMouse;
	mouseInitY = eventHandler->yMouse;
	worldInitX = worldposX;
	worldInitY = worldposY;
}

void Screen_GameMap::mouseDown() {
	worldposX = min(max(worldInitX - (eventHandler->xMouse - mouseInitX), 0), map.width * scaleX - width);
	worldposY = min(max(worldInitY - (eventHandler->yMouse - mouseInitY), 0), map.height * scaleY - height);
	//cout << worldposX << " " << worldposY << endl;
}

void Screen_GameMap::update() {
	map.updateEachTile();


	//move
	//Eat / Action
	//Death
	//Reproduce
	//update gamestate
}


void Screen_GameMap::render() {
	SDL_Rect rect = { xpos, ypos, width, height };

	SDL_SetRenderDrawColor(renderer, 0, 240, 220, 205);
	SDL_RenderFillRect(renderer, &rect);

	for (int i = 0; i < map.width; ++i) {
		for (int j = 0; j < map.height; ++j) {

			//TO ADD: render only elements on display
			(*map.mapGrid)[i][j]->render(xpos, ypos, worldposX, worldposY, scaleX, scaleY, renderer);
		}
	}
	button_zoomIn->render();
	button_zoomOut->render();
}
