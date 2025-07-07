/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:35 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:18:36 by ekashirs         ###   ########.fr       */
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
