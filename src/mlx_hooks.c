/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:11:18 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/20 19:06:31 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_canvas *canvas)
{
	if (keycode == KEY_ESC)
		exit_canvas(canvas);
	else if (keycode == KEY_LEFT_ARROW || keycode == KEY_UP_ARROW || \
			keycode == KEY_RIGHT_ARROW || keycode == KEY_DOWN_ARROW)
		move_canvas(canvas, keycode);
	else if (canvas->fractal->type == JULIA && keycode == KEY_SPACE)
		canvas->fractal->is_julia_edit_mode = \
		!canvas->fractal->is_julia_edit_mode;
	return (0);
}

int	mouse_hook(int button, int w, int h, t_canvas *canvas)
{
	t_comp	cursor;

	if (button == KEY_SCROLL_UP || button == KEY_SCROLL_DOWN)
	{
		cursor.re = canvas->min.re + \
			(w * (canvas->max.re - canvas->min.re) / WIDTH);
		cursor.im = canvas->min.im + \
			((HEIGHT - h) * (canvas->max.im - canvas->min.im) / HEIGHT);
		zoom_canvas(canvas, button, cursor);
	}
	return (0);
}

int	loop_hook(t_canvas *canvas)
{
	if (canvas->fractal->type == JULIA)
	{
		if (canvas->fractal->is_julia_edit_mode)
			update_fractal_c(canvas);
		draw_julia(canvas);
	}
	else if (canvas->fractal->type == MANDELBROT)
	{
		draw_mandelbrot(canvas);
	}
	else if (canvas->fractal->type == BURNING_SHIP)
	{
		draw_burningship(canvas);
	}
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->img->img, 0, 0);
	return (0);
}
