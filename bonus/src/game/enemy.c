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
			if (x < 0 || x >= WIDTH || enemy->distance > game->ray_dists[x]) // Enemy is behind wall skip it
				continue;
			y = enemy->draw_start_y - 1;
			while (++y < enemy->draw_end_y)
			{
				if (y < 0 || y >= HEIGHT)
					continue;
				tex_x = (x - enemy->draw_start_x) * frame->width / enemy->sprite_size;
				tex_y = (y - enemy->draw_start_y) * frame->height / enemy->sprite_size;
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
			continue;
		game->enemies[i].dx = game->enemies[i].x - game->player->x;
		game->enemies[i].dy = game->enemies[i].y - game->player->y;
		game->enemies[i].angle_en = atan2(game->enemies[i].dy, game->enemies[i].dx)
			- game->player->angle;
		norm_angle_en(game, i);
		if (fabs(game->enemies[i].angle_en) > FOV / 2) 				// skip if outside FOV
			continue;
		get_enemy_param(&game->enemies[i], proj_dist);
		draw_sprite(game, &game->enemies[i], game->anim[game->enemies[i].frame]);
	}
}

int	place_enemies(t_game *game)
{
	int				x;
	int				y;

	y = 0;
	while (y < game->size_y)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == '0')
			{
				if (((x * 17 + y * 23) & 0x7fffffff) % 100 < 5) // chance to place an enemy
				{
					game->map[y][x] = 'E';
					game->enemy_count++;
				}
			}
			x++;
		}
		y++;
	}
	if (get_enemy_coords(game) < 0)
		return (-1);
	game->enemy_left = game->enemy_count;
	return (1);
}
