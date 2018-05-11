#ifndef COMPONENT_H_DEFINED
#define COMPONENT_H_DEFINED


class Component {
  Component(int x, int y, int w, int h): xpos(x), ypos(y), width(w), height(h) {
  }
  bool isOver(int mousex, int mousey) {
    return (mousex >= xpos && mousex < xpos + width && mousey >= ypos && mousey < ypos + height);
  }
  void clicked();
  void render();
  int xpos;
  int ypos;
  int width;
  int height;
}
#endif /* COMPONENT_H_DEFINED */
