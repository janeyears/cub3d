
# include "cub3d.h"

static int	get_path(t_game *game, char **path, char *prefix)
{
	if (ft_strncmp(game->map->content, prefix, 3))
		return (err_msg(ERR_IDENT), -1);
	*path = ft_substr(game->map->content, 3, ft_strlen(game->map->content) - 4);
	if (!game->no_path)
		return (-1);
	return (1);
}

int	get_texture(t_game *game)
{
	skip_new_line(&game->map);
	if (get_path(game, &game->no_path, "NO ") < 0)
		return (-1);
	lst_del_first(&game->map);
	if (get_path(game, &game->so_path, "SO ") < 0)
		return (-1);
	lst_del_first(&game->map);
	if (get_path(game, &game->we_path, "WE ") < 0)
		return (-1);
	lst_del_first(&game->map);
	if (get_path(game, &game->ea_path, "EA ") < 0)
		return (-1);
	lst_del_first(&game->map);
	if (game->map->content[0] != '\n')
		return (err_msg(ERR_MISS), -1);
	return (1);
}

static int	*set_color(char *str)
{
	int	*colors;
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

int	get_color(t_game *game)
{
	skip_new_line(&game->map);
	if (ft_strncmp(game->map->content, "F ", 2))
		return (err_msg(ERR_IDENT), -1);
	else
	{
		game->floor = set_color(&game->map->content[2]);
		if (!game->floor)
			return (-1);
	}
	lst_del_first(&game->map);
	if (ft_strncmp(game->map->content, "C ", 2))
		return (-1);
	else
	{
		game->ceiling = set_color(&game->map->content[2]);
		if (!game->ceiling)
				return (-1);
	}
	lst_del_first(&game->map);
	if (game->map->content[0] != '\n')
		return (err_msg(ERR_MISS), -1);
	skip_new_line(&game->map);
	return (1);
}