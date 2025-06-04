
#include "cub3d.h"


// Проверка стены по координатам
// bool is_wall(t_game *game, float x, float y)
// {
// 	int mx = (int)(x / TILE_SIZE);
// 	int my = (int)(y / TILE_SIZE);

// 	if (mx < 0 || mx >= game->size_x || my < 0 || my >= game->size_y)
// 		return true; // Out of bounds = wall

// 	return (game->map[my][mx] != 0);
// }

// Ray direction functions for SCREEN COORDINATES
// bool ray_facing_right(float angle) {
//     return cos(angle) > 0;
// }

// bool ray_facing_left(float angle) {
//     return cos(angle) < 0;
// }

// // In screen coordinates: Y increases downward
// bool ray_facing_down(float angle) {
//     return sin(angle) > 0;  // Positive sin = moving down in screen coords
// }

// bool ray_facing_up(float angle) {
//     return sin(angle) < 0;  // Negative sin = moving up in screen coords
// }

// bool ray_facing_down(float angle) { return angle > 0 && angle < M_PI; }
// bool ray_facing_up(float angle) { return !ray_facing_down(angle); }
// bool ray_facing_right(float angle) { return angle < 0.5*M_PI || angle > 1.5*M_PI; }
// bool ray_facing_left(float angle) { return !ray_facing_right(angle); }
// Горизонтальные пересечения
// t_ray	horizontal_intersection(t_game *game, t_player *player, float angle)
// {
// 	t_ray ray;
// 	ray.hit_x = 0;
// 	ray.hit_y = 0;
// 	ray.dist = 1000000; // очень большое число
// 	ray.hit_vert = false;

// 	float	y_horz, x_horz;
// 	float	y_step, x_step;

// 	// 1. Найти первую горизонтальную линию
// 	y_horz = floor(player->y / TILE_SIZE) * TILE_SIZE;
// 	if (ray_facing_down(angle))
// 		y_horz += TILE_SIZE;

// 	// 2. Найти x
// 	x_horz = player->x + (y_horz - player->y) / tan(angle);

// 	// 3. Шаги
// 	y_step = TILE_SIZE;
// 	if (ray_facing_up(angle))
// 		y_step = -TILE_SIZE;

// 	x_step = TILE_SIZE / tan(angle);
// 	if ((ray_facing_left(angle) && x_step > 0) || (ray_facing_right(angle) && x_step < 0))
// 		x_step = -x_step;

// 	// 4. Перемещаемся по горизонтальным линиям, пока не найдём стену
// 	while (x_horz >= 0 && x_horz < game->size_x * TILE_SIZE &&
// 		y_horz >= 0 && y_horz < game->size_y * TILE_SIZE)
// 	{
// 		// Проверяем точку чуть выше/ниже линии (зависит от направления)
// 		float check_y = y_horz + (ray_facing_up(angle) ? -1 : 0);
// 		if (is_wall(game, x_horz, check_y))
// 		{
// 			ray.hit_x = x_horz;
// 			ray.hit_y = y_horz;
// 			ray.dist = hypot(ray.hit_x - player->x, ray.hit_y - player->y);
// 			return ray;
// 		}
// 		x_horz += x_step;
// 		y_horz += y_step;
// 	}

// 	return ray; // Если не нашли стену — вернём дальнюю точку
// }

t_ray vertical_intersection(t_game *game, t_player *player, float angle)
{
	t_ray ray = {0};
	ray.dist = 1000000;
	ray.hit_vert = true;

	if (fabs(cos(angle)) < 0.0001)
		return ray;

	float dx = cos(angle) > 0 ? TILE_SIZE : -TILE_SIZE;
	float dy = dx * tan(angle);
		
	float x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (cos(angle) > 0) x += TILE_SIZE;
	float y = player->y + (x - player->x) * tan(angle);

	for (int i = 0; i < game->size_x + game->size_y; i++)
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

		x += dx;
		y += dy;
	}
	return ray;
}

