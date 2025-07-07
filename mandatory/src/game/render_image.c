/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:58 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 15:12:18 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Cast a ray for a screen column, correct the fish-eye distortion,
calculate wall height and texture X coordinate*/
static t_column	prepare_column(t_game *game, float ray_angle, float proj_dist)
{
	t_column	col;
	float		correction;
	mlx_image_t	*img;

	col.ray = raycast(game, game->player, ray_angle);
	correction = col.ray.dist * cosf(ray_angle - game->player->angle);
	if (correction < MIN_DISTANCE)
		correction = MIN_DISTANCE;
	col.wall_height = (TILE_SIZE * proj_dist) / correction;
	col.wall_start = (HEIGHT - col.wall_height) / 2;
	col.wall_end = col.wall_start + col.wall_height;
	img = game->img[col.ray.dir];
	if (col.ray.dir == NORTH || col.ray.dir == SOUTH)
		col.tex_x = fmodf(col.ray.hit_x, TILE_SIZE) / TILE_SIZE * img->width;
	else
		col.tex_x = fmodf(col.ray.hit_y, TILE_SIZE) / TILE_SIZE * img->width;
	if (col.tex_x < 0)
		col.tex_x = 0;
	if ((uint32_t)col.tex_x >= img->width)
		col.tex_x = img->width - 1;
	return (col);
}

static int	get_column_color(t_game *game, t_column *col, int y)
{
	int	tex_y;
	int	tex_x;
	int	color;

	if (y < col->wall_start)
		return (game->color_c);
	else if (y < col->wall_end)
	{
		tex_y = (y - col->wall_start) * TEX_SIZE / col->wall_height;
		if (tex_y >= TEX_SIZE)
			tex_y = TEX_SIZE - 1;
		tex_x = col->tex_x;
		if (tex_x >= TEX_SIZE)
			tex_x = TEX_SIZE - 1;
		color = get_pixel_color(game->img[col->ray.dir], tex_x, tex_y);
		return (color);
	}
	else
		return (game->color_f);
}

/*Render a vertical column on the screen at position `x` by drawing
ceiling, wall (with texture), and floor pixels*/
static void	draw_column(t_game *game, int x, float ray_angle, float proj_dist)
{
	t_column	col;
	int			y;
	int			color;

	col = prepare_column(game, ray_angle, proj_dist);
	y = 0;
	while (y < HEIGHT)
	{
		color = get_column_color(game, &col, y);
		mlx_put_pixel(game->scene, x, y, color);
		y++;
	}
}

/*Render the entire 3D scene by casting rays for each screen column, 
calculating projection, and drawing the result*/
void	render_scene(t_game *game)
{
	float	proj_dist;
	float	ray_angle;
	int		x;

	ft_memset(game->scene->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	proj_dist = (WIDTH / 2.0f) / tan(FOV / 2.0f);
	x = 0;
	while (x < WIDTH)
	{
		ray_angle = game->player->angle - (FOV / 2.0f)
			+ ((float)x / WIDTH) * FOV;
		draw_column(game, x, ray_angle, proj_dist);
		x++;
	}
}
