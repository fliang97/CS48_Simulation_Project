#ifndef STARTBUTTON_H_DEFINED
#define STARTBUTTON_H_DEFINED


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Button.h"
#include "Entity.h"
#include "Grass.h"
#include "GameState.h"

using namespace std;
class ScreenManager;

class StartButton : public Button {
public:
  StartButton(int x, int y, int w, int h, SDL_Renderer* r, int& cr, GameState& gs): Button(x, y, w, h, r), current_screen(cr), gamestate(gs){
  }
  //~StartButton() {
  //  delete current_screen;
  //}
  void clicked() override {
    gs(10, 10);

    GameSquare* s = gs.(*board)[5][5];
    //Square must know Entity
    Entity g = new Grass(s);
    gs.entities.push_back(g);
    s->e = g;
    s = gs.(*board)[3][5];

    //Entity c = new Cow(s)
    //gs.entities.push_back(g);
    //s->e = c;
    //delete g;
    //delete c;

    current_screen = 1;
  }
  void render() override {
    SDL_Rect rect;
    rect.x = xpos;
    rect.y = ypos;
    rect.w = width;
    rect.h = height;
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 50, 0, 255 );
    SDL_RenderFillRect(renderer, &rect);
  }
  int& current_screen;
  GameState& gs;
};
#endif /* START_H_DEFINED */
