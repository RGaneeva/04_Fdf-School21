# FDF

School 21 (Ecole42) 'FdF' project. 
Score 100/100. Passed 2021/12/27

In this project I studied the redirections and the pipes. 

This project is about creating a simple wireframe model representation of a 3D landscape 
by linking various points (x, y, z) thanks to line segments (edges).

Program represents given model in isometric projection.
The coordinates of the landscape are stored in a .fdf file passed as a parameter to the program.

What is important - here I used MiniLibX - 42(21) school graphical library.
It was my first graphical library and thanks to it I discovered the
basics of graphics programming, especially how to place points in space and join them.
I have added this library to the repository (for MacOS).
https://qst0.github.io/ft_libgfx/man_mlx.html - man mlx

# USAGE

clone this repository

git clone https://github.com/RGaneeva/04_Fdf-School21.git

then

| command | result |
|:----|:----|
| make | compile fdf project |
| make clean | clean .o files |
| make fclean | clean .o and .a files |

Example of using programm:

> make

> ./fdf ./test_maps/any_map_from_test_maps_folder

