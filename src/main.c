/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:03:05 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/12 23:24:04 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_canvas	canvas;

	if (argc != 2 || \
		!(ft_strcmp(argv[1], "0") == 0 || ft_strcmp(argv[1], "1") == 0))
	{
		print_usage();
		exit(1);
	}
	init_canvas(&canvas, argv[1][0]);
	mlx_hook(canvas.win, DestroyNotify, StructureNotifyMask, \
			&exit_canvas, &canvas);
	mlx_key_hook(canvas.win, &key_hook, &canvas);
	mlx_mouse_hook(canvas.win, &mouse_hook, &canvas);
	mlx_loop_hook(canvas.mlx, &loop_hook, &canvas);
	mlx_loop(canvas.mlx);
	return (0);
}
