/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:49:32 by dogata            #+#    #+#             */
/*   Updated: 2021/11/01 04:43:53 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*g_tex_path[] = {
	"assets/wall/32wallA.xpm",
	"assets/floor/32floorB.xpm",
	"assets/exit/exitA.xpm",
	"assets/sprite/spriteA.xpm"
};

static void	init_textures_buffer(t_game *game)
{
	wrapped_malloc((void **)&game->tex.wall, sizeof(int) * TEX_SIZE);
	wrapped_malloc((void **)&game->tex.floor, sizeof(int) * TEX_SIZE);
	wrapped_malloc((void **)&game->tex.exit, sizeof(int) * TEX_SIZE);
	wrapped_malloc((void **)&game->tex.sprite, sizeof(int) * TEX_SIZE);
}

static void	load_image(t_game *game, int *texture, char *tex_path)
{
	int	x;
	int	y;

	game->img.img = mlx_xpm_file_to_image(game->mlx, tex_path, \
		&game->img.img_width, &game->img.img_height);
	if (!game->img.img)
		putstr_error_exit(ERR_FAILXPM);
	if (game->img.img_height != TILE_SIZE || game->img.img_width != TILE_SIZE)
		putstr_error_exit(ERR_INVXPM);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, \
		&game->img.bpp, &game->img.line_length, &game->img.endian);
	y = -1;
	while (++y < game->img.img_height)
	{
		x = -1;
		while (++x < game->img.img_width)
			texture[game->img.img_width * y + x] = \
				game->img.data[game->img.img_width * y + x];
	}
	mlx_destroy_image(game->mlx, game->img.img);
}

void	load_textures(t_game *game)
{
	init_textures_buffer(game);
	load_image(game, game->tex.wall, g_tex_path[WALL]);
	load_image(game, game->tex.floor, g_tex_path[FLOOR]);
	load_image(game, game->tex.exit, g_tex_path[EXIT]);
	load_image(game, game->tex.sprite, g_tex_path[SPRITE]);
}
