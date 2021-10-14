#include "so_long.h"

int	is_valid_command_line_argument(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
	{
		if (argc == 1)
			putstr_error_exit("Specify a map file");
		else
			putstr_error_exit("Invalid argument");
	}
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) <= 4
			|| !ft_memcmp(argv[1] + (ft_strlen(argv[1]) - 5), "/.ber", 5))
			putstr_error_exit("Invalid map file");
		if (!ft_memcmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
			return (0);
	}
	putstr_error_exit("Invalid map file");
	return (0);
}
