/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeorgiy <dgeorgiy@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:03:25 by dgeorgiy          #+#    #+#             */
/*   Updated: 2025/03/06 19:37:26 by dgeorgiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putchex_fd(unsigned int n, int fd, int *count);
void	ft_puthex_fd(unsigned int n, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putptr_fd(void *ptr, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putuns_fd(unsigned int n, int fd, int *count);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_array_free(char **array);
int		ft_array_len(char **array);
double	ft_atof(const char *str);

#endif