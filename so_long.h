#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define SUCCESS 1
# define ERROR -1

typedef struct		s_game
{
	void			*mlx;
	void			*win;
}					t_game;

int	is_valid_command_line_argument(int argc, char **argv);
int	is_valid_map_file(char **argv, t_game *game);

int	putstr_error_exit(char *s);
int putstr_perror_exit(char *s);

int	free_sp_rt(char **tmp, int rt);

#endif