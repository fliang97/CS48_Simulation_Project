#ifndef EVENTHANDLER_H_DEFINED
#define EVENTHANDLER_H_DEFINED


class EventHandler {
  EventHandler() {
    running = true;
    xMouse = 0;
    yMouse = 0;
  }
  bool running;
  int xMouse;
  int yMouse;
}

#endif /* EVENTHANDLER_H_DEFINED */
