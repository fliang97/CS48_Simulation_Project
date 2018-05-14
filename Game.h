//Use command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h Screen_Game.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image
//New Command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h Screen_Game.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h Screen_World.h Entity.h Grass.h Map.h Tile.h Cow.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image

#ifndef GAMES_H_DEFINED
#define GAMES_H_DEFINED


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <typeinfo>

#include "Game.h"
#include "ScreenManager.h"
#include "EventHandler.h"

using namespace std;

class Game {
public:

	// Can any of these be moved to private?
	static SDL_Renderer* renderer;
	static EventHandler* eventHandler;
	static ScreenManager* screenManager;
	static SDL_Event event; //make this a pointer?

	Game();
	~Game();
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	void close();
	void handleEvents();
	bool eventHandlerIsRunning();
	void update();
	void render();

private:
	SDL_Window* window;

};


#endif /* GAME_H_DEFINED */