//Use command: g++ -std=c++14 GameMain.cpp Button.h Component.h EventHandler.h GameScreen.h MainMenuScreen.h Screen.h ScreenManager.h StartButton.h -o sim `pkg-config --cflags --libs sdl2` -lSDL2 -lSDL2_image


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <typeinfo>
#include <chrono>

#include "ScreenManager.h"
#include "EventHandler.h"

using namespace std;
using namespace std::chrono_literals;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
constexpr std::chrono::nanoseconds timestep(16ms);

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event event;


void Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderClear(renderer);
}

void Close()
{
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}

int main(int argc, char *argv[]) {
  Init();
  using clock = std::chrono::high_resolution_clock;

  std::chrono::nanoseconds lag(0ns);
  auto time_start = clock::now();

  EventHandler eh; //#PossibleChange to EventConstants
  ScreenManager sc(&eh, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
  while (eh.running) {
    auto delta_time = clock::now() - time_start;
    time_start = clock::now();

    lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);
    //#Possibly move into seperate class
    while(SDL_PollEvent(&event) != 0) //To exit loop, call exit(-1)
    {
        if (event.type == SDL_QUIT) {
            eh.running = false;
        }
        if(event.type == SDL_MOUSEMOTION) {
            SDL_GetMouseState(&eh.xMouse, &eh.yMouse);
        }
        if(event.type == SDL_MOUSEBUTTONDOWN) {
            sc.mousePressed();
            cout << "Clicked0" << endl;
        }
    }
    // update game logic as lag permits
    while(lag >= timestep) {
      lag -= timestep;
      sc.update(); // update at a fixed rate each time
    }
    sc.render();
  }
}
