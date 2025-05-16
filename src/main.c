
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc !=2)
		return (err_msg(ERR_USAGE), 1);
	if (get_map(&game, argv[1]) < 0)
		return (err_msg("Can't get map\n"), 1);
	printf("This is cub 3d\n");
	print_linked_list(game.map);
	printf("The Y size of ma is >%d<\n", game.size_y);
	return (0);
}