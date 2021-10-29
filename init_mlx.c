/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 03:17:06 by dogata            #+#    #+#             */
/*   Updated: 2021/10/29 18:08:35 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		putstr_perror_exit(ERR_INITMLX);
}

void	init_window(t_game *game)
{
	game->window = mlx_new_window(game->mlx, \
		game->x_render_size, game->y_render_size, "so_long");
}

void	init_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, \
		game->x_render_size, game->y_render_size);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, \
		&game->img.bpp, &game->img.line_length, &game->img.endian);
}
