#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define SUCCESS 1
# define ERROR -1
# define MAX_ROW 0
# define MAX_COL 0
# define MAX_MAP 50

enum	e_err {
	ERR_NOARG,
	ERR_INVAMOARG,
	ERR_INVARG,
	ERR_INVEXTARG,
	ERR_FAILOPN,
	ERR_INVFMTMAP,

	ERR_MAPW,
	ERR_MAPSHAPE,
	ERR_MAPWALL,
	ERR_MAPCELL,
	ERR_MAPSPAWN,
	ERR_MAPEXIT,
	ERR_MAPMONEY,
};

typedef struct s_map
{
	bool	search_start;
	bool	search_end;
	bool	initialized;
	//bool	top_wall;
	bool	exist_inside_map;
	int		column;
	//int		start_column;
	//int		end_column;
	int		row;
	int		errnum;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}				t_game;

void	is_valid_command_line_argument(int argc, char **argv);
void	is_valid_map_file(char **argv, t_game *game);

int		putstr_error_exit(char *s);
int		putstr_perror_exit(char *s);

int		free_sp_rt(char **tmp, int rt);

#endif