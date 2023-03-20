NAME = cub3d

SRCS =	gnl/get_next_line.c			\
		gnl/get_next_line_utils.c	\
		parse_rbg.c					\
		parse_textures.c			\
		parse.c


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

$(NAME): $(OBJS)
	(cd mlx && make)
	make -C ./libft && make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L ./libft -lft

clean:
	cd libft && make fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
