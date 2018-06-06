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
	Screen_MainMenu(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map);
	//~Screen_MainMenu();
	void mousePressedDown() override;
	void update() override;
	void render() override;

private:
	Button_Start * button_start;
	SDL_Texture* static_img_main_menu_background;
};


#endif /* SCREEN_MAINMENU_H_DEFINED */
