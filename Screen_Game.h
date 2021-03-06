#ifndef SCREEN_GAME_H_DEFINED
#define SCREEN_GAME_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>

#include "Button_Speedup.h"
#include "Button_Speeddown.h"
#include "Button_Entity.h"
#include "Screen.h"
#include "EventHandler.h"
#include "Screen_GameMap.h"

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class Screen_Game : public Screen {
public:
	Screen_Game(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map);

	//Parameters: Component c, tile t
    //Precondition: Mouse was released over the screen.
    //Postcondition: Goes through all the component functions and calls there clicked function if mouse is over their borders.
	// Checks to see if mouse is over world screen. If it is, then it calls its mousePressedUp function.
	void mousePressedUp() override;

    //Parameters:component c, tile t
    //Precondition: Mouse was pressed over the screen. (Called Once)
    //Postcondition: Checks to see if mouse is over world screen. If it is, then it calls its mousePressedDown function.
	void mousePressedDown() override;

	//Parameters: Component c
    //Precondition: Mouse is currently being pressed over the screen. (Continuous)
    //Postcondition: Checks to see if mouse is over world screen. If it is, then it calls its mouseDown function.
	void mouseDown() override;

    //Postcondition: Calls the worldscreen's update.
	void update() override;

    //Parameters:The phorizontal ordinates and vertical coordinates of map and world.
    //Precondition: Screen world
    //Postcondition: Renders the worldscreen first then overlays an L shaped border around it. Then calls the zoom button's render.
	void render() override;

	Button_Speedup* speedup;
	Button_Speeddown* speeddown;
	Button_Entity* entity3;
	Button_Entity* entity4;
	Button_Entity* entity5;
	Screen_GameMap* screen_world;
	Map& map;

	int COUNTER; //60 fps / COUNTER = gamefps.
	int counter; //from screen_world / screen_gamemap

	 SDL_Texture *mouse_img;

	static void setTextureImg();
	static SDL_Texture *static_img;

};
#endif /* SCREEN_GAME_H_DEFINED */
