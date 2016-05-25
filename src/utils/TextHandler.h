#ifndef H_TEXTHANDLER
#define H_TEXTHANDLER

  namespace Fonts {
    typedef struct {
      TTF_Font* format;
      SDL_Color color;
    } Font;

    Font newFont(const std::string &fontFile, int size, SDL_Color color) {
      Font t;

      t.format = TTF_OpenFont(fontFile.c_str(), size);
      if (t.format == nullptr){
        riseSDLError(std::cout, "TTF_OpenFont");
      } 
      t.color = color;
      return t;
    }

    SDL_Texture* processText(SDL_Renderer* renderer, const std::string &message, const Font font){

      //We need to first render to a surface as that's what TTF_RenderText
      //returns, then load that surface into a texture
      SDL_Surface *surf = TTF_RenderText_Blended(font.format, message.c_str(), font.color);
      if (surf == nullptr){
        TTF_CloseFont(font.format);
        riseSDLError(std::cout, "TTF_RenderText");
        return nullptr;
      }
      SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
      if (texture == nullptr){
        riseSDLError(std::cout, "CreateTexture");
      }
      //Clean up the surface and font
      SDL_FreeSurface(surf);
      return texture;
    }
  }

#endif
