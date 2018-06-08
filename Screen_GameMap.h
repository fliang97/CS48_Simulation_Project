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
#include "Button_ZoomIn.h"
#include "Button_ZoomOut.h"
#include "Button_Plot.h"
#include "plotsdl/plot.h"
#include "plotsdl/llist.h"
#include "Button_Plot.h"
//#include "ScreenManager.h"
#include "Map.h"

using namespace std;

class ScreenManager;


class Screen_GameMap : public Screen {
public:
	Screen_GameMap(EventHandler* eventHandler, SDL_Renderer* r, int x, int y, int w, int h, int& currentScreen, Map& map);

    //Parameters: component c, tile t
    //Precondition: Mouse was released over the screen.
    //Postcondition: Goes through all the component functions and calls there clicked function if mouse is over their borders.
    // Checks to see if mouse is over world screen. If it is, then it calls its mousePressedUp function.
    void mousePressedUp() override;

    //Parameters:component c, tile t
    //Precondition: Mouse was pressed over the screen. (Called Once)
	//Postcondition: Sets mouseInit and worldInit to current mouse and world coordinates. Used to remember translational motion during click and drag.
	void mousePressedDown() override;
    
    //Parameters: component c
    //Precondition: Mouse is currently being pressed over the screen. (Continuous)
	//Postcondition: Updates worldposition coordinates to be within the bounds. Attempts to translate worldposition by xMouse - mouseInitX for x and y.
	void mouseDown() override;

	//Precondition: update entity
	//Postcondition: Calls updateEachTile(). update cow, grass and wolf
	void update() override;

    //Parameters:The phorizontal ordinates and vertical coordinates of map and world.
    //Precondition: Screen world
    //Postcondition: Goes through every tile and renders it based of the gamemap coordinates, its coordinates, and zoom level (or scale).
	void render() override;

//Used for mouse drag computation.
	int mouseInitX;
	int mouseInitY;
	int worldInitX;
	int worldInitY;


	int xpos;
	int ypos;
	int worldposX;
	int worldposY;
	int scaleX;
	int scaleY;
	int width;
	int height;


	int gameTicks;
	Map& map;
	Button_ZoomIn* button_zoomIn;
	Button_ZoomOut* button_zoomOut;
	Button_Plot* button_plot;

	splot plot;
	surfacelist surface_list;
	plot_params params;
	captionlist caption_list;
	coordlist coordinate_list;
	bool showplot;

	char textCows[10];
	char textGrass[10];
	char textWolves[10];
	char textTime[10];
	char textNumber[10];



	static SDL_Texture *static_img;
	static void setTextureImg();

};

#endif /* SCREEN_WORLD_H_DEFINED */
