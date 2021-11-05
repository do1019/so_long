/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:07:19 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 10:46:46 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// If you pick up a collectible, reduce the collectible count.
// And turn the map into a fllor.
static void	is_collectible(t_game *game)
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

// According to the keycode, determine whether the destination is a wall or not.
static bool	is_wall(t_game *game, int key_code)
{
	change_direction(key_code, game);
	if (key_code == W || key_code == ARROW_UP)
	{
		if (game->map.map[game->pl.player_pos_y - 1][game->pl.player_pos_x] == '1')
			return (true);
	}
	else if (key_code == A || key_code == ARROW_L)
	{
		if (game->map.map[game->pl.player_pos_y][game->pl.player_pos_x - 1] == '1')
			return (true);
	}
	else if (key_code == S || key_code == ARROW_DOWN)
	{
		if (game->map.map[game->pl.player_pos_y + 1][game->pl.player_pos_x] == '1')
			return (true);
	}
	else if (key_code == D || key_code == ARROW_R)
	{
		if (game->map.map[game->pl.player_pos_y][game->pl.player_pos_x + 1] == '1')
			return (true);
	}
	return (false);
}

int	move_player(int key_code, t_game *game)
{
	if (!game->escape && !game->move)
	{
		if ((key_code == W || key_code == ARROW_UP) && !is_wall(game, W))
		{
			game->key_code = W;
			game->pl.prev_pl_pos_x = game->pl.player_pos_x;
			game->pl.prev_pl_pos_y = game->pl.player_pos_y;
			game->pl.player_pos_y--;
			is_collectible(game);
			game->pl.direction = BACK;
			game->pl.move_count++;
			game->move = true;
			game->pl.move_draw_count = 16;
			game->y_pixel = 0;
			game->x_pixel = 0;
			printf("move_count %d\n", game->pl.move_count);
		}
		else if ((key_code == A || key_code == ARROW_L) && !is_wall(game, A))
		{
			game->key_code = A;
			game->pl.prev_pl_pos_x = game->pl.player_pos_x;
			game->pl.prev_pl_pos_y = game->pl.player_pos_y;
			game->pl.player_pos_x--;
			is_collectible(game);
			game->pl.direction = LEFT;
			game->pl.move_count++;
			game->move = true;
			game->pl.move_draw_count = 16;
			game->y_pixel = 0;
			game->x_pixel = 0;
			printf("move_count %d\n", game->pl.move_count);
		}	
		else if ((key_code == S || key_code == ARROW_DOWN) && !is_wall(game, S) )
		{
			game->key_code = S;
			game->pl.prev_pl_pos_x = game->pl.player_pos_x;
			game->pl.prev_pl_pos_y = game->pl.player_pos_y;
			game->pl.player_pos_y++;
			is_collectible(game);
			game->pl.direction = FRONT;
			game->pl.move_count++;
			game->move = true;
			game->pl.move_draw_count = 16;
			game->y_pixel = 0;
			game->x_pixel = 0;
			printf("move_count %d\n", game->pl.move_count);
		}
		else if ((key_code == D || key_code == ARROW_R) && !is_wall(game, D))
		{
			game->key_code = D;
			game->pl.prev_pl_pos_x = game->pl.player_pos_x;
			game->pl.prev_pl_pos_y = game->pl.player_pos_y;
			game->pl.player_pos_x++;
			is_collectible(game);
			game->pl.direction = RIGHT;
			game->pl.move_count++;
			game->move = true;
			game->pl.move_draw_count = 16;
			game->y_pixel = 0;
			game->x_pixel = 0;
			printf("move_count %d\n", game->pl.move_count);
		}
	}
	else if (key_code == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
