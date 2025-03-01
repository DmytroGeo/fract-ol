/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:31:05 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/27 11:59:40 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	main(void)
// {
// 	void	*mlx;
//     void    *mlx_win;

// 	mlx = mlx_init();    
//     mlx_win = mlx_new_window(mlx, 1280, 720, "Hello World");
//     mlx_loop(mlx);
// }

// As the pixels are basically ints, these usually are 4 bytes,
// however, this can differ if we are dealing with a small endian 
// (which means we most likely are on a remote display and only have 8 bit colors).

// typedef struct s_data {
//     void    *img;
//     char    *addr;
//     int     bits_per_pixel;
//     int     line_length;
//     int     endian;
// } t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Note that this will cause an issue.
// Because an image is represented in real time in a window, changing the same image will cause a bunch of screen-tearing when writing to it. 
// You should therefore create two or more images to hold your frames temporarily.
// You can then write to a temporary image, so that you don’t have to write to the currently presented image.

// int main(void)
// {
// 	void	*mlx;
// 	t_data	img;

// 	mlx = mlx_init();
// 	img.img = mlx_new_image(mlx, 1280, 720);
// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// }

// Now that we can finally create our image, we should also push it to the window, so that we can actually see it.
// This is pretty straight forward, let’s take a look at how we can write a red pixel at (5,5) and put it to our window:



// Shapes:

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int n = 1;
// 	int m = 100;
// 	// int k = 0;
// 	// int i = 0;
// 	// int m = 8;
// 	// int w = 40;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1280, 720);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	// while (n < 20)
// 	// {
// 	// 	while (k < m * ((3 * n) - 2))
// 	// 	{
// 	// 		i = 0;			
// 	// 		while (i < w)
// 	// 		{
// 	// 			my_mlx_pixel_put(&img, i, k, 0x000000FF);
// 	// 			i++;				
// 	// 		}

// 	// 		k++;			
// 	// 	}
// 	// 	while (k < m * (3 * n - 1))
// 	// 	{
// 	// 		i = 0;
// 	// 		while (i < w)
// 	// 		{
// 	// 			my_mlx_pixel_put(&img, i, k, 0x0000FF00);
// 	// 			i++;				
// 	// 		}
// 	// 		k++;			
// 	// 	}
// 	// 	while (k < m * (3 * n))
// 	// 	{
// 	// 		i = 0;
// 	// 		while (i < w)
// 	// 		{
// 	// 			my_mlx_pixel_put(&img, i, k, 0x00FF0000);
// 	// 			i++;				
// 	// 		}
// 	// 		k++;			
// 	// 	}
// 	// 	n++;	
// 	// }
// 	while (m > 0)
// 	{
// 		n = 0;
// 		while (n < m)
// 		{
// 			my_mlx_pixel_put(&img, n, m, 0x00FF0000);
// 			n++;
// 		}
// 		m--;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// n = 0;
// 	// while (n < 360)
// 	// {
// 	// 	my_mlx_pixel_put(&img, n + 100, n + 100, 0x00FF0000);
// 	// 	n++;	
// 	// }
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, 50, 50);
// 	mlx_loop(mlx);
// }


// Colours:

int create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int get_t(int color)
{
	return(color >> 24 & 255);
}

int get_r(int color)
{
	return(color >> 16 & 255);	
}

int get_g(int color)
{
	return(color >> 8 & 255);	
}

int get_b(int color)
{
	return(color & 255);	
}

int add_shade(double d, int color)
{
	int t = get_t(color);
	int r = get_r(color);
	int g = get_g(color);
	int b = get_b(color);
	
	r = (int)(r * d);
	g = (int)(g * d);
	b = (int)(b * d);
	return(create_trgb(t, r, g, b));
}

int invert_colour(int color)
{
	int t = get_t(color);
	int r = get_r(color);
	int g = get_g(color);
	int b = get_b(color);
	
	t = 255 - t;
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;
	return(create_trgb(t, r, g, b));
}

// int main(void)
// {
// 	int t = 0;
// 	int r = 250;
// 	int g = 200;
// 	int b = 150;
// 	int trgb = create_trgb(t, r, g, b);
// 	int shaded = add_shade(0.5, create_trgb(t, r, g, b));
// 	ft_printf("Input components: t = %d, r = %d, g = %d, b = %d \n", t, r, g, b);
// 	ft_printf("colour code: %d \n", trgb);
// 	ft_printf("What I'm aiming for: %d, shaded colour code: %d \n", (trgb / 2), shaded);
// 	return (0);
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	pic;
// 	int m = 100;
// 	int n = 0;
// 	int x = 200;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "fractol");
// 	pic.img = mlx_new_image(mlx, 1920, 1080);
// 	pic.addr = mlx_get_data_addr(pic.img, &pic.bits_per_pixel, &pic.line_length, &pic.endian);
// 	int color = create_trgb(0, x, x + 50, x - 50);
// 	// int shaded = add_shade(0.5, color);
// 	// int extra_shaded = add_shade(0.25, color);
// 	int inverted = invert_colour(color);

// 	while (m > 0)
// 	{
// 		n = 0;
// 		while (n < m)
// 		{
// 			my_mlx_pixel_put(&pic, n, m, color);
// 			my_mlx_pixel_put(&pic, n + 100, m + 100, inverted);
// 			// my_mlx_pixel_put(&pic, n + 200, m + 200, extra_shaded);	
// 			n++;
// 		}
// 		m--;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, pic.img, 50, 50);
// 	mlx_loop(mlx);	
// }

// int closek(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;
	
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "fractol");
// 	mlx_hook(vars.win, 2, 1L<<0, closek, &vars);
// 	// in mlx_hook: 
// 	// the second argument is event; in this case a key press.
// 	// the third argument is mask; in this case KeyPressMask.
// 	mlx_loop(vars.mlx); 
// }

int	close_key(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	close_mouse(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close_key, &vars);
// 	mlx_loop(vars.mlx);
// }

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 3, 1L<<1, close_key, &vars);
	mlx_loop(vars.mlx);
}