#ifndef SCREEN_WORLD_H_DEFINED
#define SCREEN_WORLD_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "Map.h"

const int COUNTER = 30;

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class Screen_World : public Screen {
 public:
	Screen_World(EventHandler* eventHandler, SDL_Renderer* r, int x, int y, int w, int h, int& currentScreen, Map& map) : Screen(eventHandler, r, w, h), map(map), xpos(x), ypos(y), width(w),
		height(h), count(COUNTER), worldposX(0), worldposY(0) {
		scaleX = width / map.width;
		scaleY = height / map.height;
    counter = count;
	}

	void mousePressedUp() override {
	}

	void mousePressedDown() override {
		cout << "mousePressedDown" << endl;

		mouseInitX = eventHandler->xMouse;
		mouseInitY = eventHandler->yMouse;
		worldInitX = worldposX;
		worldInitY = worldposY;
	}

	void mouseDown() override {
		worldposX = min(max(worldInitX - (eventHandler->xMouse - mouseInitX), 0), map.width * scaleX - width);

		worldposY = min(max(worldInitY - (eventHandler->yMouse - mouseInitY), 0), map.height * scaleY - height);
		cout << worldposX << " " << worldposY << endl;
	}

	void update() override {
		//cout << "WorldScreenUpdate" << endl;
		if (counter == 0) {
			//cout << "SuccessfulUpdate" << endl;
			for (int i = 0; i < map.width; ++i) {
				for (int j = 0; j < map.height; ++j) {
					(*map.mapGrid)[i][j]->update(map.bufferboard);
				}
			}
			vector< vector<Tile*> >* temp = map.mapGrid;
			map.mapGrid = map.bufferboard;
			map.bufferboard = temp;
			counter = count;
		}
		--counter;
		//cout << counter << endl;
	}

	void render() override {
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

	int mouseInitX;
	int mouseInitY;
	int worldInitX;
	int worldInitY;

	int counter;
  int count;

	int xpos;
	int ypos;
	int worldposX;
	int worldposY;
	int scaleX;
	int scaleY;
	int width;
	int height;
	Map& map;
};

#endif /* SCREEN_WORLD_H_DEFINED */
