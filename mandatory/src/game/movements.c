/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:50 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/08 15:30:50 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	handle_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player_vertic(game, S);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player_horiz(game, A);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player_vertic(game, W);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player_horiz(game, D);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, LEFT);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, RIGHT);
}
