/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:22:44 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/12 00:54:26 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_img(t_canvas *canvas);
static void	init_coodinate(t_canvas *canvas);

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
	if (fractal_type_char == '0')
		canvas->fractal_type_num = JULIA;
	else if (fractal_type_char == '1')
		canvas->fractal_type_num = MANDELBROT;
}

static void	init_coodinate(t_canvas *canvas)
{
	canvas->max_point.x = DEFAULT_X_MAX;
	canvas->min_point.x = DEFAULT_X_MIN;
	canvas->max_point.y = DEFAULT_Y_MAX;
	canvas->min_point.y = DEFAULT_Y_MIN;
	canvas->origin.x = 0.0;
	canvas->origin.y = 0.0;
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
