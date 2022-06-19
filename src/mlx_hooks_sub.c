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
	double	delta_x;
	double	delta_y;

	delta_x = (canvas->max_point.x - canvas->min_point.x) * MOVE_RATIO;
	delta_y = (canvas->max_point.y - canvas->min_point.y) * MOVE_RATIO;
	if (keycode == KEY_LEFT_ARROW)
	{
		canvas->max_point.x -= delta_x;
		canvas->min_point.x -= delta_x;
	}
	else if (keycode == KEY_TOP_ARROW)
	{
		canvas->max_point.y += delta_y;
		canvas->min_point.y += delta_y;
	}
	else if (keycode == KEY_RIGHT_ARROW)
	{
		canvas->max_point.x += delta_x;
		canvas->min_point.x += delta_x;
	}
	else if (keycode == KEY_BOTTOM_ARROW)
	{
		canvas->max_point.y -= delta_y;
		canvas->min_point.y -= delta_y;
	}
}

void	zoom_canvas(t_canvas *canvas, int button)
{
	int		direction;
	double	delta_x;
	double	delta_y;

	delta_x = (canvas->max_point.x - canvas->min_point.x) * ZOOM_RATIO;
	delta_y = (canvas->max_point.y - canvas->min_point.y) * ZOOM_RATIO;
	if (button == KEY_SCROLL_UP)
		direction = 1;
	else if (button == KEY_SCROLL_DOWN)
		direction = -1;
	canvas->max_point.x -= delta_x * direction;
	canvas->max_point.y -= delta_y * direction;
	canvas->min_point.x += delta_x * direction;
	canvas->min_point.y += delta_y * direction;
}
