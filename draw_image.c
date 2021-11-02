/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:50:04 by dogata            #+#    #+#             */
/*   Updated: 2021/11/03 03:52:29 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	draw_base_image(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.column)
	{
		x = -1;
		while (++x < game->map.row)
		{
			if (game->map.map[y][x] == '1')
				draw_texture(game, game->tex.wall, y, x);
			else if (y == game->exit_loc_y && x == game->exit_loc_x)
				draw_texture(game, game->tex.exit, y, x);
			else
				draw_texture(game, game->tex.floor, y, x);
		}
	}
}

void	draw_image(t_game *game, char map_char, int *texture)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.column)
	{
		x = -1;
		while (++x < game->map.row)
		{
			if (game->map.map[y][x] == map_char)
				draw_texture(game, texture, y, x);
		}
	}
}

void	draw_player_image(t_game *game, int *texture)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map.column)
	{
		x = -1;
		while (++x < game->map.row)
		{
			if (game->map.map[y][x] == 'P')
				draw_player_texture(game, texture, y, x);
		}
	}
}