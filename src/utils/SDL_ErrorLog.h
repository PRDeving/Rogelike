#ifndef H_SDL_ERRORLOG
#define H_SDL_ERRORLOG
  void riseSDLError(std::ostream &os, const std::string &msg){
    os << msg << " error: " << SDL_GetError() << std::endl;
  }
#endif
