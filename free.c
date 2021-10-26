/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:45:00 by dogata            #+#    #+#             */
/*   Updated: 2021/10/26 20:45:11 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Takes a single pointer argument, free it, puts in NULL, and returns rt.
*/
int	free_sp_rt(char **tmp, int rt)
{
	if (tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (rt);
}
