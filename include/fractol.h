/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:44:02 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/09 19:23:27 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
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

/* Utils */
void	init_canvas(t_canvas *canvas);
bool	is_mandelbrot(t_comp comp);
t_comp	init_comp(double re, double im);

/* Complex Calculator */
t_comp	comp_mul(t_comp c1, t_comp c2);
t_comp	comp_add(t_comp c1, t_comp c2);
double	comp_dist(t_comp c);

#endif