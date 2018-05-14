#ifndef WORLDSCREEN_H_DEFINED
#define WORLDSCREEN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL.h>

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Screen.h"
#include "EventHandler.h"
#include "GameState.h"

const int COUNTER = 30;

using namespace std;
//#include "ScreenManager.h"
class ScreenManager;

class WorldScreen : public Screen {
  public:
  WorldScreen(EventHandler* eh, SDL_Renderer* r, int x, int y, int w, int h, int& cs, GameState& gs): Screen(eh, r, w, h), gamestate(gs), xpos(x), ypos(y), width(w), height(h), counter(COUNTER) {
  }

  void update() override {
    cout << "WorldScreenUpdate" << endl;
    if (counter == 0) {
      cout << "SuccessfulUpdate" << endl;
      for (int i = 0; i < gamestate.width; ++i) {
        for (int j = 0; j < gamestate.height; ++j) {
          (*gamestate.board)[i][j]->update(gamestate.bufferboard);
        }
      }
      vector< vector<GameSquare*> >* temp = gamestate.board;
      gamestate.board = gamestate.bufferboard;
      gamestate.bufferboard = temp;
      counter = COUNTER;
    }
    --counter;
    //cout << counter << endl;
  }
  void render() override {
    //cout << "WorldScreenRender" << endl;
    SDL_Rect rect = {xpos, ypos, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 0, 240, 220, 205 );
    SDL_RenderFillRect( renderer, &rect);
    for (int i = 0; i < gamestate.width; ++i) {
      for (int j = 0; j < gamestate.height; ++j) {
        //cout << i << " " << j << endl;
        (*gamestate.board)[i][j]->render(xpos, ypos, width/gamestate.width, height/gamestate.height, renderer); //change to include zoom value and whatnot
      }
    }
  }
  int counter;
  int xpos;
  int ypos;
  int width;
  int height;
  GameState& gamestate;
};
#endif /* WORLDSCREEN_H_DEFINED */
