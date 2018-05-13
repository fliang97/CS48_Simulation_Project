#ifndef GAMESCREEN_H_DEFINED
#define GAMESCREEN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "WorldScreen.h"
using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class GameScreen : public Screen {
  public:
  GameScreen(EventHandler* eh, SDL_Renderer* r, int w, int h, int& cs, GameState& gs): Screen(eh, r, w, h), gamestate(gs) {
    ws = new WorldScreen(eh, r, width/2, height/2, width/2, height/2, cs, gs);
  }

  void mousePressed() override{
    //cout << "somewhere clicked" << end;
    //cout << "Clicked02" << endl;
    for (Component* c : components) {
      if (c->isOver(eh->xMouse, eh->yMouse)) {
        c->clicked();
      }
    }
    ws->mousePressed();
  }

  void update() override {
    ws->update();
  }
  void render() override {
    SDL_Rect rect = {0, 0, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 0, 200, 50, 255 );
    SDL_RenderFillRect( renderer, &rect);
    ws->render();
  }
  WorldScreen* ws;
  GameState& gamestate;
};
#endif /* GAMESCREEN_H_DEFINED */
