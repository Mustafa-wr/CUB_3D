# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 21:00:37 by bammar            #+#    #+#              #
#    Updated: 2023/04/24 10:17:22 by mradwan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	src/parse/parse_rgb.c			\
		src/parse/wall_error.c			\
		src/parse/parse_textures.c		\
		src/parse/add_spaces.c			\
		src/parse/rgb_init.c			\
		src/parse/init.c				\
		src/parse/validation.c			\
		src/parse/init_path.c 			\
		src/free_functions.c			\
		src/parse/parse.c				\
		src/render_pixel.c				\
		src/draw_line.c					\
		src/draw_rect.c					\
		src/movement.c					\
		src/hooks.c						\
		src/clear_img.c					\
		src/cub3d.c						\

OS = $(shell uname)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -D $(OS) -g #-fsanitize=address

	RM = /bin/rm

# LIBS
LIBFT = libs/libft


ifeq ($(OS), Linux)
	MLX = libs/mlx-linux
else
	MLX = libs/mlx-mac
endif

LINKS = -lm -L $(MLX) -L libs/libft -lft

ifeq ($(OS), Linux)
	LINKS += -L/usr/lib -lmlx -lXext -lX11
else
	LINKS += -lmlx -framework OpenGL -framework AppKit
endif

HEADER	= -Iinclude -I/usr/include -I$(MLX) -I$(LIBFT)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} $(HEADER)

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

.PHONY: all clean fclean re

