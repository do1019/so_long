/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:55:58 by dogata            #+#    #+#             */
/*   Updated: 2021/10/26 21:16:24 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Determine if it is a directory.
*/
static int	is_directory(char **argv)
{
	char	*buf;
	int		fd;

	fd = wrapped_open(argv);
	wrapped_malloc((void**)&buf, sizeof(char) * 1);
	if ((read(fd, buf, 1)) == ERROR)
	{
		free(buf);
		putstr_perror_exit(ERR_OPENFAIL);
	}
	close(fd);
	return (free_sp_rt(&buf, 0));
}

/*
** Determine if a character is allowed as a map.
*/
static bool	is_map(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

/*
** Determination of INVCHRMAP SHAPEMAP NOSURRWALL
*/
static bool	is_normal(t_game *game)
{
	return (game->map.errnum == ERR_INVCHRMAP
		|| game->map.errnum == ERR_SHAPEMAP
		|| game->map.errnum == ERR_NOSURRWALL);
}

/*
** Determine the top and bottom walls.
*/
static bool	is_upper_or_lower_wall(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (is_normal(game))
		return (false);
	while (line[i] != '\0')
	{
		if (!is_map(line[i]))
		{
			game->map.errnum = ERR_INVCHRMAP;
			return (false);
		}
		else if (is_map(line[i]) && line[i] != '1')
		{
			game->map.errnum = ERR_NOSURRWALL;
			return (false);
		}
		i++;
	}
	if (i < MIN_WALL_LIMIT || (game->map.final_row && game->map.row != i))
	{
		game->map.errnum = ERR_SHAPEMAP;
		return (false);
	}
	game->map.row = i;
	return (true);
}

/*
** Identify the elements required for map composition.
*/
static void	requirements_check(char c, t_game *game)
{
	if (c == 'C')
		game->map.collectible = true;
	else if (c == 'E')
		game->map.map_exit = true;
	else if (c == 'P')
		game->map.player_start_position++;
}

/*
** Determine if the map is outside of the top and bottom walls.
*/
static bool	is_inside_map(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (is_normal(game))
		return (false);
	while (line[i] != '\0')
	{
		if (i == 0 && is_map(line[i]) && line[i] != '1')
		{
			game->map.errnum = ERR_NOSURRWALL;
			return (false);
		}
		else if (!is_map(line[i]))
		{
			game->map.errnum = ERR_INVCHRMAP;
			return (false);
		}
		requirements_check(line[i], game);
		i++;
	}
	if (i != game->map.row)
	{
		game->map.errnum = ERR_SHAPEMAP;
		return (false);
	}
	if (line[game->map.row - 1] != '1')
	{
		game->map.errnum = ERR_NOSURRWALL;
		return (false);
	}
	return (true);
}

/*
** Determine what elements are needed for the map.
*/
static bool	final_check(t_game *game)
{
	if (!game->map.map_exit)
	{
		game->map.errnum = ERR_MAPEXIT;
		return (false);
	}
	else if (!game->map.collectible)
	{
		game->map.errnum = ERR_NOCOLLECT;
		return (false);
	}
	else if (game->map.player_start_position != 1)
	{
		game->map.errnum = ERR_MAPSPAWN;
		return (false);
	}
	return (true);
}

/*
** Determine if the format is valid.
*/
static int	is_valid_map_format(char *line, t_game *game)
{
	game->map.column++;
	if (game->map.column == 1 && is_upper_or_lower_wall(line, game))
		return (SUCCESS);
	else if (is_inside_map(line, game) && !game->map.final_row)
	{
		game->map.exist_inside_map = true;
		return (SUCCESS);
	}
	else if (game->map.exist_inside_map
		&& is_upper_or_lower_wall(line, game) && game->map.final_row)
			return (SUCCESS);
	return (putstr_error(game->map.errnum));
}

/*
** Determine if a map file is valid.
*/
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
