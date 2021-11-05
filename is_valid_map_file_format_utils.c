/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_file_format_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:44:06 by dogata            #+#    #+#             */
/*   Updated: 2021/11/05 12:50:15 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_map(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

bool	is_map_error(t_game *game)
{
	return (game->map.errnum == ERR_INVCHRMAP
		|| game->map.errnum == ERR_SHAPEMAP
		|| game->map.errnum == ERR_NOSURRWALL);
}

void	check_requirements(char c, t_game *game)
{
	if (c == 'C')
		game->map.collectible_count++;
	else if (c == 'E')
		game->map.map_exit = true;
	else if (c == 'P')
		game->map.player_start_position_num++;
}

bool	is_surrounded_by_walls(t_game *game, char *line)
{
	if (line[game->map.row - 1] != '1')
	{
		game->map.errnum = ERR_NOSURRWALL;
		return (false);
	}
	return (true);
}
