/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:31:06 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 19:31:55 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void compute_mandelbrot(t_fractol *fractol, int x, int y)
{
    double zx = 0;
    double zy = 0;
    double cx = (x - WIDTH / 2.0) / (0.5 * fractol->zoom * WIDTH) + fractol->offset_x;
    double cy = (y - HEIGHT / 2.0) / (0.5 * fractol->zoom * HEIGHT) + fractol->offset_y;
    double tmp;
    int iter = 0;

    while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2.0 * zx * zy + cy;
        zx = tmp;
        iter++;
    }
    my_mlx_pixel_put(&fractol->img, x, y, get_color(iter, MAX_ITER));
}

void compute_julia(t_fractol *fractol, int x, int y)
{
    double zx = (x - WIDTH / 2.0) / (0.5 * fractol->zoom * WIDTH) + fractol->offset_x;
    double zy = (y - HEIGHT / 2.0) / (0.5 * fractol->zoom * HEIGHT) + fractol->offset_y;
    double tmp;
    int iter = 0;

    while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
    {
        tmp = zx * zx - zy * zy + fractol->julia_cx;
        zy = 2.0 * zx * zy + fractol->julia_cy;
        zx = tmp;
        iter++;
    }
    my_mlx_pixel_put(&fractol->img, x, y, get_color(iter, MAX_ITER));
}