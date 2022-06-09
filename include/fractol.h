#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

# define WIDTH 720
# define HEIGHT 480

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_canvas
{
	void	*mlx;
	void	*win;
	t_img	*img;
}	t_canvas;

enum
{
	KEY_ESC = 65307,
};

/* Event Hooks */
int		key_hook(int keycode, t_canvas *canvas);
void	destroy_canvas(t_canvas *canvas);

#endif