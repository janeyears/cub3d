#include "cub3d.h"

int	upload_wall_textures(t_game *game)
{
	game->texture[NORTH] = mlx_load_png(game->no_path);
	if (!game->texture[NORTH])
		return (err_msg(ERR_TEXTURE), 1);
	game->texture[SOUTH] = mlx_load_png(game->so_path);
	if (!game->texture[SOUTH])
		return (err_msg(ERR_TEXTURE), 1);
	game->texture[WEST] = mlx_load_png(game->we_path);
	if (!game->texture[WEST])
		return (err_msg(ERR_TEXTURE), 1);
	game->texture[EAST] = mlx_load_png(game->ea_path);
	if (!game->texture[EAST])
		return (err_msg(ERR_TEXTURE), 1);
	return (0);
}

int	rerender_image(t_game *game)
{
	game->background = mlx_new_image(game->mlx, 800, 600);
	if (!game->background)
		return (1);
	render_f_and_c(game);
	if (mlx_image_to_window(game->mlx, game->background, 0, 0) == -1)
		return (1);
	printf("Textures uploaded successfully\n");
	return (0);
}
