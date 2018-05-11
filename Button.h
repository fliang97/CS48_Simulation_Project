#ifndef BUTTON_H_DEFINED
#define BUTTON_H_DEFINED

#include "Component.h"

class Button : Component{
public:
  Button(int x, int y, int w, int h, SDL_Renderer* r): Component(x, y, w, h, r) {
  }

  virtual void clicked();
  virtual void render();
};
#endif /* BUTTON_H_DEFINED */
