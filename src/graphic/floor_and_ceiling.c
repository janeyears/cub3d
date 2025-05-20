
#include "cub3d.h"

void get_color_code(t_game *game)
{
	game->color_c = (game->ceiling[0] << 24)
					| (game->ceiling[1] << 16)
					| (game->ceiling[2] << 8) | 0xFF;
	game->color_f = (game->floor[0] << 24)
					| (game->floor[1] << 16)
					| (game->floor[2] << 8) | 0xFF;
}

void render_f_and_c(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < 300)
				mlx_put_pixel(game->img->img, x, y, game->color_c);
			else
				mlx_put_pixel(game->img->img, x, y, game->color_f);
			x++;
		}
		y++;
	}
}
