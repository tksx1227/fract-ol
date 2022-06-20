/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:04:02 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/20 23:57:22 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	rgb2hex(unsigned char r, unsigned char g, unsigned char b)
{
	uint32_t	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

uint32_t	get_fractal_color(t_fractal *fractal)
{
	int		i;
	t_comp	z;
	t_comp	c;

	i = 0;
	z = fractal->z;
	c = fractal->c;
	while (i < fractal->max_iter)
	{
		if (comp_dist(z) > 2.0)
			return (rgb2hex(\
				(int)(pow(i, 2) / fractal->max_iter) % 235 + 20, \
				(int)powf(255 * i / fractal->max_iter, 1.2) % 235 + 20, \
				(int)powf(255 * i / fractal->max_iter, 1.3) % 235 + 20 \
			));
		if (fractal->type == BURNING_SHIP)
			z = init_comp(abs_double(z.re), abs_double(z.im));
		z = comp_add(comp_mul(z, z), c);
		i++;
	}
	return (rgb2hex(0, 0, 0));
}
