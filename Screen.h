#ifndef SCREEN_H_DEFINED
#define SCREEN_H_DEFINED

#include "EventHandler.h"
#include "ScreenManager.h"
#include "Component.h"

class Screen {
  public:
  Screen(EventHandler &eh, ScreenManager* sm) {
    this->eh = eh;
    this->sm = sm;
  }
  void mousePressed() {
    for (Component c : components) {
      if (c.isOver()) {
        c.clicked();
      }
    }
  }
  void update() {
  }
  void render() {
  }
private:
  vector< *Component > components;
  EventHandler &eh;
  ScreenManager* sm;
}
#endif /* SCREEN_H_DEFINED */
