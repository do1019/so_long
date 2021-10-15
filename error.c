#include "so_long.h"

const char	*g_errstr[] = {
	"Argument : Specify a map file"
	"Argument : Invalid amount of arguments",
	"Argument : Invalid argument",
	"Argument : Invalid file extension : Expected \"*.ber\"",
	"Argument : Failed to open the map file",
	"Map parsing : Invalid format",
	//"Map parsing : Invalid width",
	//"Map parsing : Invalid shape : Map must be rectangular",
	//"Map parsing : Map is not surrounded by walls",
	//"Map parsing : Invalid cell : Expected 01PEC",
	//"Map parsing : Invalid amount of player spawn points : Expected 1",
	//"Map parsing : Invalid amount of exit points : Expected 1",
	//"Map parsing : Invalid amount of collectible points : Expected >= 1",
};

int	putstr_error_exit(int num)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	ft_putendl_fd((char *)g_errstr[num], 2);
	exit(EXIT_FAILURE);
}

int	putstr_perror_exit(int num)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	perror((char *)g_errstr[num]);
	exit(EXIT_FAILURE);
}

int	putstr_error(int num)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	ft_putendl_fd((char *)g_errstr[num], 2);
	return (ERROR);
}
