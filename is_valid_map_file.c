#include "so_long.h"

static int	is_directory(char **argv, int fd)
{
	char	*buf;
	char	*errmsg;

	errmsg = "Failed to open the map file";
	buf = malloc(sizeof(char) * 1);
	if (!buf)
		putstr_perror_exit("");
	if ((read(fd, buf, 1)) == ERROR)
	{
		free_sp_rt(&buf, 0);
		putstr_perror_exit(errmsg);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == ERROR)
	{
		free_sp_rt(&buf, 0);
		putstr_perror_exit(errmsg);
	}
	return (free_sp_rt(&buf, 0));
}

int	is_valid_map_file(char **argv, t_game *game)
{
	char	*line;
	int		fd;
	int		rt;

	fd = open(argv[1], O_RDONLY);
	if (fd == ERROR)
		putstr_perror_exit("Failed to open the map file");
	is_directory(argv, fd);
	rt = SUCCESS;
	while ((get_next_line(fd, &line)) > 0 && rt == SUCCESS)
	{
		rt = is_valid_format(line, game);
		if (rt == ERROR)
			putstr_perror_exit("Invalid map file");
		free_sp_rt(&line, 0);
	}
	return (0);
}
