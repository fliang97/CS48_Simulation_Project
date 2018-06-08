# Popiko - Population Ecology Simulation (CS48_G08)


## How to run
Required components:
- SDL2 Library
- SDL2_Image Library
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
  
## Running the draft project simulation
For the first draft of this project, we have focused on creating the core game engine and core simulation features. For this reason, most elements still take the apperance of simple, colored rectangular boxes. Further efforts on improving the visuals will be implemented in later iterations, such as adding sprites and animations.

First, click on the center of the initial screen to start the simulation.  There is a known bug here where a start button image will be displayed for some Linux installations, but not on xCode Mac installations.  Despite the image not rendering, the clickable start button area is there and can be clicked on.

![Main Menu](https://i.imgur.com/6RRlW91.jpg "Main Menu - Final Project")

In the game/simulation screen, the current simulation automatically runs on its own.
- Light blue area is the main game board
- Green tiles represent **Grass**, which grow and spread randomly on the board
- Brown tile represents a **Cow**, which travels in random directions and eats any Grass (green tile) along its path
- Purple button in the top left corner is a placeholder for future feature buttons
- Dark green area is background
- User can *drag* Entities on the game board (Cows, Grass) and move them along with cursor movement (not yet implemented).

![Game Screen](https://i.imgur.com/3sC7DLO.jpg "Game Screen - Final Project")


Known bugs
The intial screen that is displayed should contain a start button in the center.
