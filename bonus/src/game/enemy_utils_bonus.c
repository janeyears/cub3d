/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:15:31 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/08 15:57:23 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	norm_angle_en(t_game *game, int i)
{
	if (game->enemies[i].angle_en > M_PI)
		game->enemies[i].angle_en -= 2 * M_PI;
	if (game->enemies[i].angle_en < -M_PI)
		game->enemies[i].angle_en += 2 * M_PI;
}

void	update_enemy_animation(t_game *game)
{
	int	i;

	i = 0;
	game->frame_count++;
	if (game->frame_count % 5 == 0)
	{
		while (i < game->enemy_count)
		{
			game->enemies[i].frame++;
			if (game->enemies[i].frame >= 6)
				game->enemies[i].frame = 0;
			i++;
		}
	}
}

void	sort_enemies(t_game *game)
{
	int		i;
	int		j;
	t_enemy	temp;

	i = 0;
	while (i < game->enemy_count - 1)
	{
		j = 0;
		while (j < game->enemy_count - i - 1)
		{
			if (game->enemies[j].dist < game->enemies[j + 1].dist)
			{
				temp = game->enemies[j];
				game->enemies[j] = game->enemies[j + 1];
				game->enemies[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	enemy_dist(t_game *game)
{
	int		i;
	float	dx;
	float	dy;

	i = 0;
	while (i < game->enemy_count)
	{
		dx = game->enemies[i].x - game->player->x;
		dy = game->enemies[i].y - game->player->y;
		game->enemies[i].dist = dx * dx + dy * dy;
		i++;
	}
}

int	get_enemy_coords(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	if (!game->enemy_count)
		return (err_msg(SMALL_MAP), -1);
	game->enemies = ft_calloc(game->enemy_count, sizeof(t_enemy));
	if (!game->enemies)
		return (err_msg(ADD_ENEMY), -1);
	y = -1;
	while (++y < game->size_y)
	{
		x = -1;
		while (++x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'E')
			{
				game->enemies[i].x = (x + 0.5) * TILE_SIZE;
				game->enemies[i].y = (y + 0.5) * TILE_SIZE;
				game->enemies[i++].alive = 1;
			}
		}
	}
	return (1);
}
