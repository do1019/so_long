#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	is_valid_command_line_argument(argc, argv);
	is_valid_map_file(argv, &game);
	exit(EXIT_SUCCESS);
}
