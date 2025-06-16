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

int upload_weapon_texture(t_game *game, char *path)
{
	int new_width;
	int new_height;
	int pos_x;
	int pos_y;
	mlx_texture_t *weapon_texture;

	weapon_texture = mlx_load_png(path);
	if (!weapon_texture)
		return (printf("Failed to load weapon texture\n"), 1);
	new_width = weapon_texture->width * 0.35;
	new_height = weapon_texture->height * 0.35;
	pos_x = (WIDTH - new_width) / 2;
	pos_y = HEIGHT - new_height;
	game->weapon_image = mlx_texture_to_image(game->mlx, weapon_texture);
	mlx_delete_texture(weapon_texture);
	if (!game->weapon_image)
		return (printf("Failed to create weapon image\n"), 1);
	if (!mlx_resize_image(game->weapon_image, new_width, new_height))
		return (printf("Failed to resize weapon image\n"), 1);
	if (mlx_image_to_window(game->mlx, game->weapon_image, pos_x, pos_y) == -1)
		return (printf("Failed to display weapon image\n"), 1);
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
	if (upload_weapon_texture(game, "textures/frog.png") != 0)
		return (1);
	return (0);
}
