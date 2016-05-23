# Rogelike
A simple Hack-and-slash Rogelike game in C++

#Dependencies
 - SDL2
 - SDL_image
 - SDL_ttf

#Compile
compile script has been written to easyly compile in MAC OS systems (using -framework)

to compile in Mac Os run: `./compile`
to compile in other systems run `gcc`, `g++`, or `clang` importing the required libraries

compile scripts automaticly tags the version as provided, version can be changed passing the version as argument

```bash
  ./compile "0.1.1"
```

#Run
`./bin/rogelike`


#SCHEDULED
  - refactor "chunky spritting" system
  - attack
  - NPC Enemies
  - raycasted Field of View
  - pretty cave borders
  - random generated Store
  - economic system
  - loot and inventory system
  - pause
  - game menu GUI
  - save/load game
  - levels storing and continous dungeon, two-way level movement
  - spells
  - music and ambient sounds


#CHANGELOG

### 0.1.0
  - Improved WASD movement system with ease
  - Improved Cave generation algorythm
  - Added final door in each level. when reached, a new level is generated
  - Added sprint system while holding SHIFT
  - Added stamina system
  - Added atmospheric shadowing
  - Implemented "chunky spritting"
  - Implemented simple GUI with relevant data
  - Implemented SDL_ttf
  - propperly separated headers and defines
  - fixed weird PJ position when approaching top tiles
  - fixed typo in TexturesHandler that didnt seize spritesheets propperly
  - Added version number in bottom-right corner
  - Modified compile script to define buil VERSION
  - New Level when R pressed (testing pruporses)

