# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bammar <bammar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 21:00:37 by bammar            #+#    #+#              #
#    Updated: 2023/03/22 22:37:49 by bammar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	src/gnl/get_next_line.c			\
		src/gnl/get_next_line_utils.c	\
		src/parse_rbg.c					\
		src/parse_textures.c			\
		src/free_functions.c			\
		src/parse.c						\
		src/cub3d.c						\

OS = $(shell uname)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -D $(OS)

RM = /bin/rm

# LIBS
LIBFT = libs/libft


ifeq ($(OS), Linux)
	MLX = libs/mlx-linux
else
	MLX = libs/mlx-mac
endif

LINKS = -L $(MLX) -L libs/libft -lft

ifeq ($(OS), Linux)
	LINKS += -L/usr/lib -lmlx -lXext -lX11
else
	LINKS += -l$(MLX) -framework OpenGL -framework AppKit
endif

HEADER	= -Iinclude -I/usr/include -I$(MLX) -I$(LIBFT)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} $(HEADER)

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX)
	make -C $(LIBFT) && make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $(NAME)

clean:
	(cd $(LIBFT) && make clean)
	(cd $(MLX) && make clean)
	$(RM) -f $(OBJS)

fclean: clean
	(cd $(LIBFT) && make fclean)
	$(RM) -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus
