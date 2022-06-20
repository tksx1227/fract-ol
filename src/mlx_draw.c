/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:07:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/21 00:33:06 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_mandelbrot_burningship_common(t_canvas *canvas);

void	my_mlx_pixel_put(t_canvas *canvas, int w, int h, int color)
{
	char	*dst;

	dst = canvas->img->addr + \
		(h * canvas->img->line_length + w * (canvas->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_julia(t_canvas *canvas)
{
	int			w;
	int			h;
	double		re;
	double		im;
	uint32_t	color;

	w = 0;
	while (w < WIDTH)
	{
		h = 0;
		while (h < HEIGHT)
		{
			re = canvas->min.re + \
				(w * (canvas->max.re - canvas->min.re) / WIDTH);
			im = canvas->min.im + \
				((HEIGHT - h) * (canvas->max.im - canvas->min.im) / HEIGHT);
			canvas->fractal->z = init_comp(re, im);
			color = get_fractal_color(canvas->fractal);
			my_mlx_pixel_put(canvas, w, h, color);
			h++;
		}
		w++;
	}
}

void	draw_mandelbrot(t_canvas *canvas)
{
	draw_mandelbrot_burningship_common(canvas);
}

void	draw_burningship(t_canvas *canvas)
{
	draw_mandelbrot_burningship_common(canvas);
}

static void	draw_mandelbrot_burningship_common(t_canvas *canvas)
{
	int			w;
	int			h;
	double		re;
	double		im;
	uint32_t	color;

	w = 0;
	while (w < WIDTH)
	{
		h = 0;
		while (h < HEIGHT)
		{
			re = canvas->min.re + \
				(w * (canvas->max.re - canvas->min.re) / WIDTH);
			im = canvas->min.im + \
				((HEIGHT - h) * (canvas->max.im - canvas->min.im) / HEIGHT);
			canvas->fractal->c = init_comp(re, im);
			canvas->fractal->z = init_comp(0.0, 0.0);
			color = get_fractal_color(canvas->fractal);
			my_mlx_pixel_put(canvas, w, h, color);
			h++;
		}
		w++;
	}
}
