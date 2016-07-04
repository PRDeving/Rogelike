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
    std::string name;
    SDL_Texture* inventoryImage;
    Sprites::SpriteObj spritesheet;
    unsigned int weight;
    unsigned int quantity;
    unsigned int use_options = 0x00;
  } Item;

  class _Inventory {
    private:
      unsigned int id;
      int capacity;
      std::vector<Item> items;
    public:
      Item* addItem(unsigned int);
  };
  _Inventory Inventory;

  Item* _Inventory::addItem(unsigned int ID) {
    int c = this->items.size();
    Item *found = nullptr;
    while(c--) {
      found = &items[c];
      if(found->id == ID) {
        found->quantity += 1;
        return found;
      }
    }

    // found.inventoryImage = Textures::loadTexture(inventoryImage, ren);
    // found.spritesheet = Sprites::Sprite(spritesheet, ren, 4, 9, 2);

    Item tmp;
    tmp.id = ID;
    tmp.name = "Test item 1";
    tmp.weight = 1;
    tmp.quantity = 1;
    tmp.use_options |= IN_HEAD | IS_EQUIPABLE;
    this->items.push_back(tmp);
    return &tmp;
  }

#endif
