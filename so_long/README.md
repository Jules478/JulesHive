# so_long

## What is it?

so_long, a reference to the fourth book in Douglas Adam's Hitchhiker's Guide to the Galaxy series "So Long and Thanks for all the Fish", is a project in the 42 network of coding schools which tasks students with creating a basic 2D game using a library of visual functions, in this case MLX42.

## What game did I make?

Students are allowed to design the game in any way they wish so long as it meets the requirements of the project. These requirments are:

- Full direction control, either with arrow keys or WASD, in all cardinal directions.

- A step counter displayed in shell to track how many moves the play has made.

- At least 1 collectable for the player to move to and collect thus unlocking an exit.

The theme I chose for my project was to pay homage to my personal favourite game series Fallout, by Black Isle Studios and Bethesda Softworks. The title of the game is 'Fallout 5' as a tongue in cheek joke about the new entry to the series. The player controls Vault Boy as he searches the wasteland for bottlecaps, the currency of almost all entries in the series, and then returning to the vault. 

Extra features included in my project were:

- An onscreen step counter that updates in real time alongside the shell display.

- When the player attempts to move into a wall, in this case a radioactive hotspot, the player will receive rads. Each attempt will inflict 10 rads on the player and if the player receives a dose of 1000 rads the player dies and the game is over.

- A random map generator.

## How to run the game

Once the repository is cloned, the cleanest way to create the game is to run "make full" in the shell. This will clone and run the necessary MLX42 library automatically and clean up all dependent files after creating the game executable and the map generator. 

To run the game, type "./so_long <map name>" into the shell. The filepath of the maps is not needed, the program will read the files from the 'maps' directory inside the project. You can add your own maps to this directory to play them.

To run the map generator, type "./map_gen" into the shell. This will create 'random.ber' in the maps directory. This map can then be used and played in so_long. The map will always be valid. If the program generates and invalid map, it can recognise this and will generate a new one until a valid one is outputted. 

> [!CAUTION]
> Running the map generator subsequent times will replace the 'random.ber' file. To keep generated maps they must be renamed.

> [!NOTE]
> This is intended as a guide only. Writing and understanding your own code is better than copying code.