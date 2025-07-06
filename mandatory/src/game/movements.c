#include "cub3d.h"

static void	rotate_player(t_game *game, int direction)
{
	if (direction == LEFT)
		game->player->angle -= ROT_SPEED * game->mlx->delta_time;
	else if (direction == RIGHT)
		game->player->angle += ROT_SPEED * game->mlx->delta_time;
	if (game->player->angle < 0)
		game->player->angle += 2 * M_PI;
	else if (game->player->angle > 2 * M_PI)
		game->player->angle -= 2 * M_PI;
}

static int	check_collision(t_game *game, double new_x, double new_y)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)(new_x / TILE_SIZE);
	tile_y = (int)(new_y / TILE_SIZE);
	if (game->map[tile_y][tile_x] == '1')
		return (0);
	return (1);
}

static int	move_player_horiz(t_game *game, int direction)
{
	double	new_x;
	double	new_y;
	double	vector;

	if (direction == A)
	{
		vector = game->player->angle - M_PI_2;
		new_x = move_cos(game->player->x, vector, game->mlx->delta_time);
		new_y = move_sin(game->player->y, vector, game->mlx->delta_time);
	}
	else
	{
		vector = game->player->angle + M_PI_2;
		new_x = move_cos(game->player->x, vector, game->mlx->delta_time);
		new_y = move_sin(game->player->y, vector, game->mlx->delta_time);
	}
	if (check_collision(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
		return (0);
	}
	return (1);
}

static int	move_player_vertic(t_game *game, int direction)
{
	double	new_x;
	double	new_y;

	if (direction == W)
	{
		new_x = move_cos(game->player->x, game->player->angle,
				game->mlx->delta_time);
		new_y = move_sin(game->player->y, game->player->angle,
				game->mlx->delta_time);
	}
	else
	{
		new_x = game->player->x - cos(game->player->angle)
			* TILE_SIZE * game->mlx->delta_time;
		new_y = game->player->y - sin(game->player->angle)
			* TILE_SIZE * game->mlx->delta_time;
	}
	if (check_collision(game, new_x, new_y))
	{
		game->player->x = new_x;
		game->player->y = new_y;
		return (0);
	}
	return (1);
}

void	handle_mouse_rotation(t_game *game)
{
	int	mouse_x;
	int	mouse_y;
	int	delta_x;

	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	if (!game->mouse_initialized)
	{
		game->prev_mouse_x = mouse_x;
		game->mouse_initialized = 1;
		return ;
	}
	delta_x = mouse_x - game->prev_mouse_x;
	game->player->angle += delta_x * MOUSE_SENSITIVITY;
	if (game->player->angle < 0)
		game->player->angle += 2 * M_PI;
	else if (game->player->angle > 2 * M_PI)
		game->player->angle -= 2 * M_PI;
	game->prev_mouse_x = mouse_x;
}

void	handle_movement(t_game *game) // NEED REMOVE  PRINTFS
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		if (move_player_vertic(game, S) == 0)
			printf("Down key pressed.\n");
		else
			printf("Collision detected, cannot move down\n");
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		if (move_player_horiz(game, A) == 0)
			printf("Left key pressed.\n");
		else
			printf("Collision detected, cannot move left\n");
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		if (move_player_vertic(game, W) == 0)
			printf("Up key pressed.\n");
		else
			printf("Collision detected, cannot move up\n");
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		if (move_player_horiz(game, D) == 0)
			printf("Right key pressed\n");
		else
			printf("Collision detected, cannot move right\n");
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		rotate_player(game, LEFT);
		printf("Left arrow key pressed\n");
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		rotate_player(game, RIGHT);
		printf("Right arrow key pressed\n");
	}
}
