/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:32 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/09 13:10:59 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

bool	if_inside(char c)
{
	return (c == '0' || is_player(c));
}

void	get_map_width(t_game *game)
{
	int	width;
	int	len;
	int	i;

	i = 0;
	width = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len > width)
			width = len;
		i++;
	}
	game->size_x = width;
}

void	set_player(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->player->pov = game->map[y][x];
}
