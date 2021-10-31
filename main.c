/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:54:52 by dogata            #+#    #+#             */
/*   Updated: 2021/11/01 04:48:53 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int		main_loop(t_game *game)
{
	draw_base_image(game);
	//draw_sprite_image(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}

static void	prepare_start_game(t_game *game)
{
	init_mlx(game);
	load_textures(game);
	game->x_render_size = game->map.row * TILE_SIZE;
	game->y_render_size = game->map.column * TILE_SIZE;
	init_img(game);
	init_window(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	is_valid_command_line_argument(argc, argv);
	is_valid_map_file(argv, &game);
	store_map(argv, &game);
	prepare_start_game(&game);
	mlx_hook(game.window, WINDOW_CLOSE, STRUCTURE_NOTIFY, &close_window, &game);

	//main_loop(&game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	mlx_destroy_image(game.mlx, game.img.img);
	exit(EXIT_SUCCESS);
}
