#ifndef STARTBUTTON_H_DEFINED
#define STARTBUTTON_H_DEFINED


#include "Button.h"
class ScreenManager;

class StartButton : Button{
public:
  StartButton(int x, int y, int w, int h, SDL_Renderer* r, int* cr): Button(x, y, w, h, r) {
    current_screen = cr;
  }
  void clicked() override {
    *current_screen = 1;
  }
  void render() override {
    SDL_Rect rect = {xpos, ypos, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 50, 0, 255 );
    SDL_RenderFillRect(renderer, &rect);
  }
  int* current_screen;
};
#endif /* START_H_DEFINED */
