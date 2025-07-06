#include "cub3d.h"

void	get_enemy_param(t_enemy *enemy, double proj_dist)
{
	enemy->distance = sqrt(enemy->dx * enemy->dx + enemy->dy * enemy->dy);
	enemy->sprite_size = (int)((TILE_SIZE * proj_dist) / enemy->distance);
	enemy->draw_start_y = (HEIGHT - enemy->sprite_size) / 2;
	enemy->draw_end_y = enemy->draw_start_y + enemy->sprite_size;
	enemy->draw_start_x = (WIDTH / 2) * (1 + tan(enemy->angle_en)
			/ tan(FOV / 2)) - enemy->sprite_size / 2;
	enemy->draw_end_x = enemy->draw_start_x + enemy->sprite_size;
}

void	draw_sprite(t_game *game, t_enemy *enemy, mlx_image_t *frame)
{
	int		x;
	int		y;
	int		tex_x;
	int		tex_y;
	int		color;

	x = enemy->draw_start_x - 1;
	while (++x < enemy->draw_end_x)
	{
		if (x < 0 || x >= WIDTH || enemy->distance > game->ray_dists[x])
			continue ;
		y = enemy->draw_start_y - 1;
		while (++y < enemy->draw_end_y)
		{
			if (y < 0 || y >= HEIGHT)
				continue ;
			tex_x = (x - enemy->draw_start_x) * frame->width
				/ enemy->sprite_size;
			tex_y = (y - enemy->draw_start_y) * frame->height
				/ enemy->sprite_size;
			color = get_pixel_color(frame, tex_x, tex_y);
			if ((color >> 24) & 0xFF)
				mlx_put_pixel(game->scene, x, y, color);
		}
	}
}

void	render_enemies(t_game *game)
{
	double	proj_dist;
	int		i;

	i = -1;
	proj_dist = (WIDTH / 2.0f) / tan(FOV / 2.0f);
	while (++i < game->enemy_count)
	{
		if (!game->enemies[i].alive)
			continue ;
		game->enemies[i].dx = game->enemies[i].x - game->player->x;
		game->enemies[i].dy = game->enemies[i].y - game->player->y;
		game->enemies[i].angle_en = atan2(game->enemies[i].dy,
				game->enemies[i].dx) - game->player->angle;
		norm_angle_en(game, i);
		if (fabs(game->enemies[i].angle_en) > FOV / 2)
			continue ;
		get_enemy_param(&game->enemies[i], proj_dist);
		draw_sprite(game, &game->enemies[i],
			game->anim[game->enemies[i].frame]);
	}
}

int	place_enemies(t_game *game)
{
	int				x;
	int				y;
	unsigned int	seed;

	y = -1;
	seed = 0;
	while (++y < game->size_y)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == '0')
			{
				if (custom_rand(&seed) % 100 < 10)
				{
					game->map[y][x] = 'E';
					game->enemy_count++;
				}
			}
			x++;
		}
	}
	if (get_enemy_coords(game) < 0)
		return (-1);
	return (1);
}

void	check_enemy_collision(t_game *game, double new_x, double new_y)
{
	int		tile_x;
	int		tile_y;
	int		enemy_tile_x;
	int		enemy_tile_y;
	int		i;

	i = -1;
	tile_x = (int)(new_x / TILE_SIZE);
	tile_y = (int)(new_y / TILE_SIZE);
	while (++i < game->enemy_count)
	{
		if (!game->enemies[i].alive)
			continue ;
		enemy_tile_x = (int)(game->enemies[i].x / TILE_SIZE);
		enemy_tile_y = (int)(game->enemies[i].y / TILE_SIZE);
		if (tile_x == enemy_tile_x && tile_y == enemy_tile_y)
		{
			game->enemies[i].alive = 0;
			game->enemy_left--;
			game->map[tile_y][tile_x] = '0';
		}
	}
}
