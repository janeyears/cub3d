
#include "cub3d.h"

int	get_path(t_list *map, char **path, char *prefix)
{
	
	if (ft_strncmp(map->content, prefix, 3))
		return (err_msg(ERR_IDENT), -1);
	*path = ft_substr(map->content, 3, ft_strlen(map->content) - 4);
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

	// skip spaces
	colors = ft_calloc(3, sizeof(int));
	if (!colors)
		return (err_msg(ERR_MALLOC), NULL);
	i = 0;
	k = 0;
	while (str[i] && k < 3)
	{
		j = 0;
		while (ft_isdigit(str[i]))
		{
			if (j > 2)
				return (err_msg(ERR_RGBRANGE), NULL);
			num[j++] = str[i++];
		}
		if (k < 2 && str[i] && str[i] != ',')
			return (err_msg(ERR_RGBFORMAT), NULL);
		if (k == 2 && str[i] && str[i] != '\n')
			return (err_msg(ERR_RGB), NULL);
		colors[k] = ft_atoi(num);
		if (colors[k] < 0 || colors[k] > 255)
			return (err_msg(ERR_RGBRANGE), NULL);
		ft_memset(num, 0, 3);
		i++;
		k++;
	}
	if (k != 3)
		return (err_msg(ERR_RGB), NULL);
	if (str[i] && str[i] != '\n')
		return (err_msg(ERR_IDENT), NULL);
	return (colors);
}

// remove new line at end of map

// ◦ Except for the map, each type of information from an element can be separated
// by one or more space(s).