/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_base_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:22:30 by dogata            #+#    #+#             */
/*   Updated: 2021/10/29 18:06:32 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_game *game, int y, int x, int color)
{
	char	*dst;

	dst = (char *)game->img.data + (y * game->img.line_length + x * (game->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_texture(t_game *game, int *texture, int ry, int rx)
{
	int	x;
	int	y;
	int i;

	i = 0;
	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
		{
			my_mlx_pixel_put(game, y + ry * 32, x + rx * 32, texture[i]);
			i++;
		}
	}
}

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
			else if (game->map.map[y][x] == '0')
				draw_texture(game, game->tex.floor, y, x);
			else
				draw_texture(game, game->tex.exit, y, x);	
		}
	}
}