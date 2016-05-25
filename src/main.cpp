#include "utils/headers.h"

int main (int argc, char* argv[]) {

  if(!Initialize()) return 0;

  if(FullScreen) SDL_SetWindowFullscreen(win, SDL_WINDOW_FULLSCREEN);

  SDL_Texture *grass = Textures::loadTexture("./media/rock.png", ren);
  SDL_Texture *shadow = Textures::loadTexture("./media/shadow.png", ren);
  SDL_Texture *shadow_bg = Textures::loadTexture("./media/bg_shadow.png", ren);
  
  const int MapS = 300;

  StatusBar statusBar;

  Map m(ren,MapS,MapS);
  Player pl(ren, "./media/male_base.png", m);


  // SDL_Color color = { 255, 255, 255, 255 };
  // Fonts::Font font1 = Fonts::newFont("../media/CaveatBrush-Regular.ttf", 21, color);
  // SDL_Texture* text = NULL;


  bool quit = false;
  SDL_Event e;
  while(!quit){

    // EVENTS HANDLING
    while(SDL_PollEvent(&e)){
      if (e.type == 1211) {
        pl.Stop();
      }
      if (e.type == 1212) {
        std::cout << "level Finished!!" << std::endl;
        m.GenerateLevel();
        pl.set(m);
      }
      if (e.type == SDL_QUIT){
        quit = true;
      }

      if (e.type == SDL_KEYDOWN){
        switch (e.key.keysym.scancode) {
          case 41:
            quit = true;
          break;
          case 21:
            SDL_Event event;
            SDL_memset(&event, 0, sizeof(event));
            event.type = 1212;
            SDL_PushEvent(&event);
          break;
          default: 
            pl.Controls(true, e.key.keysym.scancode);
          break;
        }
      }
      if (e.type == SDL_KEYUP){
        switch (e.key.keysym.scancode) {
          default: 
            pl.Controls(false, e.key.keysym.scancode);
          break;
        }
      }
    }

    SDL_RenderClear(ren);

    Textures::renderTexture(grass, ren, 0, 0, SCREEN_W, SCREEN_H);
    Textures::renderTexture(shadow_bg, ren, 0, 0, SCREEN_W, SCREEN_H);
    Textures::renderTexture(shadow_bg, ren, 0, 0, SCREEN_W, SCREEN_H);

    m.Render(ren, pl.pos);
    pl.Render(ren, 1, 1, m);

    Textures::renderTexture(shadow_bg, ren, 0, 0, SCREEN_W, SCREEN_H);
    Textures::renderTexture(shadow_bg, ren, 0, 0, SCREEN_W, SCREEN_H);

    statusBar.getData(pl);
    statusBar.Render(ren);

    SDL_RenderPresent(ren);
  }


  cleanup(grass, shadow, shadow_bg, ren, win);
  IMG_Quit();
  TTF_Quit();
  SDL_Quit();
}
