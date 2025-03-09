/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:53:20 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 21:13:02 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define MANDELBROT 1
# define JULIA 2

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_point
{
	double		x;
	double		y;
}	t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		type;
	double	zoom;
	double	os_x;
	double	os_y;
	double	julia_cx;
	double	julia_cy;
}	t_fractol;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		close_window(t_fractol *fractol);
int		key_hooks(int keycode, t_fractol *fractol);
int		mouse_hooks(int button, int x, int y, t_fractol *fractol);
int		init_fractol(int argc, char **argv, t_fractol *fractol);
int		get_color(int iteration, int max_iter);
void	render(t_fractol *fractol);
void	compute_mandelbrot(t_fractol *fractol, int x, int y);
void	compute_julia(t_fractol *fractol, int x, int y);

#endif
