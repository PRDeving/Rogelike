#ifndef H_HEADERS
#define H_HEADERS
  #include "./definitions.h"


  // Dependencies
  #include <utility>
  #include <cstring>
  #include <iostream>
  #include <vector>
  #include <time.h>
  #include <random>

  // Core
  #ifdef __linux
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
  #elif __APPLE__
    #include <SDL.h>
    #include <SDL_image.h>
    #include <SDL_ttf.h>
  #endif

  // Utils
  #include "./Initialize.h"
  #include "./SDL_ErrorLog.h"
  #include "./SDL_CleanUp.h"
  #include "./TexturesHandler.h"
  #include "./TextHandler.h"

  // Prefabs
  #include "../prefabs/player.h"

  // Assets
  #include "../assets/map.h"
  #include "../assets/statusBar.h"
  #include "../assets/inventory.h"
#endif
