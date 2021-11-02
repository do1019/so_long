/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:07:19 by dogata            #+#    #+#             */
/*   Updated: 2021/11/02 22:22:41 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int key_code, t_game *game)
{
	game->move_count++;
	if (key_code == W || key_code == ARROW_UP)
	{
		;
	}
	else if (key_code == A || key_code == ARROW_L)
		printf("A\n");	
	else if (key_code == S || key_code == ARROW_DOWN)
		printf("S\n");	
	else if (key_code == D || key_code == ARROW_R)
		printf("D\n");
	else if (key_code == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}