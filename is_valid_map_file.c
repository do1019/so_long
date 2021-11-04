/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:55:58 by dogata            #+#    #+#             */
/*   Updated: 2021/11/04 00:25:51 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Determine if it is a directory.
static int	is_directory(char **argv)
{
	char	*buf;
	int		fd;

	fd = wrapped_open(argv);
	wrapped_malloc((void **)&buf, sizeof(char) * 1);
	if ((read(fd, buf, 1)) == ERROR)
	{
		free(buf);
		putstr_perror_exit(ERR_OPENFAIL);
	}
	close(fd);
	return (free_sp_rt(&buf, 0));
}

// Determine what elements are needed for the map.
static bool	final_check(t_game *game)
{
	if (!game->map.map_exit)
	{
		game->map.errnum = ERR_MAPEXIT;
		return (false);
	}
	else if (!game->map.collectible_count)
	{
		game->map.errnum = ERR_NOCOLLECT;
		return (false);
	}
	else if (game->map.player_start_position_num != 1)
	{
		game->map.errnum = ERR_MAPSPAWN;
		return (false);
	}
	return (true);
}

void	is_valid_map_file(char **argv, t_game *game)
{
	char	*line;
	int		fd;

	is_directory(argv);
	fd = wrapped_open(argv);
	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (is_valid_map_format(line, game) == ERROR)
			exit(EXIT_FAILURE);
		free_sp_rt(&line, 0);
	}
	game->map.final_row = true;
	if (is_valid_map_format(line, game) == ERROR)
		exit(EXIT_FAILURE);
	if (!final_check(game))
		putstr_error_exit(game->map.errnum);
	free_sp_rt(&line, 0);
	close(fd);
}
