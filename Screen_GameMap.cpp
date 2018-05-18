
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Screen.h"
#include "EventHandler.h"
#include "Map.h"
#include "Screen_GameMap.h"


using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

Screen_GameMap::Screen_GameMap(EventHandler* eventHandler, SDL_Renderer* r, int x, int y, int w, int h, int& currentScreen, Map& map) : Screen(eventHandler, r, w, h), map(map), xpos(x), ypos(y), width(w),
height(h), worldposX(0), worldposY(0) {
	scaleX = width / map.width;
	scaleY = height / map.height;
}

void Screen_GameMap::mousePressedUp() {
}

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
}


void Screen_GameMap::render() {
	//cout << "WorldScreenRender" << endl;
	SDL_Rect rect = { xpos, ypos, width, height };
	//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
	SDL_SetRenderDrawColor(renderer, 0, 240, 220, 205);
	SDL_RenderFillRect(renderer, &rect);

	for (int i = 0; i < map.width; ++i) {
		for (int j = 0; j < map.height; ++j) {
			//cout << i << " " << j << endl;
			(*map.mapGrid)[i][j]->render(xpos, ypos, worldposX, worldposY, scaleX, scaleY, renderer); //change to include zoom value and whatnot
		}
	}
}
