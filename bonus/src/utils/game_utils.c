#include "cub3d.h"

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

unsigned int	custom_rand(unsigned int *seed)
{
	struct timeval	tv;

	if (*seed == 0)
	{
		gettimeofday(&tv, NULL);
		*seed = tv.tv_sec ^ tv.tv_usec;
	}
	*seed = *seed * 1103515245 + 12345;
	return ((*seed >> 16) & 0x7FFF);
}
