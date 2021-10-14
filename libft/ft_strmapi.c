/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 08:16:03 by dogata            #+#    #+#             */
/*   Updated: 2021/04/16 05:17:24 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	unsigned int	slen;
	char			*ans;

	if (!s)
		return (NULL);
	count = 0;
	slen = ft_strlen(s);
	ans = ft_calloc(slen + 1, sizeof(char));
	if (ans == NULL)
		return (NULL);
	while (slen)
	{
		ans[count] = (*f)(count, s[count]);
		count++;
		slen--;
	}
	ans[count] = '\0';
	return (ans);
}
