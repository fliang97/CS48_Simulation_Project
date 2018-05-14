#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL.h>

#include <iostream>
#include <vector>
#include <cstdlib>
#include <typeinfo>

#include "Game.h"
#include "ScreenManager.h"
#include "EventHandler.h"

using namespace std;

SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
SDL_Event event;


Game::Game(){
}

void Game::init(){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
}

void close()
{
    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer)
    SDL_Quit();
}

int main(int argc, char *argv[]) {
  Init();
//  using clock = std::chrono::high_resolution_clock;

//  std::chrono::nanoseconds lag(0ns);
//  auto time_start = clock::now();

  const int FPS = 60;
  const int minFrameTime = 1000 / FPS;
  Uint32 frameStartTime;
  int currentFrameTime;

  EventHandler eventHandler; //#PossibleChange to EventConstants
  ScreenManager screenManager(&eventHandler, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
  while (eventHandler.running) {
//    auto delta_time = clock::now() - time_start;
//    time_start = clock::now();

//    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

	  frameStartTime = SDL_GetTicks();

    //#Possibly move into seperate class

	  void Game::handleEvents() {
		  while (SDL_PollEvent(&event) != 0) //To exit loop, call exit(-1)
		  {
			  if (event.type == SDL_QUIT) {
				  eventHandler.running = false;
			  }
			  if (event.type == SDL_MOUSEMOTION) {
				  SDL_GetMouseState(&eventHandler.xMouse, &eventHandler.yMouse);
			  }
			  if (event.type == SDL_MOUSEBUTTONDOWN) {
				  screenManager.mousePressed();
				  //cout << "Clicked0" << endl;
			  }
		  }
	  }
    // update game logic as lag permits
//    while(lag >= timestep) {
//      lag -= timestep;
//      screenManager.update(); // update at a fixed rate each time
//    }

	////Tyler's troubleshooting code:
	//screenManager.update();
	//SDL_Delay(1000);

	screenManager.update();

    screenManager.render();

	currentFrameTime = SDL_GetTicks() - frameStartTime;

	if (currentFrameTime < minFrameTime){
		SDL_Delay(minFrameTime - currentFrameTime);
	}


  }

  return 0;
}
