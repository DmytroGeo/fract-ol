/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:58:48 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 19:43:19 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int parse_julia_params(int argc, char **argv, t_fractol *fractol)
{
    if (argc != 4)
    {
        ft_printf("Julia requires two float parameters.\n");
        return (0);
    }
    fractol->julia_cx = ft_atof(argv[2]);
    fractol->julia_cy = ft_atof(argv[3]);
    return (1);
}

int init_fractol(int argc, char **argv, t_fractol *fractol)
{
    if (argc < 2 || (ft_strncmp(argv[1], "mandelbrot", 11) && ft_strncmp(argv[1], "julia", 6)))
    {
        ft_printf("Choose one of mandelbrot or julia\n");
        return (0);
    }
    if (argv[1][0] == 'm')
        fractol->type = MANDELBROT;
    else
    {
        fractol->type = JULIA;
        if (!parse_julia_params(argc, argv, fractol))
            return (0);
    }
    fractol->zoom = 1.0;
    fractol->offset_x = 0;
    fractol->offset_y = 0;
    return (1);
}
