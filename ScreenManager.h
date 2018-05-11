#ifndef SCREENMANAGER_H_DEFINED
#define SCREENMANAGER_H_DEFINED


class ScreenManager {
  public:
  ScreenManager(EventHandler &eh, int w, int h):width(w), height(h) {
    MainMenuScreen mms(eh, this);
    GameScreen gs(eh, this);
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
  int current_screen;
  vector<Screen> screens;
  EventHandler &eh;
  int width;
  int height;
}


#endif /* SCREENMANAGER_H_DEFINED */
