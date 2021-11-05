/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:54:52 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 22:43:45 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map.column * game->map.row)
	{
		if (game->map.base_map[i] == 'P')
		{
			game->pl.player_pos_y = i / game->map.row;
			game->pl.player_pos_x = i % game->map.row;
			game->pl.prev_pl_pos_y = i / game->map.row;
			game->pl.prev_pl_pos_x = i % game->map.row;
		}	
	}	
}

static void	prepare_start_game(t_game *game)
{
	int	x;
	int	y;

	init_mlx(game);
	load_textures(game);
	game->x_render_size = game->map.row * TILE_SIZE;
	game->y_render_size = game->map.column * TILE_SIZE;
	mlx_get_screen_size(game->mlx, &x, &y);
	if (game->x_render_size > x || game->y_render_size > y)
		putstr_error_exit(ERR_INVSIZEMAP);
	init_img(game);
	init_window(game);
	get_player_position(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	is_valid_argument(argc, argv);
	is_valid_map_file(argv, &game);
	store_map(argv, &game);
	prepare_start_game(&game);
	mlx_hook(game.window, WINDOW_CLOSE, STRUCTURE_NOTIFY, &close_window, &game);
	mlx_hook(game.window, FOCUS_IN, FOCUS_CHANGE, &redraw, &game);
	mlx_hook(game.window, KEY_PRESS_EVENT, KEY_PRESS_MASK, &move_player, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}
