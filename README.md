# A raycasting "3D" representation.

This project was made in C language so it should be compiled before running.

To compile and run:

`make`

`./cub3D [map_path]`

### The map rules:

1: block

0: floor

N, S, E, W: Player position and direction at the start of the program.

Each block has 4 sides and there's a picture for each side which are changeable through the map file.

The map edges should be all blocks to prevent any type of errors.
Make sure that the images are 64x64 pixels and are in .xpm file type (convert from other image types using any tool).

### Note: Not stable on linux.
