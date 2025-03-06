/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 08:44:51 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 20:39:20 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (!init_fractol(argc, argv, &fractol))
		return (1);
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "fract-ol");
	fractol.img.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	fractol.img.addr = mlx_get_data_addr(fractol.img.img, &fractol.img.bpp, \
										&fractol.img.line_length, \
										&fractol.img.endian);
	render(&fractol);
	mlx_hook(fractol.win, 2, 1L << 0, key_hooks, &fractol);
	mlx_mouse_hook(fractol.win, mouse_hooks, &fractol);
	mlx_hook(fractol.win, 17, 0, close_window, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
