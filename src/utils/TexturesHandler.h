#ifndef H_TEXTURESHANDLER
#define H_TEXTURESHANDLER

#include "./SDL_CleanUp.h"
#include "./SDL_ErrorLog.h"

namespace Textures {
  SDL_Texture* loadTexture(std::string source, SDL_Renderer *renderer) {
    SDL_Texture* texture = NULL;

    texture = IMG_LoadTexture(renderer, source.c_str());
    if (texture == nullptr){
      riseSDLError(std::cout, "SDL_CreateTextureFromSurface Error: ");
      return NULL;
    }
    return texture;
  }

  void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;

    SDL_RenderCopy(renderer, texture, NULL, &dest);
  }

  void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, texture, NULL, &dest);
  }

  void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect dest) {
    SDL_RenderCopy(renderer, texture, NULL, &dest);
  }

  void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect section, SDL_Rect dest) {
    SDL_RenderCopy(renderer, texture, &section, &dest);
  }

}

#endif
