NAME		= so_long
MLX_DIR		= ./MLX42
MLX_LIB		= $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
SRCS		= $(wildcard srcs/*.c srcs/*/*.c)
OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR) \
				-include -I$(LIBFT_DIR)
LDFLAGS		= -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	cc $(OBJS) $(LIBFT) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

$(MLX_LIB):
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re