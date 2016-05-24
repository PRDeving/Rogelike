#ifndef H_ASSETS_STATUSBAR
#define H_ASSETS_STATUSBAR
  class StatusBar {
    int x, y;

    std::string name;
    int xp, nextLvl, level;
    int stamina, hp, energy;
    int maxStamina, maxHp, maxEnergy;

    SDL_Color color = { 255, 255, 255, 255 };
    Fonts::Font font1 = Fonts::newFont("../media/CaveatBrush-Regular.ttf", 18, color);
    Fonts::Font fontSmall = Fonts::newFont("../media/CaveatBrush-Regular.ttf", 14, color);

    public:
      void getData(Player& player);
      void Render(SDL_Renderer* ren);
  };

  void StatusBar::getData(Player& player){
    name = player.name;
    xp = player.xp;
    nextLvl = player.nextLvl;
    level = player.level;
    stamina = player.stamina;
    maxStamina = player.maxStamina;
    hp = player.hp;
    maxHp = player.maxHp;
    energy = player.energy;
    maxEnergy = player.maxEnergy;
  }

  void StatusBar::Render(SDL_Renderer* ren){
    std::string txtname = name + " Level " + std::to_string(level) + "  xp(" + std::to_string(xp) + "/" + std::to_string(nextLvl) + ")";
    std::string txthp = "HP: " + std::to_string(hp) + "/" + std::to_string(maxHp);
    std::string txtenergy = "Energy: " + std::to_string(energy) + "/" + std::to_string(maxEnergy);
    std::string txtstamina = "Stamina: " + std::to_string(stamina) + "/" + std::to_string(maxStamina);

    SDL_Texture* nameT = Fonts::processText(ren, txtname, font1);
    SDL_Texture* hpT = Fonts::processText(ren, txthp, font1);
    SDL_Texture* enT = Fonts::processText(ren, txtenergy, font1);
    SDL_Texture* stT = Fonts::processText(ren, txtstamina, font1);

    Textures::renderTexture(nameT, ren, 5, 5);
    Textures::renderTexture(hpT, ren, 5, 30);
    Textures::renderTexture(enT, ren, 5, 50);
    Textures::renderTexture(stT, ren, 5, 70);

    std::string txtversion = "v " + std::string(VERSION);
    SDL_Texture* vT = Fonts::processText(ren, txtversion, fontSmall);
    Textures::renderTexture(vT, ren, SCREEN_W - 50, SCREEN_H - 25);

    cleanup(nameT, hpT, enT, stT, vT);
  }
#endif
