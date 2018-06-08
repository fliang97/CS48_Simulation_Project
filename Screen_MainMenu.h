#ifndef SCREEN_MAINMENU_H_DEFINED
#define SCREEN_MAINMENU_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Button_Start.h"
#include "Screen.h"
#include "EventHandler.h"

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class Screen_MainMenu : public Screen {
public:
	
    //Parameters: eventHandler is used to get the (x,y) of the current event and to judge whether it is running
    //Parameters: r represents the SDL_Renderer used to render the image in the proper location.
    //Parameters: w-width of the screen h-height of the screen
    //Precondition: background image
    //Postcondition: load background image
    Screen_MainMenu(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map);
	//~Screen_MainMenu();
    
    //Precondition: click down
	void mousePressedDown() override;
    //Postcondition: abstract
	void update() override;
    //Postcondition: update new position
	void render() override;



private:
	Button_Start * button_start;
	SDL_Texture* static_img_main_menu_background;
};


#endif /* SCREEN_MAINMENU_H_DEFINED */
