/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:47:06 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/12 00:38:36 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp	init_comp(double re, double im)
{
	t_comp	comp;

	comp.re = re;
	comp.im = im;
	return (comp);
}

t_comp	comp_mul(t_comp c1, t_comp c2)
{
	t_comp	comp_res;

	comp_res.re = c1.re * c2.re - c1.im * c2.im;
	comp_res.im = c1.re * c2.im + c1.im * c2.re;
	return (comp_res);
}

t_comp	comp_add(t_comp c1, t_comp c2)
{
	t_comp	comp_res;

	comp_res.re = c1.re + c2.re;
	comp_res.im = c1.im + c2.im;
	return (comp_res);
}

double	comp_dist(t_comp c)
{
	double	dist;

	dist = sqrt(pow(c.re, 2) + pow(c.im, 2));
	return (dist);
}
