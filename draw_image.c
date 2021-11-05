/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:50:04 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 21:43:53 by dogata           ###   ########.fr       */
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
			else if (y == game->map.exit_loc_y && x == game->map.exit_loc_x)
			{
				draw_texture(game, game->tex.floor, y, x);
				draw_texture(game, game->tex.exit, y, x);
			}
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
	int	i;

	if (!game->move)
		draw_texture(game, texture, game->pl.player_pos_y, \
		game->pl.player_pos_x);
	else
	{
		i = -1;
		if (game->key_code == W)
			game->y_pixel -= 2;
		else if (game->key_code == A)
			game->x_pixel -= 2;
		else if (game->key_code == S)
			game->y_pixel += 2;
		else if (game->key_code == D)
			game->x_pixel += 2;
		while (++i < TILE_SIZE)
		{
			draw_player_texture(game, texture, game->y_pixel, game->x_pixel);
			mlx_put_image_to_window(game->mlx, game->window, \
			game->img.img, 0, 0);
		}
		game->pl.move_draw_count--;
	}
}

void	draw_sprite_image(t_game *game, int *texture)
{
	int	i;

	i = -1;
	while (++i < TILE_SIZE)
	{
		draw_sprite_texture(game, texture, game->sp.prev_collectible_y, \
		game->sp.prev_collectible_x);
		mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	}
	game->sp.sprite_draw_count--;
}
