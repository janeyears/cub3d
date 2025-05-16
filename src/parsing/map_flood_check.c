/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:39:51 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/02/13 15:27:05 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count(t_map *map, char c)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map->field[y])
	{
		x = 0;
		while (map->field[y][x])
		{
			if (map->field[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	get_position(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->field[y])
	{
		x = 0;
		while (map->field[y][x])
		{
			if (map->field[y][x] == 'P')
			{
				map->pos.x = x;
				map->pos.y = y;
			}
			if (map->field[y][x] == 'E')
			{
				map->exit_pos.x = x;
				map->exit_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	fill_pos(t_map *map)
{
	map->hero = count(map, 'P');
	map->col = count(map, 'C');
	map->exit = count(map, 'E');
	get_position(map);
}

void	flood_check(t_map *map, int x, int y, t_point *content)
{
	if (map->field[y][x] == 'E')
		content->y -= 1;
	if (map->field[y][x] == 'C')
		content->x -= 1;
	map->field[y][x] = '1';
	if (y > 0 && map->field[y - 1][x] != '1')
		flood_check(map, x, y - 1, content);
	if (y < (map->size.y - 2) && map->field[y + 1][x] != '1')
		flood_check(map, x, y + 1, content);
	if (x < (map->size.x - 2) && map->field[y][x + 1] != '1')
		flood_check(map, x + 1, y, content);
	if (x > 0 && map->field[y][x - 1] != '1')
		flood_check(map, x - 1, y, content);
}
