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
	Screen(EventHandler* eventHandler, SDL_Renderer* r, int w, int h): width(w), height(h), renderer(r), eventHandler(eventHandler){
	}
	
	//~Screen() {
	//  delete eventHandler;
	//  delete sm;
	//delete renderer;
	//}
	
	virtual void mousePressedUp() {
		//cout << "somewhere clicked" << end;
		//cout << "Clicked02" << endl;
		for (Component* c : components) {
			if (c->isOver(eventHandler->xMouse, eventHandler->yMouse)) {
				c->clicked();
			}
		}
	}
  
	virtual void mousePressedDown() {
	}

	virtual void mouseDown() {
	}

	virtual void update() {
	}
  
	virtual void render() {
		//cout <<  "Problem" << endl;
	}

	SDL_Renderer* renderer;
	vector< Component* > components;
	EventHandler* eventHandler;
	int width;
	int height;
};
#endif /* SCREEN_H_DEFINED */
