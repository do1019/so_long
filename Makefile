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
		is_valid_argument.c \
		is_valid_map_file.c \
		is_valid_map_file_format.c \
		is_valid_map_file_format_utils.c \
		store_map.c \
		load_textures.c \
		init_mlx.c \
		draw_image.c \
		draw.c \
		error.c \
		free.c \
		utils.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MINILIBX_DIR)$(NAME_MINILIBX) $(LIBFT_DIR)$(NAME_LIBFT) $(OFLAGS)

debug: $(NAME)
	@make bonus -C $(LIBFT_DIR)
	make -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) -g -fsanitize=address -o $(NAME) $(OBJS) $(MINILIBX_DIR)$(NAME_MINILIBX) $(LIBFT_DIR)$(NAME_LIBFT) $(OFLAGS)

clean:
	rm -f $(OBJS) $(LIBFT_DIR)*.o $(MINILIBX_DIR)*.o

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)$(NAME_LIBFT) $(MINILIBX_DIR)$(NAME_MINILIBX)

re: fclean all

.PHONY: all bonus clean fclean re