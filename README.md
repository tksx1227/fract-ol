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

Mandelbrot set

Burning ship set
