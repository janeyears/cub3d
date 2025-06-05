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

int	init_image(t_game *game)
{
	game->scene = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->scene)
		return (1);
	if (mlx_image_to_window(game->mlx, game->scene, 0, 0) == -1)
		return (1);
	game->minimap_img = mlx_new_image(game->mlx, MINIMAP_SIZE, MINIMAP_SIZE);
	if (!game->minimap_img)
		return (1);
	if (mlx_image_to_window(game->mlx, game->minimap_img, 10, 10) == -1)
		return (1);
	return (0);
}
