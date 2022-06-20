/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:02 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/20 21:17:58 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>
# include <X11/X.h>
# include "mlx.h"

# define WIDTH 720.0
# define HEIGHT 720.0
# define DEFAULT_MAX_ITER 80
# define DEFAULT_MAX_RE 2.0
# define DEFAULT_MIN_RE -2.0
# define DEFAULT_MAX_IM 2.0
# define DEFAULT_MIN_IM -2.0
# define DEFAULT_JULIA_C_RE -0.7
# define DEFAULT_JULIA_C_IM -0.3
# define MOVE_RATIO 0.05
# define ZOOM_RATIO 0.15

typedef enum e_fractal_type
{
	UNKNOWN = -1,
	JULIA = 0,
	MANDELBROT = 1,
	BURNING_SHIP = 2,
}	t_fractal_type;

typedef enum e_keys
{
	KEY_SCROLL_UP = 4,
	KEY_SCROLL_DOWN = 5,
	KEY_SPACE = 32,
	KEY_ESC = 65307,
	KEY_LEFT_ARROW = 65361,
	KEY_UP_ARROW = 65362,
	KEY_RIGHT_ARROW = 65363,
	KEY_DOWN_ARROW = 65364,
}	t_keys;

typedef struct s_comp
{
	double	re;
	double	im;
}	t_comp;

typedef struct s_fractal
{
	int				max_iter;
	bool			is_pressed_space_key;
	t_comp			z;
	t_comp			c;
	t_fractal_type	type;
}	t_fractal;

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
	t_fractal	*fractal;
	t_comp		max;
	t_comp		min;
}	t_canvas;

/* Event Hooks */
int			key_hook(int keycode, t_canvas *canvas);
int			mouse_hook(int keycode, int w, int h, t_canvas *canvas);
int			loop_hook(t_canvas *canvas);
int			exit_canvas(t_canvas *canvas);
void		zoom_canvas(t_canvas *canvas, int button, t_comp cursor);
void		move_canvas(t_canvas *canvas, int keycode);
void		update_fractal_c(t_canvas *canvas);

/* Drawer */
void		my_mlx_pixel_put(t_canvas *canvas, int w, int h, int color);
void		draw_julia(t_canvas *canvas);
void		draw_mandelbrot(t_canvas *canvas);
void		draw_burningship(t_canvas *canvas);

/* Utils */
int			ft_strcmp(const char *s1, const char *s2);
void		init_canvas(t_canvas *canvas, char fractal_type_char);
void		print_usage(void);
double		abs_double(double n);
uint32_t	rgb2hex(unsigned char r, unsigned char g, unsigned char b);
uint32_t	get_fractal_color(t_fractal *fractal);

/* Complex Utils */
t_comp		init_comp(double re, double im);
t_comp		comp_mul(t_comp c1, t_comp c2);
t_comp		comp_add(t_comp c1, t_comp c2);
double		comp_dist(t_comp c);

#endif
