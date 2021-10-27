/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:54:52 by dogata            #+#    #+#             */
/*   Updated: 2021/10/27 21:57:52 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	is_valid_command_line_argument(argc, argv);
	is_valid_map_file(argv, &game);
	store_map(argv, &game);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "test");
	//game.x_render_size = 800;
	//game.y_render_size = 600;
	//img_init(&game);
	//window_init(&game);
	exit(EXIT_SUCCESS);
}
