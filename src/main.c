
#include "cub3d.h"

void	init_game_struct(t_game *game)
{
	game->map = NULL;
	game->window = NULL;
	game->ceiling = NULL;
	game->floor = NULL;
	game->wall = NULL;
	game->player = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc !=2)
		return (err_msg(ERR_USAGE), 1);
	init_game_struct(&game);
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
	//player_pos(&game);
	game.mlx = mlx_init(800, 600, "cub3d", false);
	mlx_key_hook(game.mlx, key_hook, &game);
	get_color_code(&game);
	if (rerender_image(&game) == 1)
		return (1); // free exit
	mlx_loop(game.mlx);
	return (0);
}
