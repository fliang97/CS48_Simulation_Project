//Use command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h Screen_Game.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image
//New Command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h Screen_Game.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h Screen_World.h Entity.h Grass.h Map.h Tile.h Cow.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image


//Use command: g++ -std=c++14 Main.cpp Animal.h Button.h Component.h Cow.h Entity.h EntityManager.h EventHandler.h Game.h Screen_Game.h Tile.h Map.h Grass.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h Screen_World.h Button_ZoomIn.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image
//New Command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h Screen_Game.h Screen_MainMenu.h Screen.h ScreenManager.h Button_Start.h Screen_World.h Entity.h Grass.h Map.h Tile.h Cow.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image


// Disclaimer:  This main file is based on a file found at https://github.com/carlbirch/BirchEngine/blob/master/BirchEngine/Src/main.cpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <typeinfo>
//#include <chrono>
#include "Game.h"

using namespace std;
//using namespace std::chrono_literals;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
//constexpr std::chrono::nanoseconds timestep(16ms);


int main(int argc, char *argv[]) {

	Game* game = new Game();
	game->init(SCREEN_WIDTH, SCREEN_HEIGHT);

	//  using clock = std::chrono::high_resolution_clock;
	//  std::chrono::nanoseconds lag(0ns);
	//  auto time_start = clock::now();

	const int FPS = 60;
	const int minFrameTime = 1000 / FPS;
	Uint32 frameStartTime;
	int currentFrameTime;

	while (game->eventHandlerIsRunning()) {
		//    auto delta_time = clock::now() - time_start;
		//    time_start = clock::now();
		//    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

		frameStartTime = SDL_GetTicks();
		game->handleEvents();

		// update game logic as lag permits
		//    while(lag >= timestep) {
		//      lag -= timestep;
		//      screenManager.update(); // update at a fixed rate each time
		//    }

		game->update();
		game->render();

		currentFrameTime = SDL_GetTicks() - frameStartTime;

		if (currentFrameTime < minFrameTime) {
			SDL_Delay(minFrameTime - currentFrameTime);
		}
	}

	game->close();
	return 0;
}