t_ray horizontal_intersection(t_game *game, t_player *player, float angle)
{
	t_ray ray = {0};
	ray.dist = 1000000;
	ray.hit_vert = false;

	if (fabs(sin(angle)) < 0.0001)
		return ray;
	float dy = sin(angle) > 0 ? TILE_SIZE : -TILE_SIZE;
	float dx = dy / tan(angle);
		
	float y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (sin(angle) > 0) y += TILE_SIZE;
	float x = player->x + (y - player->y) / tan(angle);

	for (int i = 0; i < game->size_x + game->size_y; i++)
	{
		int map_x = (int)(x / TILE_SIZE);
		int map_y = (int)(y / TILE_SIZE);
		if (sin(angle) < 0) map_y--;

		if (map_x < 0 || map_x >= game->size_x || map_y < 0 || map_y >= game->size_y)
			break;

		if (game->map[map_y][map_x] == '1')
		{
			ray.hit_x = x;
			ray.hit_y = y;
			ray.dist = hypot(x - player->x, y - player->y);
			return ray;
		}

		x += dx;
		y += dy;
	}
	return ray;
}

// Вертикальные пересечения
// t_ray vertical_intersection(t_game *game, t_player *player, float angle)
// {
// 	t_ray ray;
// 	ray.hit_x = 0;
// 	ray.hit_y = 0;
// 	ray.dist = 1000000;
// 	ray.hit_vert = true;

// 	float x_vert, y_vert;
// 	float x_step, y_step;

// 	// 1. Найти первую вертикальную линию
// 	x_vert = floor(player->x / TILE_SIZE) * TILE_SIZE;
// 	if (ray_facing_right(angle))
// 		x_vert += TILE_SIZE;

// 	// 2. Найти y
// 	y_vert = player->y + (x_vert - player->x) * tan(angle);

// 	// 3. Шаги
// 	x_step = TILE_SIZE;
// 	if (ray_facing_left(angle))
// 		x_step = -TILE_SIZE;

// 	y_step = TILE_SIZE * tan(angle);
// 	if ((ray_facing_up(angle) && y_step > 0) || (ray_facing_down(angle) && y_step < 0))
// 		y_step = -y_step;

// 	// 4. Перемещаемся по вертикальным линиям
// 	while (x_vert >= 0 && x_vert < game->size_x * TILE_SIZE &&
// 		y_vert >= 0 && y_vert < game->size_y * TILE_SIZE)
// 	{
// 		// Проверяем точку чуть левее/правее линии
// 		float check_x;
// 		if (ray_facing_left(angle))
// 			check_x = x_vert - 1;
// 		else 
// 			check_x = x_vert;
// 		if (is_wall(game, check_x, y_vert))
// 		{
// 			ray.hit_x = x_vert;
// 			ray.hit_y = y_vert;
// 			ray.dist = hypot(ray.hit_x - player->x, ray.hit_y - player->y);
// 			return ray;
// 		}
// 		x_vert += x_step;
// 		y_vert += y_step;
// 	}

// 	return ray;
// }


// Основная функция raycast с выбором ближайшего пересечения
t_ray raycast(t_game *game, t_player *player, float angle)
{
	t_ray horz = horizontal_intersection(game, player, angle);
	t_ray vert = vertical_intersection(game, player, angle);

	if (horz.dist < vert.dist)
		return horz;
	return vert;
}

// Тест
// void	raycasting(t_game *game)
// {
// 	// float	angle_deg = 30;
// 	// float	angle = angle_deg * M_PI / 180.0f;
// 	int		i = 0;

// 	free(game->rays); 
// 	game->rays = ft_calloc(WIDTH, sizeof(t_ray));
// 	while (i < WIDTH)
// 	{
// 		float ray_angle = game->player->angle - (FOV / 2) + ((float)i / WIDTH) * FOV;
// 		game->rays[i] = raycast(game, game->player, ray_angle);
// 		i++;
// 	}
// 	printf("Raycasting complete. dist: %f, hit_x: %f, hit_y: %f\n",
// 		game->rays[0].dist, game->rays[0].hit_x, game->rays[0].hit_y);
// }

