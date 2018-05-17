#ifndef SCREEN_WORLD_H_DEFINED
#define SCREEN_WORLD_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "Screen.h"
#include "EventHandler.h"
//#include "ScreenManager.h"
#include "Map.h"

using namespace std;

class ScreenManager;
const static int COUNTER = 30;

class Screen_GameMap : public Screen {
public:
	Screen_GameMap(EventHandler* eventHandler, SDL_Renderer* r, int x, int y, int w, int h, int& currentScreen, Map& map);

	void mousePressedUp() override;
	void mousePressedDown() override;
	void mouseDown() override;
	void update() override;
	void render() override;

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
