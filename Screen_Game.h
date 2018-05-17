#ifndef SCREEN_GAME_H_DEFINED
#define SCREEN_GAME_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "Screen_GameMap.h"
#include "Button_ZoomIn.h"

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class Screen_Game : public Screen {
public:
	Screen_Game(EventHandler* eventHandler, SDL_Renderer* r, int w, int h, int& cs, Map& map);
	void mousePressedUp() override;
	void mousePressedDown() override;
	void mouseDown() override;
	void update() override;
	void render() override;

	Screen_GameMap* screen_world;
	Map& map;
	Button_ZoomIn* button_zoomIn;
};
#endif /* SCREEN_GAME_H_DEFINED */
