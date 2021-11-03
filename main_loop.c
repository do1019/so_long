/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:28:49 by dogata            #+#    #+#             */
/*   Updated: 2021/11/03 16:29:00 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_loop_called_times = 0;
static int	g_player_tex = 0;
static int	g_escape_count = 0;

int	main_loop(t_game *game)
{
	g_loop_called_times++;
	if (g_escape_count == 60)
		exit(EXIT_SUCCESS);
	if (game->escape)
		g_escape_count++;
	if (g_loop_called_times == 60)
	{
		g_loop_called_times = 0;
		if (game->key)
			g_player_tex++;
	}
	if (g_player_tex == 3)
		g_player_tex = 0;
	draw_base_image(game);
	draw_image(game, 'C', game->tex.sprite);
	if (game->pl.move_draw_count == TILE_SIZE)
	{
		game->move = false;
		game->pl.move_draw_count = 0;
	}	
	if (!game->move)
		draw_image(game, 'P', game->tex.player[g_player_tex + game->pl.direction]);
	else
		draw_player_image(game, game->tex.player[g_player_tex + game->pl.direction]);

	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	//idouryou to map no p no iti ga onaji ni nattara move wo sageru
	if (game->pl.player_pos_x == game->exit_loc_x && game->pl.player_pos_y == game->exit_loc_y)
		game->escape = true;
	return (0);
}
