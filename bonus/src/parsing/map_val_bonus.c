/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:16:09 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:16:10 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_char(t_game *game, t_count *count)
{
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	size_y = game->size_y;
	y = 0;
	while (y < size_y)
	{
		x = 0;
		size_x = ft_strlen(game->map[y]) - 1;
		while (x < size_x)
		{
			if (is_player(game->map[y][x]))
			{
				set_player(game, x, y);
				count->player++;
			}
			if (!(if_inside(game->map[y][x]) || game->map[y][x] == '1'
				|| game->map[y][x] == ' '))
				count->allowed = false;
			x++;
		}
		y++;
	}
}

int	composition(t_game *game)
{
	t_count	count;

	count.player = 0;
	count.allowed = true;
	check_char(game, &count);
	if (count.player != 1)
		return (err_msg(ERR_WRONGPLAYER), -1);
	if (count.allowed == false)
		return (err_msg(ERR_SYMBOL), -1);
	return (1);
}

static bool	cell_check(char **map, t_point	p)
{
	if (map[p.y][p.x - 1] == ' ' || map[p.y][p.x - 1] == '\0'
			|| map[p.y][p.x + 1] == ' ' || map[p.y][p.x + 1] == '\0'
			|| map[p.y - 1][p.x] == ' ' || map[p.y - 1][p.x] == '\0'
			|| map[p.y + 1][p.x] == ' ' || map[p.y + 1][p.x] == '\0')
		return (false);
	if (map[p.y - 1][p.x - 1] == ' ' || map[p.y - 1][p.x - 1] == '\0'
			|| map[p.y - 1][p.x + 1] == ' ' || map[p.y - 1][p.x + 1] == '\0'
			|| map[p.y + 1][p.x - 1] == ' ' || map[p.y + 1][p.x - 1] == '\0'
			|| map[p.y + 1][p.x + 1] == ' ' || map[p.y + 1][p.x + 1] == '\0')
		return (false);
	return (true);
}

static int	map_val_loop(t_point p, char **copy)
{
	while (p.x < p.w)
	{
		if (if_inside(copy[p.y][p.x]) == true)
		{
			if (p.y == 0 || p.y == p.h - 1 || p.x == 0 || p.x == p.w)
				return (-1);
			p.prew = ft_strlen(copy[p.y - 1]);
			p.next = ft_strlen(copy[p.y + 1]);
			if (p.x >= p.prew || p.x >= p.next)
				return (-1);
			if (cell_check(copy, p) == false)
				return (-1);
		}
		p.x++;
	}
	return (1);
}

int	map_val(t_game *game)
{
	t_point	p;

	p.y = 0;
	p.h = game->size_y;
	while (p.y < p.h)
	{
		p.x = 0;
		p.prew = -1;
		p.next = -1;
		p.w = ft_strlen(game->map[p.y]);
		if (map_val_loop(p, game->map) < 0)
			return (err_msg(ERR_WALLS), -1);
		p.y++;
	}
	return (1);
}
