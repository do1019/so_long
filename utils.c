/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:47:17 by dogata            #+#    #+#             */
/*   Updated: 2021/11/04 01:07:50 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrapped_open(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == ERROR)
		putstr_perror_exit(ERR_OPENFAIL);
	return (fd);
}

void	wrapped_malloc(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!*ptr)
		putstr_perror_exit(ERR_MALLOC);
}

int	close_window(void)
{
	exit(EXIT_SUCCESS);
}

int	redraw(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}