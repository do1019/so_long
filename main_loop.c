/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:28:49 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 10:39:55 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_loop_called_times = 0;
static int	g_escape_count = 0;

int	main_loop(t_game *game)
{
	g_loop_called_times++;
	if (game->sp.collectible_acquisition && game->sp.collectible_acquisition_count)
		game->sp.collectible_acquisition_count--;
	if (game->sp.collectible_acquisition && !game->sp.collectible_acquisition_count)
	{
		game->sp.collectible_acquisition = false;
		game->map.map[game->sp.prev_collectible_y][game->sp.prev_collectible_x] = '0';
		game->sp.animation_start = true;
	}
	if (game->pl.move_draw_count == 0)
		game->move = false;
	if (g_escape_count == WAIT_ESCAPE)
		exit(EXIT_SUCCESS);
	if (game->escape)
		g_escape_count++;
	if (g_loop_called_times == MOTION_SWITCH)
	{
		g_loop_called_times = 0;
		if (game->move)
			game->pl.player_tex++;
	}
	if (game->pl.player_tex == PL_MOTION_RESET)
		game->pl.player_tex = 0;
	draw_base_image(game);
	draw_image(game, 'C', game->tex.sprite[0]);
	if (game->sp.animation_start && game->sp.sprite_draw_count)
	{
		draw_sprite_image(game, game->tex.sprite[game->sp.sprite_tex]);
		if (game->sp.sprite_draw_count % 4 == 0)
			game->sp.sprite_tex++;
	}
	draw_player_image(game, \
		game->tex.player[game->pl.player_tex + game->pl.direction]);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	if (game->pl.player_pos_x == game->map.exit_loc_x && \
		game->pl.player_pos_y == game->map.exit_loc_y && \
		!game->map.collectible_count)
		game->escape = true;
	return (0);
}
