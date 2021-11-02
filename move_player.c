/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:07:19 by dogata            #+#    #+#             */
/*   Updated: 2021/11/02 22:15:43 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int key_code, t_game *game)
{
	if (key_code == W)
		printf("W\n");	
	else if (key_code == A)
		printf("A\n");	
	else if (key_code == S)
		printf("S\n");	
	else if (key_code == D)
		printf("D\n");
	else if (key_code == ESC)
		exit(EXIT_SUCCESS);
	(void)game;
	return (0);
}