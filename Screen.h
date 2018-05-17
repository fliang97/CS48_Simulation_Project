#ifndef SCREEN_H_DEFINED
#define SCREEN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "EventHandler.h"
//#include "ScreenManager.h"
#include "Component.h"

using namespace std;
class ScreenManager;
//class EventHandler;

class Screen {
public:
	Screen(EventHandler* eventHandler, SDL_Renderer* r, int w, int h);
	//~Screen();
	virtual void mousePressedUp();
	virtual void mousePressedDown();
	virtual void mouseDown();
	virtual void update();
	virtual void render();

	SDL_Renderer* renderer;
	vector< Component* > components;
	EventHandler* eventHandler;
	int width;
	int height;
};
#endif /* SCREEN_H_DEFINED */
