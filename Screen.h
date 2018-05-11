#ifndef SCREEN_H_DEFINED
#define SCREEN_H_DEFINED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "EventHandler.h"
//#include "ScreenManager.h"
#include "Component.h"

using namespace std;
class ScreenManager;
//class EventHandler;

class Screen {
  public:
  Screen(EventHandler* e, ScreenManager* s, SDL_Renderer* r, int w, int h): width(w), height(h), renderer(r), eh(e), sm(s) {
  }
  //~Screen() {
  //  delete eh;
  //  delete sm;
  //delete renderer;
  //}
  virtual void mousePressed() {
    //cout << "somewhere clicked" << end;
    for (Component* c : components) {
      if (c->isOver(eh->xMouse, eh->yMouse)) {
        c->clicked();
      }
    }
  }
  virtual void update() {
  }
  virtual void render() {
    cout <<  "Problem" << endl;
  }
  SDL_Renderer* renderer;
  vector< Component* > components;
  EventHandler* eh;
  ScreenManager* sm;
  int width;
  int height;
};
#endif /* SCREEN_H_DEFINED */
