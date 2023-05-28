# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 21:00:37 by bammar            #+#    #+#              #
#    Updated: 2023/05/28 15:40:52 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	src/parse/parse_rgb.c			\
		src/parse/wall_error.c			\
		src/parse/parse_textures.c		\
		src/parse/add_spaces.c			\
		src/parse/rgb_init.c			\
		src/parse/init.c				\
		src/parse/xpms.c				\
		src/parse/validation.c			\
		src/parse/init_path.c 			\
		src/free_functions.c			\
		src/parse/parse.c				\
		src/render_pixel.c				\
		src/draw_line.c					\
		src/draw_rect.c					\
		src/utils.c						\
		src/movement.c					\
		src/textures.c					\
		src/clear_img.c					\
		src/walls.c						\
		src/draw_2d.c					\
		src/cub3d.c						\
		src/hooks.c						\
		src/raycast.c					\
		src/draw_ver_lines.c			\

OS := $(shell uname)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -D $(OS) -Ofast -march=native

RM = /bin/rm

# LIBS
LIBFT = libs/libft

MLX = libs/mlx-mac

LINKS = -lm -L $(MLX) -L libs/libft -lft

LINKS += -lmlx -framework OpenGL -framework AppKit

HEADER	= -Iinclude -I/usr/include -I$(MLX) -I$(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} $(HEADER)

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME)

clean:
	(cd $(LIBFT) && make clean)
	(cd $(MLX) && make clean)
	$(RM) -f $(OBJS)

fclean: clean
	(cd $(LIBFT) && make fclean)
	$(RM) -f $(NAME)

re: fclean all

re2:
	(cd $(LIBFT) && make fclean)
	$(RM) -f $(OBJS)
	make all

.PHONY: all clean fclean re
