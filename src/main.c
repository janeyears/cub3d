#include "cub3d.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!game->mlx)
		return (err_msg(ERR_MLXINIT), 1);
	if (upload_wall_textures(game) != 0)
		return (1);
	init_player(game);
	game->rays = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (err_msg(ERR_USAGE), 1);
	if (get_map(&game, argv[1]) < 0)
		return (err_msg("Can't get map\n"), 1);
	if (init_game(&game) != 0)
		return (1);
	if (init_image(&game) == 1)
		return (1);
	mlx_key_hook(game.mlx, esc_hook, &game);
	mlx_close_hook(game.mlx, close_hook, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop_hook(game.mlx, draw_minimap, &game);
	mlx_loop(game.mlx);
	return (0);
}
