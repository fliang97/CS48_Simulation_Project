# Popiko - Population Ecology Simulation (CS48_G08)

## How to run in Windows Visual Studio (to be added)

## How to run in MacOS XCode
Required components:
- SDL2 Library
- SDL2_Image Library
- SDL2_TTF Library
- Xcode (on MacOS)


SDL libraries can be installed via homebrew:

`/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`

SDL2: `brew install sdl2`

SDL2_Image: `brew install sdl2_image`

SDL2_TTF: `brew install sdl2_ttf`

Importing SDL Libraries in XCode:
- Open Xcode, and create a new project. Choose C++ as the language.
- Click the project (a blue icon in the left list), go into `Building Settings -> Header Search Paths`.
- Enter `/usr/local/include/`
- Go to `Build Phases -> Link Binary with Libraries -> '+' -> Add other`
- Press **'Command+Shift+G'** -> `/usr/local/cellar`
- Now open the corresponding libraries. (filename might be different due to different versions)

  SDL2: `sdl2/2.0.4/lib/libSDL2-2.0.0.dyblib`

  SDL2_Image: `sdl2_image/2.0.3/lib/libSDL2_image-2.0.0.dylib`

  SDL2_TTF: `sdl2_ttf/2.0.14/lib/libSDL2_ttf-2.0.0.dyblib`


## How to run on Debian
Required components:
- SDL2 Library
- SDL2_Image Library
- SDL2_TTF Library

SDL2: `sudo apt-get install libsdl2-2.0`

SDL2_Image: `apt-get install libsdl2-image-dev`

SDL2_TTF: `apt-get install libsdl2-ttf-2.0-0`

Download all files into a folder.

Compile using this g++ command:

g++ -std=c++14 -O3 \*.cpp \*.c -o sim  -lSDL2 -lSDL2_image -lSDL2_ttf


Run simulation using ./sim from directory containing all files.

## How to run the simulation...and change your life forever
In the final draft of this projects, we made more efforts to implement better graphics for the simulation, as promised in the first draft project.

First, click on the large "START" button in the center of the initial screen to start the simulation.

![Main Menu](https://i.imgur.com/6RRlW91.jpg "Main Menu - Final Project")

In the game/simulation screen, the current simulation automatically runs on its own.
- Light blue area is the main game board
- Green areas represent **Grass**, which grow and spread randomly on the board
- Yellow areas represent **Dirt**, which (in a way) serve as the board
- **Cows** travel in random directions and eats any Grass (green tile) along its path. A pink color indicates that it's either too hungry or too old to live.
- **Wolves** use a pathing algorithm to chase after Cows when they are hungry. A dark purple color indicates that it's either too hungry or too old to live.

![Game Screen](https://i.imgur.com/3sC7DLO.jpg "Game Screen - Final Project")

### Supported features:
- **Zoom in/out** with the purple (+) button or green (-) button
- **Inspect graph** with the red button, which shows curves of overall populations as boom-bust cycles take place in the simulation
- **Adjust speed** with the red arrows (-) or yellow arrows (+) in the bottom left corner.
- **Manually place** a Cow, Grass or a Wolf by clicking the bottom right buttons and clicking on the board to place them. Click button a second time to disable placement when clicking.

### Known bugs:
- Zoom in and out slightly changes aspect ratio
- Scale width and height info is stored as an int and zooming muliplies it by a double scaler, which is then rounded.
- Converting the scaling numbrs to doubles amy solve this issue, but would require extensive changes since it's used all over the program.

## Acknowledgements
- Using plot.h and llist.h. (c) 2015 Bertrand Martel, under The MIT License (MIT).
- Cow sprite: https://www.spriters-resource.com/snes/harvestmoon/sheet/31564/ by NFinity.
- Wolf sprite: https://www.spriters-resource.com/ds_dsi/pururun1/sheet/45405/ by Dazz.
- Grass textures: https://opengameart.org/content/grass-texture-pack under the Public Domain License (CC0).
- Water textures: https://dadrian.deviantart.com/art/Water-Texture-49283686
- Wood background: https://www.photohdx.com/pic-917/brown-vintage-wood-background
- Main theme (pasture background): https://commons.wikimedia.org/wiki/File:Dairy_cows_on_pasture_in_Ireland.jpg
