#include "cub3d.h"

mlx_image_t *upload_image(t_game *game, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		err_msg(ERR_TEXTURE);
		return (NULL);
	}
	image = mlx_texture_to_image(game->mlx, texture);
	if (!image)
	{
		err_msg(ERR_IMAGE);
		mlx_delete_texture(texture);
		return (NULL);
	}
	mlx_delete_texture(texture);
	return (image);
}

int	rerender_image(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	game->wall = ft_calloc(1, sizeof(t_img));
	if (!game->img)
		return (1);
	game->img->img = mlx_new_image(game->mlx, 800, 600);
	if (!game->img->img)
		return (1);
	render_f_and_c(game);
	if (mlx_image_to_window(game->mlx, game->img->img, 0, 0) == -1)
		return (1);
	game->wall->img = upload_image (game, "textures/dogs.png");
	if (!game->wall->img)
		return (1);
	if (mlx_image_to_window(game->mlx, game->wall->img, 200, 200)== -1)
		return (1);
	return (0);
}
