#ifndef H_SPRITE
#define H_SPRITE

#include "TexturesHandler.h"

namespace Sprites {
  struct SpriteObj{
    // spriteSheet size
    int sheetW;
    int sheetH;
    // frames per line/col
    int vFrames;
    int hFrames;
    // frames size
    int frameW;
    int frameH;

    int currFrameH = 0;
    int currFrameV = 0;

    int animSpeedC;
    int animSpeed;

    SDL_Texture* spriteSheet;
  };

  SpriteObj Sprite(std::string spritesheet, SDL_Renderer* ren, int vFrames, int hFrames, int w, int h, int speed) {
    std::cout << "Generating Sprite" << std::endl;
    SpriteObj tempSprite;
    std::cout << "SpriteOBJ generated" << std::endl;
    tempSprite.spriteSheet = Textures::loadTexture(spritesheet, ren);
    std::cout << "Sprite generated" << std::endl;

    tempSprite.vFrames = vFrames;
    tempSprite.hFrames = hFrames;
    tempSprite.sheetW = w;
    tempSprite.sheetH = h;

    tempSprite.frameW = tempSprite.sheetW / tempSprite.hFrames;
    tempSprite.frameH = tempSprite.sheetH / tempSprite.vFrames;

    tempSprite.animSpeedC = speed;

    return tempSprite;
  }

  SpriteObj Sprite(std::string spritesheet, SDL_Renderer* ren, int vFrames, int hFrames, int speed) {
    std::cout << "Generating Sprite" << std::endl;
    SpriteObj tempSprite;
    std::cout << "SpriteOBJ generated" << std::endl;
    tempSprite.spriteSheet = Textures::loadTexture(spritesheet, ren);
    std::cout << "Sprite generated" << std::endl;

    tempSprite.vFrames = vFrames;
    tempSprite.hFrames = hFrames;

    SDL_QueryTexture(tempSprite.spriteSheet, NULL, NULL, &tempSprite.sheetW, &tempSprite.sheetH);

    tempSprite.frameW = tempSprite.sheetW / tempSprite.hFrames;
    tempSprite.frameH = tempSprite.sheetH / tempSprite.vFrames;

    tempSprite.animSpeedC = speed;

    return tempSprite;
  }

  void drawFrame(SDL_Renderer* ren, SpriteObj &sp, int x, int y) {
    SDL_Rect sec;
    sec.x = sp.frameW * sp.currFrameH;
    sec.y = sp.frameH * sp.currFrameV;
    sec.w = sp.frameW;
    sec.h = sp.frameH;
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = sp.frameW;
    pos.h = sp.frameH;
    Textures::renderTexture(sp.spriteSheet, ren, sec, pos);
  }

  void getNextFrame(SDL_Renderer* ren, SpriteObj &sp, int x, int y) {
    if(sp.animSpeed++ > sp.animSpeedC){
      if(sp.currFrameH++ >= sp.hFrames-1) sp.currFrameH = 0;
      sp.animSpeed = 0;
    }
    drawFrame(ren, sp, x, y);
  }

  void changeSerie(SpriteObj &sp, int serie) {
    sp.currFrameV = serie;
  }

  void changeFrame(SpriteObj &sp, int frame) {
    sp.currFrameH = frame;
  }

}

#endif
