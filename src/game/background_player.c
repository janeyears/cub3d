
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

void	get_player_pov(t_game **game)
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