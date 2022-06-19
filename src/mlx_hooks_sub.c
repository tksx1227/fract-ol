/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:30:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/19 23:41:10 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_canvas(t_canvas *canvas)
{
	mlx_destroy_window(canvas->mlx, canvas->win);
	exit(0);
}

void	move_canvas(t_canvas *canvas, int keycode)
{
	double	delta_re;
	double	delta_im;

	delta_re = (canvas->max.re - canvas->min.re) * MOVE_RATIO;
	delta_im = (canvas->max.im - canvas->min.im) * MOVE_RATIO;
	if (keycode == KEY_LEFT_ARROW)
	{
		canvas->max.re -= delta_re;
		canvas->min.re -= delta_re;
	}
	else if (keycode == KEY_TOP_ARROW)
	{
		canvas->max.im += delta_im;
		canvas->min.im += delta_im;
	}
	else if (keycode == KEY_RIGHT_ARROW)
	{
		canvas->max.re += delta_re;
		canvas->min.re += delta_re;
	}
	else if (keycode == KEY_BOTTOM_ARROW)
	{
		canvas->max.im -= delta_im;
		canvas->min.im -= delta_im;
	}
}

void	zoom_canvas(t_canvas *canvas, int button, t_comp cursor)
{
	int		direction;
	double	delta_left;
	double	delta_top;
	double	delta_right;
	double	delta_bottom;

	delta_left = ZOOM_RATIO * (cursor.re - canvas->min.re);
	delta_top = ZOOM_RATIO * (canvas->max.im - cursor.im);
	delta_right = ZOOM_RATIO * (canvas->max.re - cursor.re);
	delta_bottom = ZOOM_RATIO * (cursor.im - canvas->min.im);
	if (button == KEY_SCROLL_UP)
	{
		direction = 1;
		canvas->max_iter += 2;
	}
	else if (button == KEY_SCROLL_DOWN)
	{
		direction = -1;
		if (20 < canvas->max_iter)
			canvas->max_iter -= 2;
	}
	canvas->max.re -= delta_right * direction;
	canvas->max.im -= delta_top * direction;
	canvas->min.re += delta_left * direction;
	canvas->min.im += delta_bottom * direction;
}
