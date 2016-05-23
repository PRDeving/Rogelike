#ifndef H_PREFAB_PLAYER
#define H_PREFAB_PLAYER

  #include "../utils/Sprite.h"
  #include "../utils/Vec2.h"

  #include "../assets/map.h"

  class Player {
    Sprites::SpriteObj sprite;

    int vSpeed = 0;
    int hSpeed = 0;

    public:
      SDL_Rect pos;
      // Player(SDL_Texture* texture);
      Player(SDL_Renderer* renderer, std::string spritesheet, Map &m);
      ~Player();

      void Down();
      void Up();
      void Right();
      void Left();
      void Render(SDL_Renderer* ren, int x, int y, Map &m);
  };

  Player::~Player() {
    std::cout << "destroy player instance" << std::endl;
    cleanup(sprite.spriteSheet);
  }
  Player::Player(SDL_Renderer* renderer, std::string spritesheet, Map &m) {
    this->sprite = Sprites::Sprite(spritesheet, renderer, 4, 4, 8);
    this->pos.x = m.init.x*60;// - (SCREEN_W / 2);
    this->pos.y = m.init.y*60;// - (SCREEN_H / 2);
  }


  void Player::Up(){
    hSpeed = 0;
    vSpeed--;
  }
  void Player::Down(){
    hSpeed = 0;
    vSpeed++;
  }
  void Player::Right(){
    vSpeed = 0;
    hSpeed++;
  }
  void Player::Left(){
    vSpeed = 0;
    hSpeed--;
  }
  void Player::Render(SDL_Renderer* ren, int x, int y, Map &m) {
    if(m.Walkable((pos.x + hSpeed)/60, (pos.y + vSpeed)/60)){
      pos.y += vSpeed;
      pos.x += hSpeed;
    }
    // vSpeed = 0;
    // hSpeed = 0;
    if(vSpeed != 0 || hSpeed !=0){
      if(vSpeed > 0){
        Sprites::changeSerie(this->sprite, 0);
      } else if(vSpeed < 0) {
        Sprites::changeSerie(this->sprite, 3);
      } else if(hSpeed < 0) {
        Sprites::changeSerie(this->sprite, 1);
      } else if(hSpeed > 0) {
        Sprites::changeSerie(this->sprite, 2);
      }
      Sprites::getNextFrame(ren, this->sprite, SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
    } else{
      Sprites::changeFrame(this->sprite, 0);
      Sprites::drawFrame(ren, this->sprite,  SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
    }
  }
#endif
