#include "cub3d.h"

static int	load_resize(t_game *game, char *path, mlx_image_t **img)
{
	mlx_texture_t	*txt = mlx_load_png(path);

	if (!txt)
		return (err_msg(ERR_TEXTURE), 1);
	*img = mlx_texture_to_image(game->mlx, txt);
	if (!img)
		return (err_msg("IMAGE TO TEXTURE DEAD \n"), 1);
	if (!mlx_resize_image(*img, TEX_SIZE, TEX_SIZE))
		return (err_msg("RESIZE DEAD \n"), 1);
	mlx_delete_texture(txt);
	return (0);
}

int	upload_wall_textures(t_game *game)
{
	if (load_resize(game, game->no_path, &game->img[NORTH]))
		return (1);
	if (load_resize(game, game->so_path, &game->img[SOUTH]))
		return (1);
	if (load_resize(game, game->we_path, &game->img[WEST]))
		return (1);
	if (load_resize(game, game->ea_path, &game->img[EAST]))
		return (1);
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
