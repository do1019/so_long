/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:07:19 by dogata            #+#    #+#             */
/*   Updated: 2021/11/03 00:29:07 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_wall(t_game *game, int key_code)
{
	if (key_code == W || key_code == ARROW_UP)
	{
		if (game->map.map[game->player_pos_y - 1][game->player_pos_x] == '1')
			return (true);
	}
	else if (key_code == A || key_code == ARROW_L)
	{
		if (game->map.map[game->player_pos_y][game->player_pos_x - 1] == '1')
			return (true);
	}
	else if (key_code == S || key_code == ARROW_DOWN)
	{
		if (game->map.map[game->player_pos_y + 1][game->player_pos_x] == '1')
			return (true);
	}
	else if (key_code == D || key_code == ARROW_R)
	{
		if (game->map.map[game->player_pos_y][game->player_pos_x + 1] == '1')
			return (true);
	}
	return (false);
}

int	move_player(int key_code, t_game *game)
{
	if (!game->escape)
	{
		if ((key_code == W || key_code == ARROW_UP) && !is_wall(game, W))
		{
			game->map.map[game->player_pos_y][game->player_pos_x] = '0';
			game->map.map[game->player_pos_y - 1][game->player_pos_x] = 'P';
			game->player_pos_y--;
			game->move_count++;
		}
		else if ((key_code == A || key_code == ARROW_L) && !is_wall(game, A))
		{
		
			game->map.map[game->player_pos_y][game->player_pos_x] = '0';
			game->map.map[game->player_pos_y][game->player_pos_x - 1] = 'P';
			game->player_pos_x--;
			game->move_count++;
		}	
		else if ((key_code == S || key_code == ARROW_DOWN) && !is_wall(game, S) )
		{
			game->map.map[game->player_pos_y][game->player_pos_x] = '0';
			game->map.map[game->player_pos_y + 1][game->player_pos_x] = 'P';
			game->player_pos_y++;
			game->move_count++;
		}
		else if ((key_code == D || key_code == ARROW_R) && !is_wall(game, D))
		{
			game->map.map[game->player_pos_y][game->player_pos_x] = '0';
			game->map.map[game->player_pos_y][game->player_pos_x + 1] = 'P';
			game->player_pos_x++;
			game->move_count++;
		}
		else if (key_code == ESC)
			exit(EXIT_SUCCESS);
	}
	return (0);
}
