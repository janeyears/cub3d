/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:45:52 by mzhitnik          #+#    #+#             */
/*   Updated: 2025/02/15 12:51:41 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_map *copy, t_map *map)
{
	int	y;

	copy->field = (char **)ft_calloc(map->size.y, sizeof(char *));
	if (!copy->field)
		return ;
	copy->size.x = map->size.x;
	copy->size.y = map->size.y;
	copy->pos.x = map->pos.x;
	copy->pos.y = map->pos.y;
	y = 0;
	while (map->field[y])
	{
		copy->field[y] = ft_strdup(map->field[y]);
		if (!copy->field[y])
		{
			copy->field = NULL;
			return (free_map(copy));
		}
		y++;
	}
	copy->field[y] = NULL;
}

int	boder_check(t_map *map)
{
	t_point	pos;
	int		ind;

	pos.y = 0;
	while (pos.y < map->size.y - 2)
	{
		if (map->field[pos.y][0] != '1' ||
			map->field[pos.y][map->size.x - 2] != '1')
			return (1);
		pos.y++;
	}
	ind = 0;
	pos.x = 0;
	while (map->field[ind][pos.x])
	{
		if (map->field[ind][pos.x] != '1' && map->field[ind][pos.x] != '\n')
			return (1);
		pos.x++;
		if (pos.x == map->size.x)
		{
			ind = map->size.y - 2;
			pos.x = 0;
		}
	}
	return (0);
}

int	char_check(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->field[y])
	{
		x = 0;
		while (x < map->size.x - 2)
		{
			if (map->field[y][x] != '0' && map->field[y][x] != '1' &&
			map->field[y][x] != 'C' && map->field[y][x] != 'E' &&
			map->field[y][x] != 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	fill_check(t_map *map)
{
	t_point	content;
	t_map	*copy;

	fill_pos(map);
	if (char_check(map))
		return (5);
	if (boder_check(map) == 1)
		return (7);
	if (!(map->hero == 1 && map->exit == 1 && map->col > 0))
		return (8);
	content.x = map->col;
	content.y = map->exit;
	copy = (t_map *)ft_calloc(1, sizeof(t_map));
	copy_map(copy, map);
	if (!copy->field || !copy->field[0])
		return (2);
	flood_check(copy, copy->pos.x, copy->pos.y, &content);
	free_map(copy);
	if (content.x > 0 || content.y > 0)
		return (9);
	return (0);
}
