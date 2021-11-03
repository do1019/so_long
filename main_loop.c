/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:28:49 by dogata            #+#    #+#             */
/*   Updated: 2021/11/04 01:13:54 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_loop_called_times = 0;
static int	g_escape_count = 0;

int	main_loop(t_game *game)
{
	g_loop_called_times++;
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
	if (game->pl.player_tex == MOTION_RESET)
		game->pl.player_tex = 0;
	draw_base_image(game);
	draw_image(game, 'C', game->tex.sprite);
	draw_player_image(game, \
		game->tex.player[game->pl.player_tex + game->pl.direction]);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	if (game->pl.player_pos_x == game->map.exit_loc_x && \
		game->pl.player_pos_y == game->map.exit_loc_y && \
		!game->map.collectible_count)
		game->escape = true;
	return (0);
}
