#include "so_long.h"

/*
** Takes a single pointer argument, free it, puts in NULL, and returns rt.
*/
int		free_sp_rt(char **tmp, int rt)
{
	if (tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (rt);
}
