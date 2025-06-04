

#include "cub3d.h"

void normalize_angle(float *angle)
{
	while (*angle < 0)
		*angle += 2 * M_PI;
	while (*angle >= 2 * M_PI)
		*angle -= 2 * M_PI;
}


void render_scene(t_game *game)
{

	t_ray ray;
	// 1. Очистим картинку (можно обнулять пиксели или просто перерисовать)
	ft_memset(game->scene->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	//free(game->rays); 
	//game->rays = ft_calloc(WIDTH, sizeof(t_ray));
	// 2. Пройдем по каждому столбцу экрана
	for (int x = 0; x < WIDTH; x++)
	{
		// 2.1. Угол луча
		float ray_angle = game->player->angle - (FOV / 2.0f)
						+ ((float)x / WIDTH) * FOV;

		if (fabs(tan(ray_angle)) < 0.0001f)
			ray_angle += 0.0001f; // or use a small epsilon
		normalize_angle(&ray_angle);
		// 2.2. Запускаем луч
		ray = raycast(game, game->player, ray_angle);
		//printf("dist = %.2f\n", ray.dist);
		// 2.3. "fish-eye" коррекция (опционально, но важно)

		float angle_diff = ray_angle - game->player->angle;
		angle_diff = fmod(angle_diff + 2 * M_PI, 2 * M_PI);
		if (angle_diff > M_PI)
			angle_diff -= 2 * M_PI;
		float corrected_dist = ray.dist * cos(angle_diff);
		if (corrected_dist < 1.0f)
			corrected_dist = 1.0f;
		// 2.4. Рассчитываем высоту полоски стены
		float dist_proj_plane = (WIDTH / 2.0f) / tan(FOV / 2.0f);
		int wall_height = (int)((TILE_SIZE / corrected_dist) * dist_proj_plane);
		// int wall_height = (int)((TILE_SIZE * HEIGHT) / corrected_dist);

		// 2.5. Вычисляем начало и конец рисуемой полоски
		int start = (HEIGHT / 2) - (wall_height / 2);
		int end = start + wall_height;

		// 2.6. Рисуем вертикальную линию (например, белую или серую)
		for (int y = start; y < end; y++)
		{
			if (y >= 0 && y < HEIGHT)
			{
				if (ray.hit_vert)
					mlx_put_pixel(game->scene, x, y, 0xAAAAAAFF); // Серый цвет для вертикальных стен
				else
					mlx_put_pixel(game->scene, x, y, 0xFFFFFFFF);
			}
		}
	}
	ray = raycast(game, game->player, game->player->angle);
	printf("dist = %.2f\n", ray.dist);
}
