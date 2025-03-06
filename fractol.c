/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 08:44:51 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 09:15:05 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

// void    put_pixel(t_img *img, int x, int y, int color)
// {
//     char    *dst;

//     if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
//     {
//         dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
//         *(unsigned int*)dst = color;
//     }
// }

int close_window(t_fractol *fractol)
{
    mlx_destroy_image(fractol->mlx, fractol->img.img);
    mlx_destroy_window(fractol->mlx, fractol->win);
    exit(0);
    return (0);
}

int key_hooks(int keycode, t_fractol *fractol)
{
    if (keycode == KEY_ESC)
        close_window(fractol);
    else if (keycode == KEY_LEFT)
        fractol->offset_x -= 0.1 / fractol->zoom;
    else if (keycode == KEY_RIGHT)
        fractol->offset_x += 0.1 / fractol->zoom;
    else if (keycode == KEY_UP)
        fractol->offset_y -= 0.1 / fractol->zoom;
    else if (keycode == KEY_DOWN)
        fractol->offset_y += 0.1 / fractol->zoom;
    render(fractol);
    return (0);
}

int mouse_hooks(int button, int x, int y, t_fractol *fractol)
{
    if (button == SCROLL_UP)
        fractol->zoom *= 1.1;
    else if (button == SCROLL_DOWN)
        fractol->zoom /= 1.1;
    render(fractol);
    return (0);
}

void setup_hooks(t_fractol *fractol)
{
    mlx_key_hook(fractol->win, key_hooks, fractol);
    mlx_mouse_hook(fractol->win, mouse_hooks, fractol);
    mlx_hook(fractol->win, 17, 0, close_window, fractol);
}

int parse_args(int argc, char **argv, t_fractol *fractol)
{
    if (argc != 2 || (ft_strncmp(argv[1], "mandelbrot", 11) && ft_strncmp(argv[1], "julia", 6)))
    {
        ft_printf("Usage: ./fractol mandelbrot | julia\n");
        return (0);
    }
    if (argv[1][0] == 'm')
        fractol->type = MANDELBROT;
    else
        fractol->type = JULIA;
    fractol->zoom = 1.0;
    fractol->offset_x = 0;
    fractol->offset_y = 0;
    return (1);
}

int get_color(int iteration, int max_iter)
{
    double t = (double)iteration / max_iter;
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (r << 16 | g << 8 | b);
}

void render(t_fractol *fractol)
{
    int x, y, iter;
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

int main(int argc, char **argv)
{
    t_fractol    fractol;

    if (!parse_args(argc, argv, &fractol))
        return (1);
    fractol.mlx = mlx_init();
    fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "fract-ol");
    fractol.img.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
    fractol.img.addr = mlx_get_data_addr(fractol.img.img, &fractol.img.bpp,
                                        &fractol.img.line_length, &fractol.img.endian);
    render(&fractol);
    setup_hooks(&fractol);
    mlx_loop(fractol.mlx);
    return (0);
}
