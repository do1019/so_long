/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:54:52 by dogata            #+#    #+#             */
/*   Updated: 2021/10/28 22:09:51 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		main_loop(t_game *game)
{
	//game->img.img = mlx_xpm_file_to_image(game->mlx, "./assets/tile/32tile.xpm", &game->img.img_width, &game->img.img_height);

	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}

static void	init_game(t_game *game)
{
	//init_mlx(game);
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

	init_mlx(&game);
	//init_img(&game);
	load_textures(&game);
	init_game(&game);


	main_loop(&game);
	//mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	exit(EXIT_SUCCESS);
}
