NAME = cub3d

SRCS =	src/gnl/get_next_line.c			\
		src/gnl/get_next_line_utils.c	\
		src/parse_rbg.c					\
		src/parse_textures.c			\
		src/free_functions.c				\
		src/parse.c


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

RM = /bin/rm

LINKS = -L libs/mlx -lmlx -framework OpenGL -framework AppKit -L libs/libft -lft

HEADER	= include

# LIBS
LIBFT = libs/libft
MLX = libs/mlx


.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $(HEADER)

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
