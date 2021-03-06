CC := gcc
CFLAGS := -Wall -Wextra -Werror
OFLAGS := -lXext -lX11 -lm -lbsd
LIBS := ar rcs
NAME := so_long
NAME_MINILIBX := libmlx.a
NAME_LIBFT := libft.a
MINILIBX_DIR := minilibx-linux/
LIBFT_DIR := libft/

SRCS := main.c \
		main_loop.c \
		is_valid_argument.c \
		is_valid_map_file.c \
		is_valid_map_file_format.c \
		is_valid_map_file_format_utils.c \
		store_map.c \
		load_textures.c \
		init_mlx.c \
		draw_image.c \
		draw.c \
		move_player.c \
		move_player_utils.c \
		error.c \
		free.c \
		utils.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MINILIBX_DIR)$(NAME_MINILIBX) $(LIBFT_DIR)$(NAME_LIBFT) $(OFLAGS)

bonus: $(NAME)
	@make bonus -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MINILIBX_DIR)$(NAME_MINILIBX) $(LIBFT_DIR)$(NAME_LIBFT) $(OFLAGS)

debug: $(NAME)
	@make bonus -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) -g -fsanitize=address -o $(NAME) $(OBJS) $(MINILIBX_DIR)$(NAME_MINILIBX) $(LIBFT_DIR)$(NAME_LIBFT) $(OFLAGS)

clean:
	rm -f $(OBJS) 
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)

re: fclean all

.PHONY: all bonus clean fclean re