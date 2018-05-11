#ifndef MAINMENUSCREEN_H_DEFINED
#define MAINMENUSCREEN_H_DEFINED


class MainMenuScreen : public Screen {
  public:
  MainMenuScreen(EventHandler &eh, ScreenManager* sm): Screen(eh, sm) {
    sb = new StartButton(sm->width/3, sm->height/3, sm->width/3, sm->height/3);
    components.push_back(sb);
  }

  void update() {
  }
  void render() {
    sb->render();
  }
private:
  StartButton* sb;
}


#endif /* MAINMENUSCREEN_H_DEFINED */
