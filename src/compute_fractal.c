/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:31:06 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 20:37:48 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	compute_mandelbrot(t_fractol *fctl, int x, int y)
{
	double	zx;
	double	zy;
	t_point	point;
	int		iter;
	double	tmp;

	zy = 0;
	zx = 0;
	point.x = (x - WIDTH / 2.0) / (0.5 * fctl->zoom * WIDTH) + fctl->os_x;
	point.y = (y - HEIGHT / 2.0) / (0.5 * fctl->zoom * HEIGHT) + fctl->os_y;
	iter = 0;
	while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + point.x;
		zy = 2.0 * zx * zy + point.y;
		zx = tmp;
		iter++;
	}
	my_mlx_pixel_put(&fctl->img, x, y, get_color(iter, MAX_ITER));
}

void	compute_julia(t_fractol *fractol, int x, int y)
{
	double	zx;
	double	zy;
	double	tmp;
	int		iter;

	iter = 0;
	zx = (x - WIDTH / 2.0) / (0.5 * fractol->zoom * WIDTH) + fractol->os_x;
	zy = (y - HEIGHT / 2.0) / (0.5 * fractol->zoom * HEIGHT) + fractol->os_y;
	while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + fractol->julia_cx;
		zy = 2.0 * zx * zy + fractol->julia_cy;
		zx = tmp;
		iter++;
	}
	my_mlx_pixel_put(&fractol->img, x, y, get_color(iter, MAX_ITER));
}
