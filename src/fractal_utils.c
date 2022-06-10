/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:25:59 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/11 00:25:59 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
