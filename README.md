# fract-ol

A program that creates beautiful graphical fractals.

## Description

This program uses the screen drawing library MiniLibX to draw fractals.

Valid fractals are the following three types of sets.

- Mandelbrot set
- Julia set
- Burning Ship set

## Usage

Clone the submodule at the same time with the following command.

```shell
$ git clone --recursive https://github.com/tksx1227/fract-ol.git
```

You can use the make command to generate object files and a binary file.

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

### Julia set

![ezgif com-gif-maker (4)](https://user-images.githubusercontent.com/59915788/174652551-634ad1bd-1831-4590-92d6-853860e8acb7.gif)

### Mandelbrot set

![ezgif com-gif-maker (3)](https://user-images.githubusercontent.com/59915788/174652361-1c030d21-f4ee-4203-bb6f-34bf4c141bb0.gif)

### Burning ship set

![ezgif com-gif-maker (2)](https://user-images.githubusercontent.com/59915788/174651474-1e122565-131b-4af9-9bdf-8aeef24801a2.gif)

## Links

- MiniLibX's repository: [MiniLibX](https://github.com/42Paris/minilibx-linux.git)

- MiniLibX's document: [MiniLibX - 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx)
