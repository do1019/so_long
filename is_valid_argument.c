/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:55:22 by dogata            #+#    #+#             */
/*   Updated: 2021/11/02 22:35:15 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_argument(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			putstr_error_exit(ERR_NOARG);
		else
			putstr_error_exit(ERR_INVAMOARG);
	}
	if (argc == 2)
	{
		if (!ft_memcmp(argv[1] + (ft_strlen(argv[1]) - 5), "/.ber", 5))
			putstr_error_exit(ERR_INVARG);
		if (ft_strlen(argv[1]) > 4
			&& !ft_memcmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
			return ;
	}
	putstr_error_exit(ERR_INVEXTARG);
}
