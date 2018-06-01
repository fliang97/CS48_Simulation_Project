//New compiling command: g++ -std=c++14 Main.cpp Animal.cpp Button.cpp Button_Start.cpp Button_ZoomIn.cpp Button_ZoomOut.cpp Component.cpp Cow.cpp Entity.cpp EntityManager.cpp EventHandler.cpp Game.cpp Grass.cpp Map.cpp Plant.cpp Screen.cpp Screen_Game.cpp Screen_MainMenu.cpp Screen_GameMap.cpp ScreenManager.cpp Tile.cpp -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image


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

	Game* game = new Game(); //No reason for this to be pointer but idk
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
