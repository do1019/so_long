/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:54:33 by dogata            #+#    #+#             */
/*   Updated: 2021/11/01 05:23:20 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define SUCCESS 1
# define ERROR -1

//# define MAX_ROW 0
//# define MAX_COL 0
# define MAX_MAP 20
# define MIN_WALL_LIMIT 3

# define TILE_SIZE 32
//# define TEX_NUM 3
# define TEX_SIZE 1024
# define PLAYER_TEX_NUM 12

//color
# define BLACK -16777216

/*
** X11 events
*/
# define WINDOW_CLOSE 17
# define KEY_PRESS 

/*
** X11 masks
*/
# define STRUCTURE_NOTIFY 131072

enum	e_err {
	ERR_MALLOC,
	ERR_INITMLX,
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
	ERR_FAILXPM,
	ERR_INVXPM,
};

enum	e_basic_tex_path {
	WALL,
	FLOOR,
	EXIT,
	SPRITE,
};

enum	e_player_tex_path {
	FRONT1,
	FRONT2,
	FRONT3,
	BACK1,
	BACK2,
	BACK3,
	LEFT1,
	LEFT2,
	LEFT3,
	RIGHT1,
	RIGHT2,
	RIGHT3,
} ;

typedef struct s_texture
{
	int			*wall;
	int			*floor;
	int			*exit;
	int			*sprite;
	int			**player;
	int			**enemy;
	int			**movement;
}				t_tex;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		line_length;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

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
	void	*window;
	int		x_render_size;
	int		y_render_size;
	t_map	map;
	t_img	img;
	t_tex	tex;
}				t_game;

//is_valid_argument.c
void	is_valid_command_line_argument(int argc, char **argv);

/*
** is_valid_map_file.c
*/
void	is_valid_map_file(char **argv, t_game *game);

/*
** is_valid_map_file_format.c
*/
int		is_valid_map_format(char *line, t_game *game);

/*
** is_valid_map_file_format_utils.c
*/
bool	is_surrounded_by_walls(t_game *game, char *line);
void	check_requirements(char c, t_game *game);
bool	is_map_error(t_game *game);
bool	is_map(char c);

/*
** store_map.c
*/
void	store_map(char **argv, t_game *game);

//load_textures.c
void	load_textures(t_game *game);

//draw_image.c
void	draw_base_image(t_game *game);
void	draw_image(t_game *game, char map_char, int *texture);

//draw.c
void	draw_texture(t_game *game, int *texture, int ry, int rx);
void	my_mlx_pixel_put(t_game *game, int y, int x, int color);

/*
** init_mlx.c
*/
void	init_mlx(t_game *game);
void	init_img(t_game *game);
void	init_window(t_game *game);

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