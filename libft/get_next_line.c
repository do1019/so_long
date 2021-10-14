/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 08:40:57 by dogata            #+#    #+#             */
/*   Updated: 2021/10/13 18:11:24 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SUCCESS 1
#define ERROR -1
#define REACHED_EOF 0
#define FD_MAX 256
#define BUFFER_SIZE 1024

static int	free_rt(int result, char **s1, char **s2)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (result);
}

static int	merge_up_to_newline_and_save(char **save, \
										char *buf, char **line, char *nl)
{
	char	*tmp;

	tmp = ft_substr(buf, 0, nl - buf);
	if (tmp == NULL)
		return (free_rt(ERROR, &(*save), NULL));
	*line = ft_free_strjoin(*save, tmp);
	if (*line == NULL)
		return (free_rt(ERROR, &buf, &tmp));
	*save = ft_substr(buf, (nl - buf) + 1, ft_strlen(nl + 1));
	if (*save == NULL)
		return (free_rt(ERROR, &tmp, NULL));
	return (free_rt(SUCCESS, &buf, &tmp));
}

static int	join_and_store_in_line(int fd, char **save, char *buf, char **line)
{
	char	*nl;
	int		rv;

	while (1)
	{	
		rv = read(fd, buf, BUFFER_SIZE);
		if (rv == 0 || rv == ERROR)
			break ;
		buf[rv] = '\0';
		nl = ft_strchr(buf, '\n');
		if (nl)
			return (merge_up_to_newline_and_save(save, buf, line, nl));
		else
		{
			*save = ft_free_strjoin(*save, buf);
			if (*save == NULL)
				return (free_rt(ERROR, &buf, NULL));
		}
	}
	return (free_rt(rv, &buf, NULL));
}

static int	store_in_line(char **save, char **line, char *nl)
{
	char	*tmp;

	tmp = *save;
	if (nl)
	{
		*line = ft_substr(*save, 0, nl - *save);
		if (*line == NULL)
			return (ERROR);
		*save = ft_substr(*save, (nl - *save) + 1, ft_strlen(nl + 1));
		if (*save == NULL)
			return (ERROR);
		return (free_rt(SUCCESS, &tmp, NULL));
	}
	else
	{
		*line = ft_strdup(tmp);
		if (*line == NULL)
			return (free_rt(ERROR, &(*save), NULL));
	}
	return (free_rt(REACHED_EOF, &(*save), NULL));
}

int	get_next_line(int fd, char **line)
{
	static char	*save[FD_MAX + 1];
	char		*buf;
	int			result;

	if (fd < 0 || FD_MAX < fd || BUFFER_SIZE < 1 || !line)
		return (ERROR);
	if (!save[fd])
	{
		save[fd] = ft_strdup("");
		if (save[fd] == NULL)
			return (ERROR);
	}
	if (ft_strchr(save[fd], '\n'))
		return (store_in_line(&save[fd], line, ft_strchr(save[fd], '\n')));
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (free_rt(ERROR, &save[fd], NULL));
	result = join_and_store_in_line(fd, &save[fd], buf, line);
	if (result != 0)
		return (result);
	return (store_in_line(&save[fd], line, NULL));
}
