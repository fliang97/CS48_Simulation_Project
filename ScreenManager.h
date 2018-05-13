#ifndef SCREENMANAGER_H_DEFINED
#define SCREENMANAGER_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "Component.h"

using namespace std;


class ScreenManager {
  public:
  ScreenManager(EventHandler* eh, SDL_Renderer* r, const int w, const int h):width(w), height(h), renderer(r) {
    MainMenuScreen* mms = new MainMenuScreen(eh, r, width, height, current_screen, currentGameState);
    GameScreen* gs = new GameScreen(eh, r, width, height, current_screen, currentGameState);
    screens = {mms, gs};
    currentGameState = WorldGenerator::newGameState(); //possibly remove
    current_screen = 0;
    this->eh = eh;
  }

  //~ScreenManager() {
  //  delete renderer;
  //  delete eh;
  //}
  void mousePressed() {
    //cout << "Clicked01" << endl;
    screens[current_screen]->mousePressed();
  }
  void update() {
    screens[current_screen]->update();
  }
  void render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    screens[current_screen]->render();
    //SDL_Rect rect = {0, 0, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    //SDL_SetRenderDrawColor( renderer, 100, 0, 100, 255 );
    //SDL_RenderFillRect( renderer, &rect);
    //cout <<  current_screen << endl;

    SDL_RenderPresent(renderer);
  }
private:
  SDL_Renderer* renderer;
  int current_screen;
  GameState currentGameState;
  vector<Screen*> screens;
  EventHandler* eh;
  int width;
  int height;
};

#endif /* SCREENMANAGER_H_DEFINED */
