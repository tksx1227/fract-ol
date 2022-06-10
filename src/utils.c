/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:03:39 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/10 09:47:37 by ttomori          ###   ########.fr       */
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


int	create_trgb(unsigned char t, unsigned char r,
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
