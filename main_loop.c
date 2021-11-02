/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:28:49 by dogata            #+#    #+#             */
/*   Updated: 2021/11/02 22:30:35 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	g_called_times = 0;
static int	g_player = 0;

int	main_loop(t_game *game)
{
	g_called_times++;
	if (g_called_times == 60)
	{
		g_called_times = 0;
		g_player++;
	}
	if (g_player == 3)
		g_player = 0;
	draw_base_image(game);
	draw_image(game, 'C', game->tex.sprite);
	draw_image(game, 'P', game->tex.player[g_player]);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}
