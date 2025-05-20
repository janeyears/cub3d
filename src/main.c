
#include "cub3d.h"

// void render_f_and_c(t_game *game)
// {
// 	size_t	*address;
// 	size_t	i;

// 	address = (size_t)game->img->address;
// 	i = 800 * 600 / 2 + 1;
// 	while (--i > 0)
// 	{
// 		*address = game->ceiling;
// 		address++;
// 	}
// 	i = 800 * 600 / 2 + 1;
// 	while (--i > 0)
// 	{
// 		*address = game->floor;
// 		address++;
// 	}
// }

// rerender_image(t_game *game)
// {
// 	game->img->img = mlx_new_image(game->mlx, 800, 600);
// 	game->img->address = mlx_get_data_addr(game->img.img, &game->img->width,
// 			&game->img.height, &game->img.width);
// 	render_f_and_c(game);
// 	mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
// 	mlx_destroy_image(game->mlx, game->img.img);
// }

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
	printf("The Y size of ma is >%s<\n", game.ceiling_str);
	printf("The Y size of ma is >%s<\n", game.floor_str);
	printf("-----------------------------------------\n");
	// //player_pos(&game);
	// game.mlx = mlx_init(800, 600, "cub3d", true);
	// rerender_image(&game);
	// //mlx_hook(game.window, MLX_EVENT_KEY_PRESS, key_hook, &game);
	// mlx_loop(game.mlx);
	return (0);
}