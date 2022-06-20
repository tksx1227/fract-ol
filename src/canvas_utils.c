/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:22:44 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/19 23:34:19 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_img(t_canvas *canvas);
static void	init_coodinate(t_canvas *canvas);
static void	init_fractal(t_canvas *canvas, char type_char);

void	init_canvas(t_canvas *canvas, char fractal_type_char)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit(1);
	canvas->win = mlx_new_window(canvas->mlx, WIDTH, HEIGHT, "fract-ol");
	if (canvas->win == NULL)
		exit(1);
	init_img(canvas);
	init_coodinate(canvas);
	init_fractal(canvas, fractal_type_char);
}

static void	init_img(t_canvas *canvas)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (img == NULL)
		exit(1);
	img->img = mlx_new_image(canvas->mlx, WIDTH, HEIGHT);
	if (img->img == NULL)
		exit(1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (img->addr == NULL)
		exit(1);
	canvas->img = img;
}

static void	init_coodinate(t_canvas *canvas)
{
	canvas->max.re = DEFAULT_MAX_RE;
	canvas->min.re = DEFAULT_MIN_RE;
	canvas->max.im = DEFAULT_MAX_IM;
	canvas->min.im = DEFAULT_MIN_IM;
}

static void	init_fractal(t_canvas *canvas, char type_char)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (fractal == NULL)
		exit(1);
	fractal->max_iter = DEFAULT_MAX_ITER;
	fractal->z = init_comp(0.0, 0.0);
	fractal->c = init_comp(0.0, 0.0);
	if (type_char == '0')
		fractal->type = JULIA;
	else if (type_char == '1')
		fractal->type = MANDELBROT;
	else
		fractal->type = UNKNOWN;
	canvas->fractal = fractal;
}
