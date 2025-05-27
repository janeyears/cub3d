

#include "cub3d.h"

void	rotate_player(t_game *game, int direction)
{
	if (direction == LEFT)
		game->player->angle -= ROT_SPEED * game->mlx->delta_time;
	else if (direction == RIGHT)
		game->player->angle += ROT_SPEED * game->mlx->delta_time;
	// Keep angle within [0, 2*PI] for consistency
	if (game->player->angle < 0)
		game->player->angle += 2 * M_PI;
	else if (game->player->angle > 2 * M_PI)
		game->player->angle -= 2 * M_PI;
}

int move_player_sideways(t_game *game, int direction)
{
	double new_x;
	double new_y;
	double vector;

	if (direction == A)
	{
		vector = game->player->angle - M_PI_2; // 90 degrees counter-clockwise
		new_x = game->player->x + cos(vector) * TILE_SIZE * game->mlx->delta_time; // MAYBE NOT TILE_SIZE
		new_y = game->player->y + sin(vector) * TILE_SIZE * game->mlx->delta_time; // MAYBE NOT TILE_SIZE
	}
	else if (direction == D)
	{
		vector = game->player->angle + M_PI_2; // 90 degrees clockwise
		new_x = game->player->x + cos(vector) * TILE_SIZE * game->mlx->delta_time; // MAYBE NOT TILE_SIZE
		new_y = game->player->y + sin(vector) * TILE_SIZE * game->mlx->delta_time; // MAYBE NOT TILE_SIZE
	}

	// CHECK COLLISION
}