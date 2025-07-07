/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:15:40 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:15:41 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	load(t_game *game, char *path, mlx_image_t **img)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png(path);
	if (!txt)
		return (err_msg(ERR_TEXTURE), 1);
	*img = mlx_texture_to_image(game->mlx, txt);
	if (!img || !*img)
		return (err_msg(ERR_IMAGE), 1);
	mlx_delete_texture(txt);
	return (0);
}

static int	load_resize(t_game *game, char *path, mlx_image_t **img, int size)
{
	if (load(game, path, img))
		return (1);
	if (!mlx_resize_image(*img, size, size))
		return (err_msg(ERR_RESIZE), 1);
	return (0);
}

int	upload_wall_textures(t_game *game)
{
	if (load_resize(game, game->no_path, &game->img[NORTH], TEX_SIZE))
		return (1);
	if (load_resize(game, game->so_path, &game->img[SOUTH], TEX_SIZE))
		return (1);
	if (load_resize(game, game->we_path, &game->img[WEST], TEX_SIZE))
		return (1);
	if (load_resize(game, game->ea_path, &game->img[EAST], TEX_SIZE))
		return (1);
	if (load_resize(game, PATH_E1, &game->anim[0], TEX_SIZE))
		return (1);
	if (load_resize(game, PATH_E2, &game->anim[1], TEX_SIZE))
		return (1);
	if (load_resize(game, PATH_E3, &game->anim[2], TEX_SIZE))
		return (1);
	if (load_resize(game, PATH_E4, &game->anim[3], TEX_SIZE))
		return (1);
	if (load_resize(game, PATH_E5, &game->anim[4], TEX_SIZE))
		return (1);
	if (load_resize(game, PATH_E6, &game->anim[5], TEX_SIZE))
		return (1);
	if (load(game, PATH_COUNT, &game->counter_frame))
		return (1);
	return (0);
}

int	upload_weapon_texture(t_game *game, char *path)
{
	int				new_width;
	int				new_height;
	int				pos_x;
	int				pos_y;
	mlx_texture_t	*weapon_texture;

	weapon_texture = mlx_load_png(path);
	if (!weapon_texture)
		return (err_msg(ERR_TEXTURE), 1);
	new_width = weapon_texture->width * 0.35;
	new_height = weapon_texture->height * 0.35;
	pos_x = (WIDTH - new_width) / 2;
	pos_y = HEIGHT - new_height;
	game->weapon_image = mlx_texture_to_image(game->mlx, weapon_texture);
	mlx_delete_texture(weapon_texture);
	if (!game->weapon_image)
		return (err_msg(ERR_IMAGE), 1);
	if (!mlx_resize_image(game->weapon_image, new_width, new_height))
		return (err_msg(ERR_RESIZE), 1);
	if (mlx_image_to_window(game->mlx, game->weapon_image, pos_x, pos_y) == -1)
		return (err_msg(ERR_DISPLAY), 1);
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
	if (mlx_image_to_window(game->mlx, game->minimap_img, 10,
			HEIGHT - MINIMAP_RADIUS * 2 - 10) == -1)
		return (1);
	if (mlx_image_to_window(game->mlx, game->counter_frame,
			WIDTH - game->counter_frame->width - 10, 10) == -1)
		return (1);
	if (upload_weapon_texture(game, "textures/frog.png") != 0)
		return (1);
	return (0);
}
