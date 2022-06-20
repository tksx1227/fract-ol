# fract-ol

A program that creates beautiful graphical fractals.

## Description

This program uses the screen drawing library [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) to draw fractals.

Valid fractals are the following three types of sets.

- Mandelbrot set
- Julia set
- Burning Ship set

## Usage

You can use the make command to clone MiniLibX and generate a binary file.

```shell
$ make
$ ls
Makefile README.md bin/ include/ minilibx/ obj/ src/
```

You can draw by passing the number corresponding to the fractal you want to draw in the command line argument.

```shell
$ ./bin/fractol
Usage: fractol <TYPE NUMBER>
The available type numbers are:
  - 0: Julia
  - 1: Mandelbrot
  - 2: Burning ship
```

The actions that can be executed while drawing are:

- Close the window by pressing the esc key
- Screen movement using the cross key
- Zoom in and out using the mouse wheel
- Update the set according to the coordinates of the cursor by switching the space key (Julia set only)

## Sample

Julia set

![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/59915788/174650873-440c3830-82a5-4067-ae4a-00a74cb83e05.gif)

Mandelbrot set

![ezgif com-gif-maker](https://user-images.githubusercontent.com/59915788/174650836-ae6bf765-4751-461a-ac4f-893a473fa739.gif)

Burning ship set

![ezgif com-gif-maker (2)](https://user-images.githubusercontent.com/59915788/174651474-1e122565-131b-4af9-9bdf-8aeef24801a2.gif)
