# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 19:28:41 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/03/06 17:01:34 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
# MLX = mlx/
CC = cc
SOURCES = src/hooks.c \
				src/colour.c \
				src/close_and_exit.c \
				src/initialise.c \
				src/pixel_put.c \
				src/render.c \
				fractol.c

OBJ = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -I mlx_linux -O3 -c $< -o $@

all: libft $(NAME)

# I actually made a mistake in the above line. It used to be: 
# all: libft 
# 		$(NAME)
# Here's what I learned about why this is wrong: 
# This line $(NAME) is the problem. 
# In Makefiles, when you put a target name there without a command,
# Make treats it as if you're trying to run an executable called fractol, which doesn't exist yet.


# Now $(NAME) is properly treated as a dependency of all,
#  so Make knows it needs to look for a rule to build $(NAME), instead of trying to run it as a command.

# mlx: 
# 		$(MAKE) -C mlx_linux
libft: 
		$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 

clean:
		rm -f $(OBJ)
		$(MAKE) -C libft clean 

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C libft fclean

re: fclean all

.PHONY: all re fclean clean libft