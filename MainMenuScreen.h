#ifndef MAINMENUSCREEN_H_DEFINED
#define MAINMENUSCREEN_H_DEFINED

#include "StartButton.h"
#include "Screen.h"
#include "EventHandler.h"
#include "ScreenManager.h"


class MainMenuScreen : public Screen {
  public:
  MainMenuScreen(EventHandler* eh, ScreenManager* sm, SDL_Renderer* r, int w, int h): Screen(eh, sm, r, w, h) {
    sb = new StartButton(sm->width/3, sm->height/3, sm->width/3, sm->height/3, &(sm->current_screen));
    components.push_back(sb);
  }

  void update() {
  }
  void render() {
    SDL_Rect rect = {0, 0, sm->width, sm->height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 0, 100, 255 );
    SDL_RenderFillRect( renderer, &rect);
    sb->render();
  }
private:
  StartButton* sb;
};


#endif /* MAINMENUSCREEN_H_DEFINED */
