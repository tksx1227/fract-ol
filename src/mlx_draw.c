/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:07:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/10 09:45:35 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char	*dst;

	dst = canvas->img->addr + \
		(y * canvas->img->line_length + x * (canvas->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_draw(t_canvas *canvas)
{
	int		x;
	int		y;
	double	a;
	double	b;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			a = 2 * x / (double)WIDTH - 1;
			b = 2 * y / (double)HEIGHT - 1;
			if (is_mandelbrot(init_comp(a, b)))
				my_mlx_pixel_put(canvas, x, y, create_trgb(0, 0, 255, 255));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
}
