/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:28:49 by dogata            #+#    #+#             */
/*   Updated: 2021/11/06 02:43:59 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// When you pick up a collectible, it rewrites map
// to floor and sets flag to start the sprite animation.
static void	collectible_rerated_process(t_game *game)
{
	if (game->sp.collectible_acquisition \
	&& game->sp.collectible_acquisition_count)
		game->sp.collectible_acquisition_count--;
	if (game->sp.collectible_acquisition \
	&& !game->sp.collectible_acquisition_count)
	{
		game->sp.collectible_acquisition = false;
		game->map.map[game->sp.prev_collectible_y] \
		[game->sp.prev_collectible_x] = '0';
		game->sp.animation_start = true;
	}
}

// Update the player's texture when the main_loop function
// turns a specified number of times.
static void	switch_player_motion(t_game *game)
{
	if (game->loop_called_times == PLAYER_MOTION_SWITCH)
	{
		game->loop_called_times = 0;
		if (game->move)
			game->pl.player_tex++;
	}
}

// If playes's position coincides with exit and player
// has collected all collectibles, the escape flag is set to true.
static void	is_escape(t_game *game)
{
	if (game->map.map[game->pl.player_pos_y] \
	[game->pl.player_pos_x] == 'E' && !game->map.collectible_count)
		game->escape = true;
}

int	main_loop(t_game *game)
{
	game->loop_called_times++;
	collectible_rerated_process(game);
	if (game->pl.move_draw_count == 0)
		game->move = false;
	if (game->escape_count == WAIT_ESCAPE)
		exit(EXIT_SUCCESS);
	if (game->escape)
		game->escape_count++;
	switch_player_motion(game);
	if (game->pl.player_tex == PLAYER_MOTION_RESET)
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
	is_escape(game);
	return (0);
}
