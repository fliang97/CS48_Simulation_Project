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

	//Parameters:
	//Return Values:
	//Precondition: Mouse Pressed Up (Occurs Once)
	//Postcondition: Goes through every component and calls its released function. If the mouse is over the square, it also calls the components clicked function
	virtual void mousePressedUp();

	//Parameters:
	//Return Values:
	//Precondition: Mouse Pressed Down (Occurs Once)
	//Postcondition: Abstract functionality
	virtual void mousePressedDown();

	//Parameters:
	//Return Values:
	//Precondition: Mouse Pressed Up (Occurs Continuously)
	//Postcondition: Abstract functionality
	virtual void mouseDown();

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition: Abstract functionality
	virtual void update();

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition: Abstract functionality
	virtual void render();

	SDL_Renderer* renderer;
	vector< Component* > components;
	EventHandler* eventHandler;
	int width;
	int height;
};
#endif /* SCREEN_H_DEFINED */
