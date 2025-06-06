

#include "cub3d.h"

static t_column	prepare_column(t_game *game, float ray_angle, float proj_dist)
{
	t_column	col;
	float		corrected_dist;

	col.ray = raycast(game, game->player, ray_angle);
	corrected_dist = col.ray.dist * cos(ray_angle - game->player->angle);
	if (corrected_dist < MIN_DISTANCE)
		corrected_dist = MIN_DISTANCE;
	col.wall_height = (TILE_SIZE * proj_dist) / corrected_dist;
	col.wall_start = (HEIGHT - col.wall_height) / 2;
	col.wall_end = col.wall_start + col.wall_height;
	if (col.ray.dir == 0 || col.ray.dir == 1)
		col.tex_x = ((int)col.ray.hit_x % TILE_SIZE) * TEX_SIZE / TILE_SIZE;
	else
		col.tex_x = ((int)col.ray.hit_y % TILE_SIZE) * TEX_SIZE / TILE_SIZE;
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

		color = get_pixel_color(game->texture[col->ray.dir], tex_x, tex_y);
		return (color);
	}
	else
		return (game->color_f);
}

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
		ray_angle = game->player->angle - (FOV / 2.0f) + ((float)x / WIDTH) * FOV;
		draw_column(game, x, ray_angle, proj_dist);
		x++;
	}
}
