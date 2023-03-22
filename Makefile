NAME = cub3d

SRCS =	src/gnl/get_next_line.c			\
		src/gnl/get_next_line_utils.c	\
		src/parse_rbg.c					\
		src/parse_textures.c			\
		src/free_functions.c				\
		src/parse.c

OS = $(shell uname)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -D $(OS)

RM = /bin/rm

HEADER	= -Iinclude -I/usr/include -Imlx-linux

# LIBS
LIBFT = libs/libft

ifeq ($(OS), Linux)
	MLX = libs/mlx-linux
else
	MLX = libs/mlx-mac
endif

LINKS = -L $(MLX) -L libs/libft -lft

ifeq ($(OS), Linux)
	LINKS += -L$(MLX) -l$(MLX) -L/usr/lib -I$(MLX) -lXext -lX11 -lm -lz
else
	LINKS += -l$(MLX) -framework OpenGL -framework AppKit
endif

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
