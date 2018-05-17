#ifndef SCREENMANAGER_H_DEFINED
#define SCREENMANAGER_H_DEFINED

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

using namespace std;

class ScreenManager {
 public:
	 ScreenManager(EventHandler* eventHandler, SDL_Renderer* r, const int w, const int h);
	//~ScreenManager();
	void mousePressedUp();
	void mousePressedDown();
	void mouseDown();
	void update();
	void render();

private:
	SDL_Renderer* renderer;
	int currentScreen;
	Map currentMap;
	vector<Screen*> screens;
	EventHandler* eventHandler;
	int width;
	int height;
};

#endif /* SCREENMANAGER_H_DEFINED */
