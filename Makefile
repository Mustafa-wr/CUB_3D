# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 21:00:37 by bammar            #+#    #+#              #
#    Updated: 2023/03/28 21:34:00 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	src/parse/parse_rbg.c			\
		src/parse/parse_textures.c		\
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

CFLAGS = -Wall -Wextra -Werror -D $(OS) -g

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

.PHONY: all clean fclean re bonus

