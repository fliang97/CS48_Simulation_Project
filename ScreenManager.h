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
	
    //Parameters: eventHandler is used to get the (x,y) of the current event and to judge whether it is running
    //Parameters: r represents the SDL_Renderer used to render the image in the proper location.
    //Parameters: w-width of the screen h-height of the screen
    //Precondition: background image
    //Postcondition: load background image
    ScreenManager(EventHandler* eventHandler, SDL_Renderer* r, const int w, const int h);
	//~ScreenManager();
    
    //Precondition: Mouse Pressed Up (Occurs Once)
    //Postcondition: Goes through every component and calls its released function. If the mouse is over the square, it also calls the components clicked function
	void mousePressedUp();
   
    //Precondition: Mouse Pressed Down (Occurs Once)
    //Postcondition: Abstract functionality
	void mousePressedDown();
	
    //Precondition: Mouse Pressed Up (Occurs Continuously)
    //Postcondition: Abstract functionality
    void mouseDown();
    
    //Precondition:current screen
    //Postcondition: Abstract functionality
	void update();
    
    //Postcondition: Abstract functionality
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
