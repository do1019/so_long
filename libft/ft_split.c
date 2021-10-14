/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:40:24 by dogata            #+#    #+#             */
/*   Updated: 2021/04/17 20:36:53 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_array(char const *s, char c)
{
	int		flag;
	int		array;

	flag = 0;
	array = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
		{
			flag = 0;
			s++;
		}
		while (*s != c && *s != '\0')
		{
			if (!flag)
				flag = 1;
			s++;
		}
		if (flag)
			array++;
		flag = 0;
	}
	return (array);
}

static char	**free_memory(char **ans)
{
	int		array;

	array = 0;
	while (ans[array])
	{
		free(ans[array]);
		array++;
	}
	free(ans);
	return (NULL);
}

static char	*convert_c_to_null(char *s, char c, char *dest)
{
	int		count;

	count = 0;
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			dest[count] = '\0';
		else
			dest[count] = *s;
		s++;
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

static char	**do_split(char *s, char c, int array, int slen)
{
	char	**ans;
	char	*nulls;
	char	*tmp;
	int		array_count;

	array_count = 0;
	ans = ft_calloc(array + 1, sizeof(char *));
	if (ans == NULL)
		return (NULL);
	nulls = convert_c_to_null(s, c, ft_calloc(slen + 1, sizeof(char)));
	if (nulls == NULL)
		return (free_memory(ans));
	tmp = nulls;
	while (array--)
	{
		while (*nulls == '\0')
			nulls++;
		ans[array_count++] = ft_substr(nulls, 0, ft_strlen(nulls));
		if (ans[array_count - 1] == NULL)
			return (free_memory(ans));
		while (*nulls != '\0')
			nulls++;
	}
	free(tmp);
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		array_count;

	if (!s)
		return (NULL);
	array_count = count_array(s, c);
	ans = do_split((char *)s, c, array_count, ft_strlen(s));
	if (ans == NULL)
		return (NULL);
	ans[array_count] = NULL;
	return (ans);
}
