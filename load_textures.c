/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:49:32 by dogata            #+#    #+#             */
/*   Updated: 2021/11/03 01:16:37 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	*g_base_tex_path[] = {
	"assets/wall/wallA.xpm",
	"assets/floor/floorB.xpm",
	"assets/exit/exitB2.xpm",
	"assets/sprite/spriteA.xpm",
};

const char	*g_player_tex_path[] = {
	"assets/player/playerA/front/front1.xpm",
	"assets/player/playerA/front/front2.xpm",
	"assets/player/playerA/front/front3.xpm",
	"assets/player/playerA/back/back1.xpm",
	"assets/player/playerA/back/back2.xpm",
	"assets/player/playerA/back/back3.xpm",
	"assets/player/playerA/left/left1.xpm",
	"assets/player/playerA/left/left2.xpm",
	"assets/player/playerA/left/left3.xpm",
	"assets/player/playerA/right/right1.xpm",
	"assets/player/playerA/right/right2.xpm",
	"assets/player/playerA/right/right3.xpm",
};

// Initialize the texture buffer.
static void	init_textures_buffer(t_game *game)
{
	int	i;

	wrapped_malloc((void **)&game->tex.wall, sizeof(int) * TEX_SIZE);
	wrapped_malloc((void **)&game->tex.floor, sizeof(int) * TEX_SIZE);
	wrapped_malloc((void **)&game->tex.exit, sizeof(int) * TEX_SIZE);
	wrapped_malloc((void **)&game->tex.sprite, sizeof(int) * TEX_SIZE);
	wrapped_malloc((void **)&game->tex.player, sizeof(int *) * PLAYER_TEX_NUM);
	i = -1;
	while (++i < PLAYER_TEX_NUM)
		wrapped_malloc((void **)&game->tex.player[i], sizeof(int) * TEX_SIZE);
}

// Check for errors in xpm and store the loaded image data in the buffer.
static void	load_image(t_game *game, int *texture, const char *tex_path)
{
	int	x;
	int	y;

	game->img.img = mlx_xpm_file_to_image(game->mlx, (char *)tex_path, \
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
	int	i;
	init_textures_buffer(game);
	load_image(game, game->tex.wall, g_base_tex_path[WALL]);
	load_image(game, game->tex.floor, g_base_tex_path[FLOOR]);
	load_image(game, game->tex.exit, g_base_tex_path[EXIT]);
	load_image(game, game->tex.sprite, g_base_tex_path[SPRITE]);
	i = -1;
	while (++i < PLAYER_TEX_NUM)
		load_image(game, game->tex.player[i], g_player_tex_path[i]);
}
