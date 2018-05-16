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
#include "Cow.h"
#include "Map.h"

using namespace std;
class ScreenManager;

class Button_Start : public Button {
public:
  Button_Start(int x, int y, int w, int h, SDL_Renderer* r, int& currentScreen, Map& map): Button(x, y, w, h, r), currentScreen(currentScreen), map(map){
  }
  //~Button_Start() {
  //  delete currentScreen;
  //}
  void clicked() override {
    map = Map(20, 20);

    Tile* tile = (*map.mapGrid)[5][5];
    //Square must know Entity
    tile->entity = new Grass(tile);
    tile = (*map.mapGrid)[3][5];
    tile->entity = new Cow(tile);

    //delete map;
    //delete c;

    currentScreen = 1;
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
  int& currentScreen;
  Map& map;
};
#endif /* STARTBUTTON_H_DEFINED */
