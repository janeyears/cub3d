/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:16:34 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 12:24:55 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	file_check(char *fname)
{
	return (!ft_strchr(fname, '.')
		|| ft_strncmp((ft_strrchr(fname, '.')), ".cub\0", 5));
}

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	is_map(const char *curr)
{
	int	i;

	i = 0;
	while (curr[i])
	{
		if (curr[i] != '0' && curr[i] != '1'
			&& curr[i] != ' ' && curr[i] != 'N'
			&& curr[i] != 'S' && curr[i] != 'E'
			&& curr[i] != 'W' && curr[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_fill(t_game *game)
{
	if (!game->no_path || !game->so_path || !game->we_path || !game->no_path
		|| !game->ea_path || game->color_f == -1 || game->color_c == -1)
		return (err_msg(ERR_MISSID), -1);
	return (0);
}

long long	ft_atol(const char *str)
{
	size_t		i;
	int			sign;
	long long	num;

	num = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
