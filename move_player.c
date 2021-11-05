/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:07:19 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 19:54:28 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_collectible(t_game *game)
{
	if (game->map.map[game->pl.player_pos_y][game->pl.player_pos_x] == 'C')
	{
		game->map.collectible_count--;
		game->sp.collectible_acquisition = true;
		game->sp.collectible_acquisition_count = NO_INDICATE_DELAY;
		game->sp.prev_collectible_y = game->pl.player_pos_y;
		game->sp.prev_collectible_x = game->pl.player_pos_x;
		game->sp.sprite_draw_count = DRAW_FRAME;
		game->sp.sprite_tex = 0;
	}
}

// Change the direction of the player.
static void	change_direction(int key_code, t_game *game)
{
	if (key_code == W || key_code == ARROW_UP)
		game->pl.direction = BACK;
	else if (key_code == A || key_code == ARROW_L)
		game->pl.direction = LEFT;
	else if (key_code == S || key_code == ARROW_DOWN)
		game->pl.direction = FRONT;
	else if (key_code == D || key_code == ARROW_R)
		game->pl.direction = RIGHT;
	else if (key_code == ESC)
		exit(EXIT_SUCCESS);
}

static bool	_is_wall(int key_code, t_game *game)
{
	if (key_code == W || key_code == ARROW_UP)
	{
		if (game->map.map[game->pl.player_pos_y - 1] \
		[game->pl.player_pos_x] == '1')
			return (true);
	}
	else if (key_code == A || key_code == ARROW_L)
	{
		if (game->map.map[game->pl.player_pos_y] \
		[game->pl.player_pos_x - 1] == '1')
			return (true);
	}
	else if (key_code == S || key_code == ARROW_DOWN)
	{
		if (game->map.map[game->pl.player_pos_y + 1] \
		[game->pl.player_pos_x] == '1')
			return (true);
	}
	else if (key_code == D || key_code == ARROW_R)
	{
		if (game->map.map[game->pl.player_pos_y] \
		[game->pl.player_pos_x + 1] == '1')
			return (true);
	}
	return (false);
}

// According to the keycode, determine whether the destination is a wall or not.
static bool	is_wall(t_game *game, int key_code)
{
	change_direction(key_code, game);
	return (_is_wall(key_code, game));
}

int	move_player(int key_code, t_game *game)
{
	if (!game->escape && !game->move)
	{
		game->y_pixel = 0;
		game->x_pixel = 0;
		if ((key_code == W || key_code == ARROW_UP) && !is_wall(game, W))
			move_with_w(game);
		else if ((key_code == A || key_code == ARROW_L) && !is_wall(game, A))
			move_with_a(game);
		else if ((key_code == S || key_code == ARROW_DOWN) && !is_wall(game, S))
			move_with_s(game);
		else if ((key_code == D || key_code == ARROW_R) && !is_wall(game, D))
			move_with_d(game);
	}
	else if (key_code == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
