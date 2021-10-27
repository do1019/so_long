/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 03:17:06 by dogata            #+#    #+#             */
/*   Updated: 2021/10/27 13:54:56 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_init(t_game *game)
{
	game->win = mlx_new_window(game->mlx,
		game->x_render_size, game->y_render_size, "so_long");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx,
		game->x_render_size, game->y_render_size);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img,
		&game->img.bpp, &game->img.line_length, &game->img.endian);
}
