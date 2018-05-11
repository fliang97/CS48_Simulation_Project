#ifndef STARTBUTTON_H_DEFINED
#define STARTBUTTON_H_DEFINED


class Button {
  StartButton(int x, int y, int w, int h, ScreenManager* sm): Button(x, y, w, h) {
  }
  clicked() override {
    sm->current_screen = 1;
  }
  render() override {
    SDL_Rect rect = {x, y, w, h};
    //SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
    SDL_SetRenderDrawColor( renderer, 100, 50, 0, 255 );
    SDL_RenderFillRect( renderer, &rect);
  }
}
#endif /* START_H_DEFINED */
