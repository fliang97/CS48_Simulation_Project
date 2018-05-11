#ifndef MAINMENUSCREEN_H_DEFINED
#define MAINMENUSCREEN_H_DEFINED


class MainMenuScreen : public Screen {
  public:
  MainMenuScreen(EventHandler &eh, ScreenManager* sm): Screen(eh, sm) {
    sb = new StartButton(sm->width/3, sm->height/3, sm->width/3, sm->height/3, sm);
    components.push_back(sb);
  }

  void update() {
  }
  void render() {
    SDL_Rect rect = {0, 0, width, height};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 0, 100, 255 );
    SDL_RenderFillRect( renderer, &rect);
    sb->render();
  }
private:
  StartButton* sb;
}


#endif /* MAINMENUSCREEN_H_DEFINED */
