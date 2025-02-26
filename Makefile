# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 19:28:41 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/02/26 11:00:15 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = libft/libft.a
# MINILIBX = minilibx-linux/libmlx.a
FLAGS = -Wall -Wextra -Werror
CC = cc
SOURCES = fractol.c
OBJ = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -I mlx_linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
		rm -f $(OBJ)
		$(MAKE) -C libft clean 

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C libft fclean

re: fclean all

.PHONY: all re fclean clean