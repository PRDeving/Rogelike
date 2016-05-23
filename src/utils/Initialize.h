#ifndef H_INITIALIZE
#define H_INITIALIZE
  SDL_Window* win = NULL;
  SDL_Renderer* ren = NULL;
  void riseSDLError(std::ostream &os, const std::string &msg);

  bool Initialize() {
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_VIDEO) != 0){
      std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
      SDL_Quit();
      return false;
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ){
      riseSDLError(std::cout, "IMG_Init");
      SDL_Quit();
      return false;
    }

    if(TTF_Init() < 0){
      riseSDLError(std::cout, "TTF_Init");
      IMG_Quit();
      SDL_Quit();
      return false;
    }

    win = SDL_CreateWindow("Rogelike", 100, 100, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
    if (win == nullptr){
      riseSDLError(std::cout, "SDL_CreateWindow");
      IMG_Quit();
      TTF_Quit();
      SDL_Quit();
      return false;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
      SDL_DestroyWindow(win);
      riseSDLError(std::cout, "SDL_CreateRenderer");
      IMG_Quit();
      TTF_Quit();
      SDL_Quit();
      return false;
    }
    return true;
  }
#endif
