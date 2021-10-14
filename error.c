#include "so_long.h"

int	putstr_error_exit(char *s)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

int	putstr_perror_exit(char *s)
{
	ft_putendl_fd("\x1b[31mERROR\x1b[m", 2);
	perror(s);
	exit(EXIT_FAILURE);
}