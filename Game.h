//Newer Command: g++ -std=c++14 Main.cpp Animal.cpp Button.cpp Button_Start.cpp Button_ZoomIn.cpp Component.cpp Cow.cpp Entity.cpp EntityManager.cpp EventHandler.cpp Game.cpp Grass.cpp Map.cpp Plant.cpp Screen.cpp Screen_Game.cpp Screen_MainMenu.cpp Screen_GameMap.cpp ScreenManager.cpp Tile.cpp -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image

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

	const static int COUNTER = 30;

private:
	SDL_Window* window;

};


#endif /* GAME_H_DEFINED */
