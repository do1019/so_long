/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:43:36 by dogata            #+#    #+#             */
/*   Updated: 2021/11/02 23:09:13 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	*g_errstr[] = {
	"malloc failed",
	"init_mlx failed",
	"Argument : Specify a map file",
	"Argument : Invalid amount of arguments",
	"Argument : Invalid argument",
	"Argument : Invalid file extension : Expected \"*.ber\"",
	"Argument : Failed to open the map file",
	"Map parsing : Invalid character : \
		Only '0', '1', 'C', 'E', and 'P' are valid.",
	"Map parsing : Map is not surrounded by walls",
	"Map parsing : Invalid shape : Map must be rectangular",
	"Map parsing : Invalid amount of player spawn points : Expected 1",
	"Map parsing : Invalid amount of collectible points : Expected >= 1",
	"Map parsing : Invalid amount of exit points : Expected >= 1",
	"Assets : Invalid xpm file : Failed xpm file to image",
	"Assets : Invalid xpm file : Valid only for xpm of size 32 * 32",
};

int	putstr_error_exit(int num)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	ft_putendl_fd((char *)g_errstr[num], 2);
	exit(EXIT_FAILURE);
}

int	putstr_perror_exit(int num)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	perror((char *)g_errstr[num]);
	exit(EXIT_FAILURE);
}

int	putstr_error(int num)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	ft_putendl_fd((char *)g_errstr[num], 2);
	return (ERROR);
}
