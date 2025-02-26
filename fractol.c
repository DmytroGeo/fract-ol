/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:31:05 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/02/26 16:47:01 by dgeorgiy         ###   ########.fr       */
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

int create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8| b);
}

int get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_g(int trgb)
{
	return (trgb & 0xFF);
}

// 1 byte = 8 bits. 
// Each of t, r, g, b goes from 0 to 255 so it requires 8 bits = 1 byte to store.
// thus each pixel takes one integer to store.
// char = 1 byte so we can fir a pixel into 4 unsigned chars.

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return(*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return(((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return(((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return(((unsigned char *)&trgb)[1]);
}

unsigned char	get_g(int trgb)
{
	return(((unsigned char *)&trgb)[0]);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int n = 1;
	int m = 100;
	// int k = 0;
	// int i = 0;
	// int m = 8;
	// int w = 40;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// while (n < 20)
	// {
	// 	while (k < m * ((3 * n) - 2))
	// 	{
	// 		i = 0;			
	// 		while (i < w)
	// 		{
	// 			my_mlx_pixel_put(&img, i, k, 0x000000FF);
	// 			i++;				
	// 		}

	// 		k++;			
	// 	}
	// 	while (k < m * (3 * n - 1))
	// 	{
	// 		i = 0;
	// 		while (i < w)
	// 		{
	// 			my_mlx_pixel_put(&img, i, k, 0x0000FF00);
	// 			i++;				
	// 		}
	// 		k++;			
	// 	}
	// 	while (k < m * (3 * n))
	// 	{
	// 		i = 0;
	// 		while (i < w)
	// 		{
	// 			my_mlx_pixel_put(&img, i, k, 0x00FF0000);
	// 			i++;				
	// 		}
	// 		k++;			
	// 	}
	// 	n++;	
	// }
	while (m > 0)
	{
		n = 0;
		while (n < m)
		{
			my_mlx_pixel_put(&img, n, m, 0x00FF0000);
			n++;
		}
		m--;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// n = 0;
	// while (n < 360)
	// {
	// 	my_mlx_pixel_put(&img, n + 100, n + 100, 0x00FF0000);
	// 	n++;	
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 50, 50);
	mlx_loop(mlx);
}