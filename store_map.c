/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:44:03 by dogata            #+#    #+#             */
/*   Updated: 2021/11/02 22:32:41 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//// For debug
// static void display_map(t_game *game)
// {
// 	int	i;
// 	int j;

// 	setvbuf(stdout, (char *)NULL, _IONBF, 0);
// 	i = -1;
// 	while (++i < game->map.column)
// 	{
// 		j = -1;
// 		while (++j < game->map.row)
// 			printf("%d", game->map.map[i][j]);
// 		printf("\n");
// 	}
// }

// Allocate heap memory in map of game struct
static void	allocate_memory_in_map(t_game *game)
{
	wrapped_malloc((void **)&game->map.map, sizeof(int *) * game->map.column);
	wrapped_malloc((void **)&game->map.base_map, \
		sizeof(int) * game->map.row * game->map.column);
}

// Connect lines read by get_next_line
static char	*connect_line(char *connected_line, char *line)
{
	char	*ret_line;

	ret_line = ft_free_strjoin(connected_line, line);
	if (!ret_line)
		putstr_perror_exit(ERR_MALLOC);
	return (ret_line);
}


void	store_map(char **argv, t_game *game)
{
	int		fd;
	int		i;
	char	*line;
	char	*connected_line;

	fd = wrapped_open(argv);
	allocate_memory_in_map(game);
	connected_line = ft_strdup("");
	if (!connected_line)
		putstr_perror_exit(ERR_MALLOC);
	while ((get_next_line(fd, &line)) > 0)
	{
		connected_line = connect_line(connected_line, line);
		free_sp_rt(&line, 0);
	}
	connected_line = connect_line(connected_line, line);
	free_sp_rt(&line, 0);
	i = -1;
	while (++i < game->map.row * game->map.column)
		game->map.base_map[i] = connected_line[i];
	i = -1;
	while (++i < game->map.column)
		game->map.map[i] = game->map.base_map + i * game->map.row;
	free_sp_rt(&connected_line, 0);
}
