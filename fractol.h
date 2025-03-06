/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fract-ol_dev                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:00:00 by fract-ol_dev      #+#    #+#             */
/*   Updated: 2025/03/06 00:00:00 by fract-ol_dev     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "./libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define MANDELBROT 1
# define JULIA 2

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_fractol
{
    void    *mlx;
    void    *win;
    t_img   img;
    int     type;
    double  zoom;
    double  offset_x;
    double  offset_y;
}   t_fractol;

void    put_pixel(t_img *img, int x, int y, int color);
int     close_window(t_fractol *fractol);
int     key_hooks(int keycode, t_fractol *fractol);
int     mouse_hooks(int button, int x, int y, t_fractol *fractol);
void    setup_hooks(t_fractol *fractol);
int     parse_args(int argc, char **argv, t_fractol *fractol);
int     get_color(int iteration, int max_iter);
void    render(t_fractol *fractol);

#endif
