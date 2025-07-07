/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:16:02 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:16:03 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_path(t_list *map, char **path, char *prefix)
{
	if (*path)
		return (err_msg(ERR_TWOID), -1);
	if (ft_strncmp(map->content, prefix, 3))
		return (err_msg(ERR_IDENT), -1);
	*path = ft_substr(map->content, skip_spaces(map->content) + 3,
			ft_strlen(map->content) - 4);
	if (!*path)
		return (-1);
	return (1);
}

int	copy_num(char *str, int *i)
{
	char	sub[4];
	int		j;
	int		num;

	j = 0;
	*i += skip_spaces(&str[*i]);
	if (str[*i] == ',')
		(*i)++;
	*i += skip_spaces(&str[*i]);
	if (!ft_isdigit(str[*i]))
		return (err_msg(ERR_RGBFORMAT), -1);
	while (ft_isdigit(str[*i]))
		sub[j++] = str[(*i)++];
	sub[j] = '\0';
	num = ft_atoi(sub);
	if (num < 0 || num > 255 || j > 3)
		return (err_msg(ERR_RGBRANGE), -1);
	return (num);
}

int	set_color(char *str)
{
	int		colors[3];
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] && k < 3)
	{
		colors[k] = copy_num(str, &i);
		if (colors[k] < 0)
			return (-1);
		k++;
	}
	i += skip_spaces(&str[i]);
	if (str[i] && str[i + 1] && ft_isdigit(str[i + 1]))
		return (err_msg(ERR_RGB), -1);
	if (str[i] && !(str[i] == '\n' || str[i] == '\0'))
		return (err_msg(ERR_IDENT), -1);
	return (get_color_code(colors));
}

int	parse_texture(t_list **curr, char *prefix, char **target)
{
	if (!ft_strncmp((*curr)->content, prefix, ft_strlen(prefix)))
	{
		if (get_path(*curr, target, prefix) < 0)
			return (-1);
		return (1);
	}
	return (0);
}

int	parse_color(t_list **curr, const char *prefix, int *target)
{
	if (!ft_strncmp((*curr)->content, prefix, ft_strlen(prefix)))
	{
		if (*target)
			return (err_msg(ERR_TWOID), -1);
		*target = set_color((*curr)->content + ft_strlen(prefix));
		if (*target < 0)
			return (-1);
		return (1);
	}
	return (0);
}
