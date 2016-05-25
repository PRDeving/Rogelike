# Rogelike
Hack-and-slash Rogelike game wirtten in C++ and SDL2

#Dependencies
 - SDL2
 - SDL_image
 - SDL_ttf

#Compile
compile script has been written to easyly compile in MAC OS systems (using -framework) and Unix systems

to compile in Mac OS or Unix run: `./compile`
to compile in other systems run `gcc`, `g++`, or `clang` importing the required libraries

compile scripts automaticly tags the version as provided, version can be changed passing the version as argument

```bash
  ./compile "0.1.1"
```

#Run
`./bin/rogelike`


#BRANCHES
  - master: Development
  - dist: v0.1.0

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
  - Compile script updated for Mac and Linux

### 0.1.0
  - Texture-based GPU renderization
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
  - Modified compile script to define build VERSION
  - New Level when R pressed (testing pruporses)

