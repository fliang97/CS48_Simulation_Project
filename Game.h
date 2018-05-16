//Use command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h Screen_Game.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image
//New Command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h Screen_Game.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h Screen_World.h Entity.h Grass.h Map.h Tile.h Cow.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image
//Newer Command: g++ -std=c++14 Main.cpp Animal.cpp Button.cpp Button_Start.h Component.cpp Cow.cpp Entity.cpp EntityManager.cpp EventHandler.cpp Game.cpp Grass.cpp Map.cpp Plant.cpp Screen.cpp Screen_Game.cpp Screen_MainMenu.cpp Screen_World.cpp ScreenManager.cpp Tile.cpp ZoomInButton.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image

#ifndef GAMES_H_DEFINED
#define GAMES_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <typeinfo>

#include "ScreenManager.h"
#include "EventHandler.h"

using namespace std;

class Game {
public:

	Game();
	~Game();
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	void close();
	void handleEvents();
	bool eventHandlerIsRunning();
	void update();
	void render();

	// Can any of these be moved to private?
	static SDL_Renderer* renderer;
	static EventHandler* eventHandler;
	static ScreenManager* screenManager;
	static SDL_Event event; //make this a pointer?

private:
	SDL_Window* window;

};


#endif /* GAME_H_DEFINED */
