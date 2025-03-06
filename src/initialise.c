/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:58:48 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 14:59:49 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int init_fractol(int argc, char **argv, t_fractol *fractol)
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