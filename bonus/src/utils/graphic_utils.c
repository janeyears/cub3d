#include "cub3d.h"

double	move_sin(double val, double vector, double time)
{
	return (val + sin(vector) * TILE_SIZE * time);
}

double	move_cos(double val, double vector, double time)
{
	return (val + cos(vector) * TILE_SIZE * time);
}

int	get_color_code(int *color)
{
	return ((color[0] << 24) |(color[1] << 16) | (color[2] << 8) | 0xFF);
}

static void	get_player_pov(t_game **game)
{
	if ((*game)->player->pov == 'E')
		(*game)->player->angle = EAST_POV;
	else if ((*game)->player->pov == 'N')
		(*game)->player->angle = NORTH_POV;
	else if ((*game)->player->pov == 'W')
		(*game)->player->angle = WEST_POV;
	else if ((*game)->player->pov == 'S')
		(*game)->player->angle = SOUTH_POV;
}

void	init_player(t_game *game)
{
	game->player->y = (game->player->y * TILE_SIZE) + (TILE_SIZE / 2);
	game->player->x = (game->player->x * TILE_SIZE) + (TILE_SIZE / 2);
	get_player_pov(&game);
}

int get_pixel_color(mlx_image_t *img, int tex_x, int tex_y)
{
	uint8_t *pixel = &img->pixels[(tex_y * img->width + tex_x) * 4];

	return ((pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3]);
}