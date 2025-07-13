/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:35 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/09 17:01:28 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
