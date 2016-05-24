#ifndef H_ASSETS_MAP
#define H_ASSETS_MAP

#include <vector>

#include "../utils/Random.h"
#include "../utils/Vec2.h"
#include "../utils/SDL_CleanUp.h"

  class Map {
    int w;
    int h;

    std::vector<vec2> cave;

    // Sprites::SpriteObj rock;
    Sprites::SpriteObj path;
    Sprites::SpriteObj door;


    public:
      vec2 init;
      vec2 goal;
      bool goalReached = false;

      void GenerateLevel();
      Map(SDL_Renderer* ren, int w, int h);
      ~Map();
      bool Walkable(int x, int h);
      bool Walkable(vec2 tile);
      void Render(SDL_Renderer* ren, SDL_Rect &camera);
  };

  Map::Map(SDL_Renderer* ren, int w, int h) {
    path = Sprites::Sprite("../media/path.png", ren, 1, 1, 80, 70, 1);
    door = Sprites::Sprite("../media/door.png", ren, 1, 5, 7);
    this->w = w;
    this->h = h;

    this->GenerateLevel();
  }
  Map::~Map() {
    cleanup(this->path.spriteSheet);
    cleanup(this->door.spriteSheet);
  }

  void Map::GenerateLevel() {
    cave.clear();
    this->door.currFrameH = 0;
    this->goalReached = false;

    vec2 step;
    step.x = this->w / 2;
    step.y = this->h / 2;
    cave.push_back(step);
    this->init = step;

    int cs = 30000;
    while(cs--) {
      switch(Random(0,2)) {
        case 0:
          step.x += Random(0, 3) - 1;
        break;
        case 1:
          step.y += Random(0, 3) - 1;
        break;
      }
      cave.push_back(step);

      if(step.x == 0 || step.y == 0 || step.x == this->w || step.y == this->h){
        this->goal = step;
        break;
      }
    }

    std::cout << "Map Generated from " << init.x << "/" << init.y << " to " << goal.x << "/" << goal.y << std::endl;
  }

  bool Map::Walkable(int x, int y){
    for(int t = 0; t < cave.size(); t++)
      if(cave[t].x == x && cave[t].y == y) return true;
    return false;
  }
  bool Map::Walkable(vec2 tile){
    for(int t = 0; t < cave.size(); t++)
      if(cave[t].x == tile.x && cave[t].y == tile.y) return true;
    return false;
  }

  void Map::Render(SDL_Renderer* ren, SDL_Rect &camera) {
    for(int t = 0; t < cave.size(); t++)
      Sprites::drawFrame(ren, this->path, (cave[t].x*60) - camera.x + SCREEN_W/2 - 10, (cave[t].y*60) - camera.y + SCREEN_H/2 - 10 );

    if(goalReached){
      Sprites::getNextFrame(ren, this->door, (cave[cave.size() -1].x*60) - camera.x + SCREEN_W/2, (cave[cave.size() -1].y*60) - camera.y + SCREEN_H/2 - 30 );
        SDL_Event event;
        SDL_memset(&event, 0, sizeof(event)); /* or SDL_zero(event) */
        event.type = 1211;
        SDL_PushEvent(&event);
      if(this->door.currFrameH == 4) {
        SDL_Event event;
        SDL_memset(&event, 0, sizeof(event)); /* or SDL_zero(event) */
        event.type = 1212;
        SDL_PushEvent(&event);
      }
    } else {
      Sprites::drawFrame(ren, this->door, (cave[cave.size() -1].x*60) - camera.x + SCREEN_W/2, (cave[cave.size() -1].y*60) - camera.y + SCREEN_H/2 - 30 );
    }
  }
#endif
