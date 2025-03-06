/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:36:37 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 19:37:07 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double handle_fractional(const char *str)
{
    double fraction;
    double divisor;

    fraction = 0.0;
    divisor = 10.0;
    while (*str >= '0' && *str <= '9')
    {
        fraction += (*str - '0') / divisor;
        divisor *= 10.0;
        str++;
    }
    return (fraction);
}

double ft_atof(const char *str)
{
    double result;
    int sign;

    result = 0.0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10.0 + (*str - '0');
        str++;
    }
    if (*str == '.')
        result += handle_fractional(str + 1);
    return (result * sign);
}