/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:30:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/12 14:30:21 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_origin(t_canvas *canvas, int keycode)
{
	double	delta_x;
	double	delta_y;

	delta_x = (canvas->max_point.x - canvas->min_point.x) * MOVE_RATIO;
	delta_y = (canvas->max_point.y - canvas->min_point.y) * MOVE_RATIO;
	if (keycode == KEY_LEFT_ARROW)
		canvas->origin.x += delta_x;
	else if (keycode == KEY_TOP_ARROW)
		canvas->origin.y += delta_y;
	else if (keycode == KEY_RIGHT_ARROW)
		canvas->origin.x -= delta_x;
	else if (keycode == KEY_BOTTOM_ARROW)
		canvas->origin.y -= delta_y;
}
