/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_file_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:16:13 by dogata            #+#    #+#             */
/*   Updated: 2021/11/02 22:43:33 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Determine if the map has the correct shape.
static bool	is_correct_shape_map(t_game *game, int i)
{
	if (i != game->map.row)
	{
		game->map.errnum = ERR_SHAPEMAP;
		return (false);
	}
	return (true);
}

// Determine if the map is outside of the top and bottom walls.
static bool	is_inside_map(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (is_map_error(game))
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
		check_requirements(line[i], game);
		i++;
	}
	if (!is_correct_shape_map(game, i))
		return (false);
	if (!is_surrounded_by_walls(game, line))
		return (false);
	return (true);
}

// Determine if the map has the correct shape for the last line.
static bool	is_correct_shape_map_last(t_game *game, int i)
{
	if (i < MIN_WALL_LIMIT || (game->map.final_row && game->map.row != i))
	{
		game->map.errnum = ERR_SHAPEMAP;
		return (false);
	}
	return (true);
}

// Determine the top and bottom walls.
static bool	is_upper_or_lower_wall(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (is_map_error(game))
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
	if (!is_correct_shape_map_last(game, i))
		return (false);
	game->map.row = i;
	return (true);
}

int	is_valid_map_format(char *line, t_game *game)
{
	game->map.column++;
	if (game->map.column == 1 && is_upper_or_lower_wall(line, game))
		return (SUCCESS);
	else if (is_inside_map(line, game) && !game->map.final_row)
	{
		game->map.exist_inside_map = true;
		return (SUCCESS);
	}
	else if (game->map.exist_inside_map && \
		is_upper_or_lower_wall(line, game) && game->map.final_row)
		return (SUCCESS);
	return (putstr_error(game->map.errnum));
}
