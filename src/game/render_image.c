

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
	
	ft_memset(game->scene->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));

	for (int x = 0; x < WIDTH; x++)
	{
		// Calculate ray angle for this column
		float ray_angle = game->player->angle - (FOV / 2.0f)
						+ ((float)x / WIDTH) * FOV;

		// Avoid division by zero in tan()
		if (fabs(tan(ray_angle)) < 0.0001f)
			ray_angle += 0.0001f;
		normalize_angle(&ray_angle);
		
		ray = raycast(game, game->player, ray_angle);
		// Fish-eye correction
		float angle_diff = ray_angle - game->player->angle;
		normalize_angle(&angle_diff);
		if (angle_diff > M_PI)
			angle_diff -= 2 * M_PI;
		float corrected_dist = ray.dist * cos(angle_diff);
		if (corrected_dist < 1.0f)
			corrected_dist = 1.0f;
		
		// Simplified wall height calculation
		int wall_height = (int)(HEIGHT / corrected_dist);
		
		// Calculate wall boundaries
		int start = (HEIGHT / 2) - (wall_height / 2);
		int end = start + wall_height;

		// Draw vertical line
		for (int y = start; y < end; y++)
		{
			if (y >= 0 && y < HEIGHT)
			{
				if (ray.hit_vert)
					mlx_put_pixel(game->scene, x, y, 0xAAAAAAFF); 
				else
					mlx_put_pixel(game->scene, x, y, 0xFFFFFFFF);
			}
		}
	}
	// ray = raycast(game, game->player, game->player->angle);
	// printf("dist = %.2f\n", ray.dist);
}
