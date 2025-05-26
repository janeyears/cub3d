
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc !=2)
		return (err_msg(ERR_USAGE), 1);
	if (get_map(&game, argv[1]) < 0)
		return (err_msg("Can't get map\n"), 1);
	printf("This is cub 3d\n");
	int i = 0;
	while (game.map[i])
		printf("Ha:%s", game.map[i++]);
	printf("\n-----------------------------------------\n");
	printf("The Y size of ma is >%d<\n", game.size_y);
	printf("The path to north texture is >%s<\n", game.no_path);
	printf("The path to south texture is >%s<\n", game.so_path);
	printf("The path to west texture is >%s<\n", game.we_path);
	printf("The path to east texture is >%s<\n", game.ea_path);
	printf("-----------------------------------------\n");
	i=0;
	while (i < 3)
		printf("The Ceiling color >%d<\n", game.ceiling[i++]);
	i=0;
	while (i < 3)
		printf("The Floor color >%d<\n", game.floor[i++]);
	printf("-----------------------------------------\n");
	printf("x: %f y: %f pov: %c\n", game.player->x, game.player->y, game.player->pov);
	return (0);
}
