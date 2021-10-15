#include "so_long.h"

/*
** Determine if it is a directory.
*/
static int	is_directory(char **argv, int fd)
{
	char	*buf;

	buf = malloc(sizeof(char) * 1);
	if (!buf)
		putstr_perror_exit("");
	if ((read(fd, buf, 1)) == ERROR)
	{
		free(buf);
		putstr_perror_exit("Failed to open the map file");
	}
	close(fd);
	return (free_sp_rt(&buf, 0));
}

/*
** Returns 1 if all spaces are blank, 0 otherwise.
*/
//static int	is_blank_line(char *line)
//{
	//while (*line)
	//{
		//if (*line == ' ')
			//line++;
		//else
			//return (0);
	//}
	//return (SUCCESS);
//}

//int			is_valid_map_format(char *line, t_game *game)
//{
	//int		count;
	//char	*s1;
	//char	*s2;

	//s1 = "Invalid map file format / The map is too large";
	//s2 =
	//"Invalid map file format / The map contains invalid character";
	//count = (int)ft_strlen(line);
	//if (game->map.map_initialized == false)
		//map_init(game);
	//if (count > MAX_MAP)
		//return (putstr_error(s1));
	//if (game->map.max_col < count)
		//game->map.max_col = count;
	//game->map.max_row++;
	//if (game->map.max_row > MAX_MAP)
		//return (putstr_error(s1));
	//if (is_valid_map_row(line, game) == ERROR)
		//return (putstr_error(s2));
	//game->map.map_search_start = true;
	//game->map.map_line++;
	//return (SUCCESS);
//}

static bool	is_upper_or_lower_wall(char *line)
{
	while (*line != '\0')
	{
		if (line[0] != '1')
		{
			return (false);
		}
		line++;
	}
	return (true);
}

/*
** Determine if the format is valid.
*/
static int	is_valid_map_format(char *line, t_game *game)
{
	if (game->map.column == 1 && is_upper_or_lower_wall(line))
	{
		game->map.search_start = true;
		return (SUCCESS);
	}
	else if (game->map.column > 1 && is_inside_map(line))
	{
		game->map.exist_inside_map = true;
		return (SUCCESS);
	}
	else if (game->map.column > 1 && game->map.exist_inside_map && is_upper_or_lower_wall(line))
	{
		game->map.search_end = true;
		return (SUCCESS);
	}
	return (putstr_error(game->map.errnum)); //エラーフラグ立てて構造体から持ってくる。
}

/*
** Determine if a map file is valid.
*/
void	is_valid_map_file(char **argv, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == ERROR)
		putstr_perror_exit(ERR_FAILOPN);
	is_directory(argv, fd);
	while ((get_next_line(fd, &line)) > 0)
	{
		game->map.column++;
		if (is_valid_map_format(line, game) == ERROR)
			exit(EXIT_FAILURE);
		free_sp_rt(&line, 0);
	}
	if (is_valid_map_format(line, game) == ERROR)
		exit(EXIT_FAILURE);
	free_sp_rt(&line, 0);
	printf("Map road sucess\n"); //test
	close(fd);
}
