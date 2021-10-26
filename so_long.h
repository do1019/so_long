/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:54:33 by dogata            #+#    #+#             */
/*   Updated: 2021/10/27 02:25:56 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define MAX_MAP 20

# define MIN_WALL_LIMIT 3

enum	e_err {
	ERR_MALLOC,
	ERR_NOARG,
	ERR_INVAMOARG,
	ERR_INVARG,
	ERR_INVEXTARG,
	ERR_OPENFAIL,
	ERR_INVCHRMAP,
	ERR_NOSURRWALL,
	ERR_SHAPEMAP,
	ERR_MAPSPAWN,
	ERR_NOCOLLECT,
	ERR_MAPEXIT,
};

typedef struct s_map
{
	int		**map;
	int		*base_map;
	bool	initialized;
	bool	exist_inside_map;
	bool	final_row;
	bool	collectible;
	bool	map_exit;
	int		player_start_position;
	int		column;
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
void	store_map(char **argv, t_game *game);

/*
** utils.c
*/
int		wrapped_open(char **argv);
void	wrapped_malloc(void **ptr, size_t size);

/*
** error.c
*/
int		putstr_error_exit(int num);
int		putstr_perror_exit(int num);
int		putstr_error(int num);

/*
** free.c
*/
int		free_sp_rt(char **tmp, int rt);

#endif