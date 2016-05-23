#include <string>
#include <iostream>
#include <SDL.h>

const int SCREEN_W = 400;
const int SCREEN_H = 400;

#include "utils/SDL_CleanUp.h"
#include "utils/SDL_ErrorLog.h"
#include "utils/TexturesHandler.h"

#include "prefabs/player.h"

#include "assets/map.h"


int main (int argc, char* argv[]) {
  srand(time(NULL));

  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
  if( !( IMG_Init( imgFlags ) & imgFlags ) ){
    riseSDLError(std::cout, "SDL_image");
  }

  SDL_Window *win = SDL_CreateWindow("Rogelike", 100, 100, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
  if (win == nullptr){
    riseSDLError(std::cout, "SDL_CreateWindow");
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr){
    SDL_DestroyWindow(win);
    riseSDLError(std::cout, "SDL_CreateRenderer");
    SDL_Quit();
    return 1;
  }



  // SDL_Texture *grass = Textures::loadTexture("../media/grass.jpg", ren);
  SDL_Texture *grass = Textures::loadTexture("../media/rock.png", ren);

  Map m(ren,100,100);
  Player pl(ren, "../media/claude.png", m);
  // std::cout << m.length() << std::endl;

  bool quit = false;
  SDL_Event e;

  while(!quit){

    // EVENTS HANDLING
    while(SDL_PollEvent(&e)){
      if (e.type == SDL_KEYDOWN){
        switch (e.key.keysym.scancode) {
          case 26:
            pl.Up();
          break;
          case 7:
            pl.Right();
          break;
          case 22:
            pl.Down();
          break;
          case 4:
            pl.Left();
          break;
          case 41:
            quit = true;
          break;
        }
      }
      if (e.type == SDL_QUIT){
        quit = true;
      }
    }

    SDL_RenderClear(ren);

    Textures::renderTexture(grass, ren, 0, 0, SCREEN_W, SCREEN_H);
    m.Render(ren, pl.pos);
    pl.Render(ren, 1, 1, m);


    SDL_RenderPresent(ren);
  }


  cleanup(grass, ren, win);
  IMG_Quit();
  SDL_Quit();
}
