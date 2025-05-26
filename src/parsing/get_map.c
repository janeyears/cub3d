
#include "cub3d.h"

static int	config(t_game *game, t_list **map)
{
	t_list	*curr;

	curr = *map;
	while (curr)
	{
		if (((char *)(curr)->content)[0] == '\n')
		{
			while (((char *)(curr)->content)[0] == '\n')
				lst_del_first(&curr);
		}
		if (!(ft_strncmp(curr->content, "NO ", 3)))
		{
			if (get_path(curr, &game->no_path, "NO ") < 0)
				return (-1);
		}
		else if (!(ft_strncmp(curr->content, "SO ", 3)))
		{
			if (get_path(curr, &game->so_path, "SO ") < 0)
				return (-1);
		}
		else if (!(ft_strncmp(curr->content, "WE ", 3)))
		{
			if (get_path(curr, &game->we_path, "WE ") < 0)
				return (-1);
		}
		else if (!(ft_strncmp(curr->content, "EA ", 3)))
		{
			if (get_path(curr, &game->ea_path, "EA ") < 0)
				return (-1);
		}
		else if (!(ft_strncmp(curr->content, "F ", 2)))
		{
			game->floor = set_color(&curr->content[2]);
			if (!game->floor)
				return (-1);
		}
		else if (!(ft_strncmp(curr->content, "C ", 2)))
		{
			game->ceiling = set_color(&curr->content[2]);
			if (!game->ceiling)
					return (-1);
		}
		else
		{
			return (err_msg(ERR_IDENT), -1);
		}
		lst_del_first(&curr);
		if (game->no_path && game->so_path && game->we_path && game->ea_path && game->floor && game->ceiling)
			break ;
	}
	skip_new_line(&curr);
	*map = curr;
	return (1);
}

static int	read_map(t_list **map, char *fname)
{
	int		fd;
	char	*line;
	t_list	*new;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (err_msg(ERR_OPEN), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = lstnew_m(line);
		if (!new)
			return (err_msg(ERR_MALLOC), -1);
		ft_lstadd_back(map, new);
		free(line);
	}
	close(fd);
	return (1);
}

int	get_map(t_game *game, char *fname)
{
	t_list	*map;

	game->ceiling = NULL;
	game->floor = NULL;
	if (!fname || file_check(fname))
		return (err_msg(ERR_NOTCUB), -1);
	map = NULL;
	if (read_map(&map, fname) < 0)
		return (err_msg(ERR_OPEN), -1); // FREE MAP FUNCTION
	if (config(game, &map) < 0)
		return (-1);					// FREE MAP FUNCTION
	game->size_y = ft_lstsize(map);
	game->map = list_to_arr(map);
	ft_lstclear(&map, free);
	if (!game->map)
		return (err_msg(ERR_MALLOC), -1);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return (err_msg(ERR_MALLOC), -1); // FREE MAP FUNCTION
	if (composition(game) < 0)
		return (-1);
	if (map_val(game) < 0)
		return (-1);					// FREE MAP FUNCTION
	return (1);
}
