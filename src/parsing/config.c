
#include "cub3d.h"

int	get_path(t_list *map, char **path, char *prefix)
{
	printf("%s\n", *path);
	if (*path)
		return (err_msg(ERR_TWOID), -1);
	if (ft_strncmp(map->content, prefix, 3))
		return (err_msg(ERR_IDENT), -1);
	*path = ft_substr(map->content, skip_spaces(map->content) + 3, ft_strlen(map->content) - 4);
	if (!*path)
		return (-1);
	return (1);
}

int	*set_color(char *str)
{
	int		*colors;
	char	num[3];
	int		i;
	int		j;
	int		k;

	colors = ft_calloc(3, sizeof(int));
	if (!colors)
		return (err_msg(ERR_MALLOC), NULL);
	i = 0;
	k = 0;
	while (str[i] && k < 3)
	{
		if (str[i] == ',')
			i++;
		i += skip_spaces(&str[i]);
		if (!ft_isdigit(str[i]))
			return (free(colors), err_msg(ERR_RGBFORMAT), NULL);
		j = 0;
		while (ft_isdigit(str[i]))
		{
			if (j > 2)
				return (free(colors), err_msg(ERR_RGBRANGE), NULL);
			num[j++] = str[i++];
		}
		colors[k] = ft_atoi(num);
		if (colors[k] < 0 || colors[k] > 255)
			return (free(colors), err_msg(ERR_RGBRANGE), NULL);
		ft_memset(num, 0, 3);
		if (str[i] == '\0')
			break ;
		i++;
		k++;
	}
	i--;
	i += skip_spaces(&str[i]);
	if (str[i] && str[i + 1] && ft_isdigit(str[i + 1]))
		return (free(colors), err_msg(ERR_RGB), NULL);
	if (str[i] && !(str[i] == '\n' || str[i] == '\0'))
		return (free(colors), err_msg(ERR_IDENT), NULL);
	return (colors);
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

int	parse_color(t_list **curr, const char *prefix, int **target)
{
	if (*target)
		return (err_msg(ERR_TWOID), -1);
	if (!ft_strncmp((*curr)->content, prefix, ft_strlen(prefix)))
	{
		*target = set_color((*curr)->content + ft_strlen(prefix));
		if (!*target)
			return (-1);
		return (1);
	}
	return (0);
}
