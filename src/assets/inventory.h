#ifndef H_ASSETS_INVENTORY
#define H_ASSETS_INVENTORY

  // USE OPTIONS
  const unsigned int IS_EQUIPABLE   = 0x01;
  const unsigned int IS_POTION      = 0x02;
  const unsigned int IN_HEAD        = 0x04;
  const unsigned int IN_TORSO       = 0x08;
  const unsigned int IN_ARMS        = 0x10;
  const unsigned int IN_HANDS       = 0x20;
  const unsigned int IN_LEGS        = 0x40;
  const unsigned int IN_FEETS       = 0x80;

  typedef struct {
    unsigned int id;
    unsigned int quantity;
  } Inveentory_entry;

  typedef struct {
    unsigned int id;
    int capacity;
    std::vector<Item> items;
  } Inventory;

  typedef struct {
    unsigned int id;
    std::string name;
    SDL_Texture* inventoryImage;
    Sprites::SpriteObj spritesheet;
    unsigned int weight;
    unsigned int use_options = 0x00;
  } Item;

  Item* newItem(std::string inventoryImage, std::string spritesheet) {
    this->inventoryImage = Textures::loadTexture(inventoryImage, ren);
    this->spritesheet = Sprites::Sprite(spritesheet, ren, 4, 9, 2);
  }

#endif
