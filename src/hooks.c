/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:55:51 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 17:12:43 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int key_hooks(int keycode, t_fractol *fractol)
{
    if (keycode == XK_Escape)
        close_window(fractol);
    else if (keycode == XK_Left)
        fractol->offset_x -= 0.1 / fractol->zoom;
    else if (keycode == XK_Right)
        fractol->offset_x += 0.1 / fractol->zoom;
    else if (keycode == XK_Up)
        fractol->offset_y -= 0.1 / fractol->zoom;
    else if (keycode == XK_Down)
        fractol->offset_y += 0.1 / fractol->zoom;
    render(fractol);
    return (0);
}

int mouse_hooks(int button, int x, int y, t_fractol *fractol)
{
    (void)x;
    (void)y;

    if (button == SCROLL_UP)
        fractol->zoom *= 1.1;
    else if (button == SCROLL_DOWN)
        fractol->zoom /= 1.1;
    render(fractol);
    return (0);
}
