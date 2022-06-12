/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:02 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/10 09:43:42 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include "mlx.h"

# define WIDTH 720
# define HEIGHT 480
# define DEFAULT_X_MAX 2
# define DEFAULT_X_MIN -2
# define DEFAULT_Y_MAX 2
# define DEFAULT_Y_MIN -2
# define JULIA 0
# define MANDELBROT 1

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coodinate
{
	double	x;
	double	y;
}	t_coodinate;

typedef struct s_canvas
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		fractal_type_num;
	t_coodinate	origin;
	t_coodinate	max_point;
	t_coodinate	min_point;
}	t_canvas;

typedef struct s_comp
{
	double	re;
	double	im;
}	t_comp;

enum
{
	KEY_ESC = 65307,
};

/* Event Hooks */
int		key_hook(int keycode, t_canvas *canvas);
int		exit_canvas(t_canvas *canvas);

/* Drawer */
void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color);
void	mlx_draw(t_canvas *canvas);

/* Utils */
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr_fd(char const *s, int fd);
void	print_usage(void);
bool	is_mandelbrot(t_comp comp);
uint32_t	rgb2hex(unsigned char r, unsigned char g, unsigned char b);

/* MinilibX Utils*/
void	init_canvas(t_canvas *canvas, char fractal_type_char);

/* Complex Utils */
t_comp	init_comp(double re, double im);
t_comp	comp_mul(t_comp c1, t_comp c2);
t_comp	comp_add(t_comp c1, t_comp c2);
double	comp_dist(t_comp c);

#endif
