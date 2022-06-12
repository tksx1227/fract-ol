/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:11:18 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/12 23:24:20 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_canvas *canvas)
{
	if (keycode == KEY_ESC)
		exit_canvas(canvas);
	else if (keycode == KEY_LEFT_ARROW || keycode == KEY_TOP_ARROW || \
			keycode == KEY_RIGHT_ARROW || keycode == KEY_BOTTOM_ARROW)
		update_origin(canvas, keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_canvas *canvas)
{
	if (button == KEY_SCROLL_UP || button == KEY_SCROLL_DOWN)
		zoom_canvas(canvas, button);
	return (0);
}

int	loop_hook(t_canvas *canvas)
{
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
	return (0);
}
