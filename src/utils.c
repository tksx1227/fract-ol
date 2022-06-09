/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:03:39 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/09 19:22:39 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_img(t_canvas *canvas);

t_comp	init_comp(double re, double im)
{
	t_comp	comp;

	comp.re = re;
	comp.im = im;
	return (comp);
}

bool	is_mandelbrot(t_comp comp)
{
	int		i;
	t_comp	z;

	z = init_comp(0.0, 0.0);
	i = 0;
	while (i < 30)
	{
		if (comp_dist(z) > 2.0)
			return (false);
		z = comp_add(comp_mul(z, z), comp);
		i++;
	}
	return (true);
}

int create_trgb(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char[4]){b, g, r, t});
}

void	init_canvas(t_canvas *canvas)
{
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		exit(1);
	canvas->win = mlx_new_window(canvas->mlx, WIDTH, HEIGHT, "fract-ol");
	if (canvas->win == NULL)
		exit(1);
	init_img(canvas);
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