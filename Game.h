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

	//Parameters: int SCREEN_WIDTH, SCREEN_HEIGHT used to define the width and height of the screen window.
	//Return Values:
	//Precondition:
	//Postcondition:  Initializes SDL settings. Creates window at size of SCREEN_WIDTH x SCREEN_HEIGHT. Creates EventHandler and ScreenManager.
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT);

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition:  Destroys Window and Renderer.
	void close();

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition:  Pops event from queue and calls appropriate screen manager functions. Also updates globals (mouse positions and running).
	void handleEvents();

	//Parameters:
	//Return Values: getter for running value. eventHandler->isRunning();
	//Precondition:
	//Postcondition: Getter for eventhandler->isRunning(), which controls the whether the game is running.
	bool eventHandlerIsRunning();

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition: Calls ScreenManager's update function
	void update();

	//Parameters:
	//Return Values:
	//Precondition:
	//Postcondition: Calls ScreenManager's render function
	void render();

	// TO DO: Move some of these to private
	static SDL_Renderer* renderer;
	static EventHandler* eventHandler;
	static ScreenManager* screenManager;
	static SDL_Event event; //make this a pointer?

	const static int COUNTER = 30; //60 fps / COUNTER = gamefps.

private:
	SDL_Window* window;

};


#endif /* GAME_H_DEFINED */
