
#include "cub3d.h"

// DDA

t_ray vertical_intersection(t_game *game, t_player *player, float angle)
{
	t_ray ray = {0};
	ray.dist = 1000000;
	ray.hit_vert = true;

	float x_step = cos(angle) > 0 ? TILE_SIZE : -TILE_SIZE;
	float y_step = x_step * tan(angle);

	float x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (cos(angle) > 0) x += TILE_SIZE;
	float y = player->y + (x - player->x) * tan(angle);

	while (1)
	{
		int map_x = (int)(x / TILE_SIZE);
		if (cos(angle) < 0) map_x--;
		int map_y = (int)(y / TILE_SIZE);

		if (map_x < 0 || map_x >= game->size_x || map_y < 0 || map_y >= game->size_y)
			break;

		if (game->map[map_y][map_x] == '1')
		{
			ray.hit_x = x;
			ray.hit_y = y;
			ray.dist = hypot(x - player->x, y - player->y);
			return ray;
		}
		x += x_step;
		y += y_step;
	}

	return ray;
}

// DDA

t_ray horizontal_intersection(t_game *game, t_player *player, float angle)
{
	t_ray ray = {0};
	ray.dist = 1000000;
	ray.hit_vert = false;

	float y_step = sin(angle) > 0 ? TILE_SIZE : -TILE_SIZE;
	float x_step = y_step / tan(angle);

	float y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (sin(angle) > 0) y += TILE_SIZE;
	float x = player->x + (y - player->y) / tan(angle);

	while (1)
	{
		int map_y = (int)(y / TILE_SIZE);
		if (sin(angle) < 0) map_y--;
		int map_x = (int)(x / TILE_SIZE);

		if (map_x < 0 || map_x >= game->size_x || map_y < 0 || map_y >= game->size_y)
			break;

		if (game->map[map_y][map_x] == '1')
		{
			ray.hit_x = x;
			ray.hit_y = y;
			ray.dist = hypot(x - player->x, y - player->y);
			return ray;
		}
		x += x_step;
		y += y_step;
	}

	return ray;
}

// Основная функция raycast с выбором ближайшего пересечения
t_ray raycast(t_game *game, t_player *player, float angle)
{
	t_ray horz;
	t_ray vert;

	horz = horizontal_intersection(game, player, angle);
	vert = vertical_intersection(game, player, angle);
	if (horz.dist < vert.dist)
	{
		if (sin(angle) > 0)
			horz.dir = 1;  // flip for South walls
		else
			horz.dir = 0; // flip for Noth walls
		return horz;
	}
	if (cos(angle) < 0)
		vert.dir = 2; // flip for West walls
	else
		vert.dir = 3; // flip for East walls
	return vert;
}
