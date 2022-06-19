/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:02 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/20 00:39:55 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <X11/X.h>
# include "mlx.h"

# define WIDTH 720
# define HEIGHT 720
# define DEFAULT_MAX_ITER 80
# define DEFAULT_MAX_RE 2.0
# define DEFAULT_MIN_RE -2.0
# define DEFAULT_MAX_IM 2.0
# define DEFAULT_MIN_IM -2.0
# define MOVE_RATIO 0.05
# define ZOOM_RATIO 0.15

typedef enum e_fractal
{
	UNKNOWN = -1,
	JULIA = 0,
	MANDELBROT = 1,
}	t_fractal;

typedef enum e_keys
{
	KEY_SCROLL_UP = 4,
	KEY_SCROLL_DOWN = 5,
	KEY_ESC = 65307,
	KEY_LEFT_ARROW = 65361,
	KEY_TOP_ARROW = 65362,
	KEY_RIGHT_ARROW = 65363,
	KEY_BOTTOM_ARROW = 65364,
}	t_keys;

typedef struct s_comp
{
	double	re;
	double	im;
}	t_comp;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_canvas
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_fractal	fractal;
	int			max_iter;
	t_comp		max;
	t_comp		min;
}	t_canvas;

/* Event Hooks */
int		key_hook(int keycode, t_canvas *canvas);
int		mouse_hook(int keycode, int w, int h, t_canvas *canvas);
int		loop_hook(t_canvas *canvas);
int		exit_canvas(t_canvas *canvas);
void	zoom_canvas(t_canvas *canvas, int button, t_comp cursor);
void	move_canvas(t_canvas *canvas, int keycode);

/* Drawer */
void	my_mlx_pixel_put(t_canvas *canvas, int w, int h, int color);

/* Utils */
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char const *s, int fd);
void	print_usage(void);
uint32_t	rgb2hex(unsigned char r, unsigned char g, unsigned char b);

/* MinilibX Utils*/
void	init_canvas(t_canvas *canvas, char fractal_type_char);

/* Complex Utils */
t_comp	init_comp(double re, double im);
t_comp	comp_mul(t_comp c1, t_comp c2);
t_comp	comp_add(t_comp c1, t_comp c2);
double	comp_dist(t_comp c);

#endif
