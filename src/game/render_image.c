

#include "cub3d.h"

// Assuming texture->bytes_per_pixel == 4 (RGBA)
int get_pixel_color(mlx_texture_t *texture, int tex_x, int tex_y)
{
	uint32_t offset = (tex_y * texture->width + tex_x) * texture->bytes_per_pixel;

	uint8_t r = texture->pixels[offset + 0];
	uint8_t g = texture->pixels[offset + 1];
	uint8_t b = texture->pixels[offset + 2];
	uint8_t a = texture->pixels[offset + 3];

	// Combine RGBA into a single 32-bit color (MLX42 uses 0xRRGGBBAA format by default)
	return (r << 24) | (g << 16) | (b << 8) | a;
}


void render_scene(t_game *game)
{
	t_ray ray;
	
	ft_memset(game->scene->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));

	float distance_to_projection_plane = (WIDTH / 2.0f) / tan(FOV / 2.0f);
	for (int x = 0; x < WIDTH; x++)
	{
		// Calculate ray angle for this column
		float ray_angle = game->player->angle - (FOV / 2.0f)
						+ ((float)x / WIDTH) * FOV;

		// Avoid division by zero in tan()
		if (fabs(tan(ray_angle)) < 0.0001f)
			ray_angle += 0.0001f;
		
		ray = raycast(game, game->player, ray_angle);
		// Fish-eye correction
		float angle_diff = ray_angle - game->player->angle;
		float corrected_dist = ray.dist * cos(angle_diff);

		// Simplified wall height calculation
		float wall_height = (TILE_SIZE / corrected_dist) * distance_to_projection_plane; // NEW

		if (wall_height > HEIGHT) // NEW
			wall_height = HEIGHT; // NEW

		// float wall_height = (int)(HEIGHT / corrected_dist); // OLD
		int wall_top = HEIGHT / 2 - wall_height / 2;  // NEW
		int wall_bottom = HEIGHT / 2 + wall_height / 2;  // NEW
		
		// Calculate wall boundaries
		int start = (HEIGHT / 2) - (wall_height / 2);
		int end   = (HEIGHT / 2) + (wall_height / 2);

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

		int tex_x;

		if (ray.dir == 0 || ray.dir == 1)  // North or South (horizontal wall)
		{
			// Use x-position of hit to find offset in the texture
			tex_x = (int)(ray.hit_x) % TILE_SIZE;
		}
		else  // East or West (vertical wall)
		{
			// Use y-position of hit to find offset in the texture
			tex_x = (int)(ray.hit_y) % TILE_SIZE;
		}

		// Scale tex_x to match texture width
		tex_x = (tex_x * 640) / TILE_SIZE; // 640 size of texture image
		for (int y = 0; y < HEIGHT; y++)
		{
			if (y < wall_top)
			{
				// Draw ceiling pixel
				mlx_put_pixel(game->scene, x, y, game->color_c);
			}
			else if (y >= wall_top && y <= wall_bottom)
			{
				// Draw wall pixel (use texture or color)
				int tex_y = (y - wall_top) * 640 / wall_height;  // 640 size of texture image
				int tex_color = get_pixel_color(game->texture[ray.dir], tex_x, tex_y);
				mlx_put_pixel(game->scene, x, y, tex_color);  // tex_x depends on hit location
			}
			else
			{
				// Draw floor pixel
				mlx_put_pixel(game->scene, x, y, game->color_f);
			}
		}
	}
}
