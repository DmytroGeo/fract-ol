# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 19:28:41 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/02/24 20:19:16 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a
FLAGS = -Wall -Wextra -Werror
CC = cc
SOURCES = fractol.c
OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(MINILIBX)
		$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MINILIBX)

clean:
		rm -f $(OBJECTS)
		$(MAKE) -C libft clean 

fclean: clean
		rm -f $(NAME)
		$(MAKE) -c libft fclean

re: fclean all

.PHONY: all re fclean clean