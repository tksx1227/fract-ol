/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:07:08 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/19 23:38:44 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_canvas *canvas, int w, int h, int color)
{
	char	*dst;

	dst = canvas->img->addr + \
		(h * canvas->img->line_length + w * (canvas->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
