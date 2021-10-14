#include "so_long.h"

int		free_sp_rt(char **tmp, int rt)
{
	if (tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (rt);
}
