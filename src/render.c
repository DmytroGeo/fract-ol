/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:00:31 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 15:00:56 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void render(t_fractol *fractol)
{
    int x;
	int y;
	int iter;
    double zx, zy, cx, cy, tmp;
    
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            cx = (x - WIDTH / 2.0) / (0.5 * fractol->zoom * WIDTH) + fractol->offset_x;
            cy = (y - HEIGHT / 2.0) / (0.5 * fractol->zoom * HEIGHT) + fractol->offset_y;
            if (fractol->type == MANDELBROT)
            {
                zx = 0;
                zy = 0;
            }
            else
            {
                zx = cx;
                zy = cy;
            }
            iter = 0;
            while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
            {
                tmp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = tmp;
                iter++;
            }
            my_mlx_pixel_put(&fractol->img, x, y, get_color(iter, MAX_ITER));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}