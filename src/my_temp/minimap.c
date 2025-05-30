
#include "cub3d.h"

void	put_pixel_safe(mlx_image_t *img, int x, int y, uint32_t color)
{
	if (x >= 0 && y >= 0 && x < (int)img->width && y < (int)img->height)
		mlx_put_pixel(img, x, y, color);
}

void	put_minimap(t_game *game)
{
	int		center_x = MINIMAP_RADIUS;
	int		center_y = MINIMAP_RADIUS;
	int		dy;
	int		dx;
	float	map_x = 0;
	float	map_y = 0;
	int		tile_x = 0;
	int		tile_y = 0;
	uint32_t color;

	dy = -MINIMAP_RADIUS;
	while (dy < MINIMAP_RADIUS)
	{
		dx = -MINIMAP_RADIUS;
		while (dx < MINIMAP_RADIUS)
		{
			if (dx*dx + dy*dy > MINIMAP_RADIUS * MINIMAP_RADIUS)
			{
				dx++;
				continue;
			}
			map_x = game->player->x / TILE_SIZE + dx / (float)MINIMAP_SCALE;
			map_y = game->player->y / TILE_SIZE + dy / (float)MINIMAP_SCALE;
			if (map_x >= 0)
				tile_x = (int)map_x;
			else
				tile_x = (int)floorf(map_x); // Allowed floorf? tile_x = (int)map_x;
			if (map_y >= 0)
				tile_y = (int)map_y; // Allowed floorf? tile_y = (int)map_y;
			else
				tile_y = (int)floorf(map_y);
			if (tile_y >= 0 && tile_y < game->size_y && tile_x >= 0 && tile_x < game->size_x)
			{
				if (game->map[tile_y][tile_x] == '1')
					color = 0x444444FF;
				else if (if_inside(game->map[tile_y][tile_x]))
					color = 0xAAAAAAFF;
				else
					color = 0x00000000;
				put_pixel_safe(game->minimap_img, center_x + dx, center_y + dy, color);
			}
			dx++;
		}
		dy++;
	}
}

void	clean_minimap(t_game *game)
{
	int		x = 0;
	int		y = 0;

	while (y < MINIMAP_SIZE)
	{
		x = 0;
		while (x < MINIMAP_SIZE)
		{
			mlx_put_pixel(game->minimap_img, x, y, 0x00000000);  // Black background
			x++;
		}
		y++;
	}
}

void	draw_minimap(void *param)
{
	int		center_x = MINIMAP_RADIUS;
	int		center_y = MINIMAP_RADIUS;
	int	dy;
	int	dx;
	t_game *game;

	game = (t_game *)param;

	// Clear minimap
	clean_minimap(game);
	// Draw map minimap
	put_minimap(game);

	// Draw green dot for player
	dy = -4;
	while (dy <= 4)
	{
		dx = -4;
		while (dx <= 4)
		{
			if (dx*dx + dy*dy <= 16)
				put_pixel_safe(game->minimap_img, center_x + dx, center_y + dy, 0x00FF00FF);
			dx++;
		}
		dy++;
	}
}
