
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
	printf("-----------------------------------------\n");
	printf("The Y size of ma is >%d<\n", game.size_y);
	printf("The Y size of ma is >%s<\n", game.no_path);
	printf("The Y size of ma is >%s<\n", game.so_path);
	printf("The Y size of ma is >%s<\n", game.we_path);
	printf("The Y size of ma is >%s<\n", game.ea_path);
	printf("-----------------------------------------\n");
	int	i=0;
	while (i < 3)
		printf("The Ceiling color >%d<\n", game.ceiling[i++]);
	i=0;
	while (i < 3)
		printf("The Flooor color >%d<\n", game.floor[i++]);
	printf("-----------------------------------------\n");
	return (0);
}
