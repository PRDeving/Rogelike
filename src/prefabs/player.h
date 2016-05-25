#ifndef H_PREFAB_PLAYER
#define H_PREFAB_PLAYER

  #include "../utils/Sprite.h"
  #include "../utils/Vec2.h"

  #include "../assets/map.h"

  class Player {
    Sprites::SpriteObj sprite;
    // Sprites::SpriteObj attack;

    Sprites::SpriteObj head;
    Sprites::SpriteObj torso;
    Sprites::SpriteObj legs;
    Sprites::SpriteObj hands;

    bool keypressed[256];
    float vSpeed = 0.0f;
    float hSpeed = 0.0f;

    int speed = 2;

    void Down(int shift);
    void Up(int shift);
    void Right(int shift);
    void Left(int shift);
    void Attack();


    public:
      SDL_Rect pos;

      std::string name = "John Doe";
      int level = 1;
      int xp = 0;
      int nextLvl = level * 10;

      int maxStamina = 10;
      int stamina = 10;
      int staminaCount = 0;
      int strength = 100;

      int maxHp = 100;
      int hp = 100;

      int maxEnergy = 100;
      int energy = 100;

      Player(SDL_Renderer* renderer, std::string spritesheet, Map &m);
      ~Player();

      void set(Map &m);
      void Controls(bool mode, SDL_Scancode key);
      void Stop();
      void Update(Map &m);
      void Render(SDL_Renderer* ren, int x, int y, Map &m);
  };

  Player::~Player() {
    std::cout << "destroy player instance" << std::endl;
    cleanup(sprite.spriteSheet, head.spriteSheet, torso.spriteSheet, legs.spriteSheet, hands.spriteSheet);
  }
  Player::Player(SDL_Renderer* renderer, std::string spritesheet, Map &m) {
    this->sprite = Sprites::Sprite(spritesheet, renderer, 4, 9, 2);

    this->head = Sprites::Sprite("./media/hair_head.png", renderer, 4, 9, 2);
    this->torso = Sprites::Sprite("./media/shirt_torso.png", renderer, 4, 9, 2);
    this->legs = Sprites::Sprite("./media/robe_legs.png", renderer, 4, 9, 2);
    set(m);
  }
  void Player::set(Map &m) {
    this->pos.x = m.init.x*60;
    this->pos.y = m.init.y*60;
    this->vSpeed = 0.0f;
    this->hSpeed = 0.0f;
  }

  void Player::Controls(bool mode, SDL_Scancode key) {
    if(mode) keypressed[key] = true;
    else keypressed[key] = false;
  }

  void Player::Up(int shift){
    hSpeed = 0;
    vSpeed = -1 * (speed + shift);
  }
  void Player::Down(int shift){
    hSpeed = 0;
    vSpeed = speed + shift;
  }
  void Player::Right(int shift){
    vSpeed = 0;
    hSpeed = speed + shift;
  }
  void Player::Left(int shift){
    vSpeed = 0;
    hSpeed = -1 * (speed + shift);
  }
  void Player::Stop(){
    vSpeed = 0;
    hSpeed = 0;
  }
  void Player::Attack() {
    std::cout << "Attack" << std::endl;
  }
  void Player::Update(Map &m){
    int shift = (keypressed[225] && stamina > 0);

    if(staminaCount++ >= strength){
      if(shift){
        stamina--;
      } else if(stamina < maxStamina){
        stamina++;
      }
      staminaCount = 0;
    }

    for(int c = 0; c < 256; c++){
      if(!keypressed[c]) continue;
      switch(c) {
        case 26:
          Up(shift);
        break;
        case 7:
          Right(shift);
        break;
        case 22:
          Down(shift);
        break;
        case 4:
          Left(shift);
        break;
        case 44:
          Attack();
        break;
      }
    }

    if(m.Walkable((pos.x + hSpeed)/60, (pos.y + vSpeed)/60)){
      pos.y += (int)vSpeed;
      pos.x += (int)hSpeed;
      vSpeed += (vSpeed > 0)? -0.1 : ((vSpeed < 0)? 0.1 : 0.0);
      hSpeed += (hSpeed > 0)? -0.1 : ((hSpeed < 0)? 0.1 : 0.0);
    } else {
      Stop();
    }

  }
  void Player::Render(SDL_Renderer* ren, int x, int y, Map &m) {
    Update(m);
    if(pos.x/60 == m.goal.x && pos.y/60 == m.goal.y) m.goalReached = true;

    if((int)vSpeed != 0 || (int)hSpeed !=0){
      if(vSpeed > 0){
        Sprites::changeSerie(this->head, 2);
        Sprites::changeSerie(this->torso, 2);
        Sprites::changeSerie(this->legs, 2);
        Sprites::changeSerie(this->sprite, 2);
      } else if(vSpeed < 0) {
        Sprites::changeSerie(this->head, 0);
        Sprites::changeSerie(this->torso, 0);
        Sprites::changeSerie(this->legs, 0);
        Sprites::changeSerie(this->sprite, 0);
      } else if(hSpeed < 0) {
        Sprites::changeSerie(this->head, 1);
        Sprites::changeSerie(this->torso, 1);
        Sprites::changeSerie(this->legs, 1);
        Sprites::changeSerie(this->sprite, 1);
      } else if(hSpeed > 0) {
        Sprites::changeSerie(this->head, 3);
        Sprites::changeSerie(this->torso, 3);
        Sprites::changeSerie(this->legs, 3);
        Sprites::changeSerie(this->sprite, 3);
      }

      Sprites::getNextFrame(ren, this->sprite, SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
      Sprites::getNextFrame(ren, this->head, SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
      Sprites::getNextFrame(ren, this->torso, SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
      Sprites::getNextFrame(ren, this->legs, SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);

    } else{
      Sprites::changeFrame(this->sprite, 0);
      Sprites::changeFrame(this->head, 0);
      Sprites::changeFrame(this->torso, 0);
      Sprites::changeFrame(this->legs, 0);
      Sprites::drawFrame(ren, this->sprite,  SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
      Sprites::drawFrame(ren, this->head,  SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
      Sprites::drawFrame(ren, this->torso,  SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
      Sprites::drawFrame(ren, this->legs,  SCREEN_W / 2 - this->sprite.frameW/2, SCREEN_H / 2 - this->sprite.frameH);
    }
  }
#endif
