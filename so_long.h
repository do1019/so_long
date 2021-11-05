/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:54:33 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 22:43:31 by dogata           ###   ########.fr       */
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

// MAP
# define MIN_WALL_LIMIT 3

// Texture
# define TILE_SIZE 32
# define TEX_SIZE 1024
# define PLAYER_TEX_NUM 16
# define SPRITE_TEX_NUM 8

// Color of transparent area
# define TEX_SPRITE_BACK 15539236
# define TEX_PLAYER_BACK 262660
# define TEX_EXIT_BACK 4007227

// X11 events
# define WINDOW_CLOSE 17
# define FOCUS_IN 9
# define KEY_PRESS_EVENT 2

// X11 masks
# define STRUCTURE_NOTIFY 131072
# define FOCUS_CHANGE 2097152
# define KEY_PRESS_MASK 1

// Key
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define ARROW_L 65361
# define ARROW_R 65363
# define ARROW_UP 65362
# define ARROW_DOWN 65364

// Direction
# define FRONT 0
# define BACK 4
# define LEFT 8
# define RIGHT 12

// Motion drawning related
# define PLAYER_MOTION_SWITCH 8
# define PLAYER_MOTION_RESET 4
# define NO_INDICATE_DELAY 16
# define DRAW_FRAME 32
# define WAIT_ESCAPE 60

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
	ERR_INVSIZEMAP,
	ERR_FAILXPM,
	ERR_INVXPM,
};

enum	e_basic_tex_path {
	WALL,
	FLOOR,
	EXIT,
	SPRITE,
};

typedef struct s_sprite
{
	int		prev_collectible_y;
	int		prev_collectible_x;
	int		collectible_acquisition_count;
	bool	collectible_acquisition;
	bool	animation_start;
	int		sprite_tex;
	int		sprite_draw_count;
}				t_sp;

typedef struct s_player
{
	int		player_pos_x;
	int		player_pos_y;
	int		prev_pl_pos_x;
	int		prev_pl_pos_y;
	int		move_count;
	int		direction;
	int		move_draw_count;
	int		player_tex;
}				t_pl;

typedef struct s_texture
{
	int		*wall;
	int		*floor;
	int		*exit;
	int		**player;
	int		**sprite;
	int		**enemy;
	int		**movement;
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
	bool	map_exit;
	int		player_start_position_num;
	int		collectible_count;
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
	int		key_code;
	int		y_pixel;
	int		x_pixel;
	bool	move;
	bool	escape;
	t_map	map;
	t_img	img;
	t_tex	tex;
	t_pl	pl;
	t_sp	sp;
}				t_game;

// Determines if the command line argument is valid.
void	is_valid_argument(int argc, char **argv);

// Determine if a map file is valid.
void	is_valid_map_file(char **argv, t_game *game);

// Determine if the format is valid.
int		is_valid_map_format(char *line, t_game *game);

// Determine if the map is surrounded by walls
bool	is_surrounded_by_walls(t_game *game, char *line);

// Identify the elements required for map composition.
void	check_requirements(char c, t_game *game);

// Determination of INVCHRMAP SHAPEMAP NOSURRWALL
bool	is_map_error(t_game *game);

// Determine if a character is allowed as a map.
bool	is_map(char c);

// Store map to an array of int.
void	store_map(char **argv, t_game *game);

// Load textures.
void	load_textures(t_game *game);

// Main loop.
int		main_loop(t_game *game);

// Draw the walls, floor, and exits.
void	draw_base_image(t_game *game);

// Draw the specified element.
void	draw_image(t_game *game, char map_char, int *texture);

// Draw the player image;
void	draw_player_image(t_game *game, int *texture);

// Draw the sprite image;
void	draw_sprite_image(t_game *game, int *texture);

// Draw a texture at the specified location.
void	draw_texture(t_game *game, int *texture, int ry, int rx);

// Draw a player texture.
void	draw_player_texture(t_game *game, int *texture, \
	int y_pixel, int x_pixel);

// Draw a sprite texture.
void	draw_sprite_texture(t_game *game, int *texture, \
		int y_pixel, int x_pixel);

// Draw a color at the specified location.
void	my_mlx_pixel_put(t_game *game, int y, int x, int color);

// Initialize mlx.
void	init_mlx(t_game *game);

// Initialize img.
void	init_img(t_game *game);

// Initialize window.
void	init_window(t_game *game);

// Action when a key is pressed.
int		move_player(int key_code, t_game *game);

// Action when w key is pressed.
void	move_with_w(t_game *game);

// Action when a key is pressed.
void	move_with_a(t_game *game);

// Action when s key is pressed.
void	move_with_s(t_game *game);

// Action when d key is pressed.
void	move_with_d(t_game *game);

// If you pick up a collectible, reduce the collectible count.
// And turn the map into a fllor.
void	is_collectible(t_game *game);

// it contains open function, 
// and calls perror and exit functions if there is an error.
// It returns file descriptor if normal.
int		wrapped_open(char **argv);

// It contains malloc and allocates bytes of size to ptr.
// If there is an error, call the perror and exit functions.
void	wrapped_malloc(void **ptr, size_t size);

// Close a window.
int		close_window(void);

// Redraw.
int		redraw(t_game *game);

// Receive the number corresponding to errstr, output it, and exit.
int		putstr_error_exit(int num);

// receive the number corresponding to errstr, 
// output it with the perror function, and exit.
int		putstr_perror_exit(int num);

// Receive the number corresponding to errstr, output it, and return -1.
int		putstr_error(int num);

// Receive a single pointer argument by call by reference,
// free it, puts in NULL, and returns rt.
int		free_sp_rt(char **tmp, int rt);

#endif