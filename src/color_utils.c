/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:04:02 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/20 19:05:12 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		if (comp_dist(fractal->z) > 2.0)
			return (rgb2hex(
					i % 42,
					255 * i / fractal->max_iter,
					(int)powf((i / (double)fractal->max_iter) * 256, 1.5) % 256
				));
		if (fractal->type == BURNING_SHIP)
			z = init_comp(abs_double(z.re), abs_double(z.im));
		z = comp_add(comp_mul(z, z), c);
		i++;
	}
	return (rgb2hex(0, 0, 0));
}
