/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:00:18 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 21:48:12 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_with_w(t_game *game)
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
	printf("Move count : %d\n", game->pl.move_count);
}

void	move_with_a(t_game *game)
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
	printf("Move count : %d\n", game->pl.move_count);
}

void	move_with_s(t_game *game)
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
	printf("Move count : %d\n", game->pl.move_count);
}

void	move_with_d(t_game *game)
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
	printf("Move count : %d\n", game->pl.move_count);
}
