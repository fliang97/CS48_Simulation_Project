#ifndef SCREENMANAGER_H_DEFINED
#define SCREENMANAGER_H_DEFINED

#include "Screen.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include "Component.h"

using namespace std;

class ScreenManager {
  public:
  ScreenManager(EventHandler* eh, SDL_Renderer* r, int w, int h):width(w), height(h), renderer(r) {
    MainMenuScreen mms(eh, this, r, width, height);
    GameScreen gs(eh, this, r, width, height);
    screens = {mms, gs};
    current_screen = 0;
    this->eh = eh;
  }
  void mousePressed() {
    screens[current_screen].mousePressed();
  }
  void update() {
    screens[current_screen].update();
  }
  void render() {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    screens[current_screen].render();
    SDL_RenderPresent(renderer);
  }
private:
  SDL_Renderer* renderer;
  int current_screen;
  vector<Screen> screens;
  EventHandler* eh;
  int width;
  int height;
};


#endif /* SCREENMANAGER_H_DEFINED */
