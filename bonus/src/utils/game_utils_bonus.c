/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:16:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:22:52 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

int	check_collision(t_game *game, double new_x, double new_y)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)(new_x / TILE_SIZE);
	tile_y = (int)(new_y / TILE_SIZE);
	check_enemy_collision(game, new_x, new_y);
	if (game->map[tile_y][tile_x] == '1')
		return (0);
	return (1);
}
