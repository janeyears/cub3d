/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:21 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 12:06:01 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_collision(t_game *game, double new_x, double new_y)
{
	int	tile_x;
	int	tile_y;

	tile_x = (int)((new_x - COLLISION_BUFFER) / TILE_SIZE);
	tile_y = (int)((new_y - COLLISION_BUFFER) / TILE_SIZE);
	if (game->map[tile_y][tile_x] == '1')
		return (0);
	tile_x = (int)((new_x + COLLISION_BUFFER) / TILE_SIZE);
	tile_y = (int)((new_y - COLLISION_BUFFER) / TILE_SIZE);
	if (game->map[tile_y][tile_x] == '1')
		return (0);
	tile_x = (int)((new_x - COLLISION_BUFFER) / TILE_SIZE);
	tile_y = (int)((new_y + COLLISION_BUFFER) / TILE_SIZE);
	if (game->map[tile_y][tile_x] == '1')
		return (0);
	tile_x = (int)((new_x + COLLISION_BUFFER) / TILE_SIZE);
	tile_y = (int)((new_y + COLLISION_BUFFER) / TILE_SIZE);
	if (game->map[tile_y][tile_x] == '1')
		return (0);
	return (1);
}
