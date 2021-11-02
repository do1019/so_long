/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 04:53:54 by dogata            #+#    #+#             */
/*   Updated: 2021/11/01 05:14:33 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_player_texture(t_game *game, int *texture)
{
	int	i;

	i = -1;
	while (++i < PLAYER_TEX_NUM)
	{
		if (texture == game->tex.player[i])
			return (true);
	}
	return (false);
}

void	my_mlx_pixel_put(t_game *game, int y, int x, int color)
{
	char	*dst;

	dst = (char *)game->img.data + \
		(y * game->img.line_length + x * (game->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_texture(t_game *game, int *texture, int ry, int rx)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (++y < TILE_SIZE)
	{
		x = -1;
		while (++x < TILE_SIZE)
		{
			if (!(texture == game->tex.sprite && texture[i] == TEX_SPRITE_BACK) && !(is_player_texture(game, texture) && texture[i] == TEX_PLAYER_BACK))
			{
				my_mlx_pixel_put(game, y + ry * 32, x + rx * 32, texture[i]);
				//if (texture == game->tex.player[FRONT2])
					//printf("%d\n", texture[i]);
			}
			i++;
		}
	}
}
