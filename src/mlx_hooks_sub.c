/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:30:21 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/23 09:54:59 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_canvas(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx, canvas->img->img);
	mlx_destroy_window(canvas->mlx, canvas->win);
	mlx_destroy_display(canvas->mlx);
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
	else if (keycode == KEY_UP_ARROW)
	{
		canvas->max.im += delta_im;
		canvas->min.im += delta_im;
	}
	else if (keycode == KEY_RIGHT_ARROW)
	{
		canvas->max.re += delta_re;
		canvas->min.re += delta_re;
	}
	else if (keycode == KEY_DOWN_ARROW)
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

	delta_left = (cursor.re - canvas->min.re) * ZOOM_RATIO;
	delta_top = (canvas->max.im - cursor.im) * ZOOM_RATIO;
	delta_right = (canvas->max.re - cursor.re) * ZOOM_RATIO;
	delta_bottom = (cursor.im - canvas->min.im) * ZOOM_RATIO;
	if (button == KEY_SCROLL_UP)
	{
		direction = 1;
		canvas->fractal->max_iter += 2;
	}
	else if (button == KEY_SCROLL_DOWN)
	{
		direction = -1;
		if (20 < canvas->fractal->max_iter)
			canvas->fractal->max_iter -= 2;
	}
	canvas->max.re -= delta_right * direction;
	canvas->max.im -= delta_top * direction;
	canvas->min.re += delta_left * direction;
	canvas->min.im += delta_bottom * direction;
}

void	update_fractal_c(t_canvas *canvas)
{
	int	w;
	int	h;

	mlx_mouse_get_pos(canvas->mlx, canvas->win, &w, &h);
	canvas->fractal->c.im = w / WIDTH;
	canvas->fractal->c.re = h / HEIGHT;
}
