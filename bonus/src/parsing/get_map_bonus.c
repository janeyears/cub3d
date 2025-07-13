/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:07 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/09 17:28:49 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	handle_line(t_game *game, t_list **curr)
{
	int	result;

	result = parse_texture(curr, "NO ", &game->no_path);
	if (result != 0)
		return (result);
	result = parse_texture(curr, "SO ", &game->so_path);
	if (result != 0)
		return (result);
	result = parse_texture(curr, "WE ", &game->we_path);
	if (result != 0)
		return (result);
	result = parse_texture(curr, "EA ", &game->ea_path);
	if (result != 0)
		return (result);
	result = parse_color(curr, "F ", &game->color_f);
	if (result != 0)
		return (result);
	result = parse_color(curr, "C ", &game->color_c);
	if (result != 0)
		return (result);
	return (-2);
}

static int	config(t_game *game, t_list **map)
{
	t_list	*curr;

	curr = *map;
	while (curr)
	{
		while (curr && ((char *)(curr->content))[0] == '\n')
			lst_del_first(&curr);
		if (is_map((char *)(curr->content)))
			break ;
		if (!curr)
		{
			*map = curr;
			return (err_msg(ERR_IDENT), -1);
		}
		if (handle_line(game, &curr) < 0)
		{
			*map = curr;
			return (-1);
		}
		lst_del_first(&curr);
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
		return (-1);
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

static int	init_game(t_game *game, char *fname)
{
	if (!fname || file_check(fname))
		return (err_msg(ERR_NOTCUB), -1);
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->player = NULL;
	game->color_f = -1;
	game->color_c = -1;
	game->map = NULL;
	game->size_x = 0;
	game->size_y = 0;
	return (0);
}

int	get_map(t_game *game, char *fname)
{
	t_list	*map;

	if (init_game(game, fname) < 0)
		return (-1);
	map = NULL;
	if (read_map(&map, fname) < 0)
		return (err_msg(ERR_OPEN), -1);
	if (config(game, &map) < 0)
		return (ft_lstclear(&map, free), free_parsing(game), -1);
	if (check_fill(game) < 0)
		return (ft_lstclear(&map, free), free_parsing(game), -1);
	game->size_y = ft_lstsize(map);
	game->map = list_to_arr(map);
	ft_lstclear(&map, free);
	if (!game->map)
		return (free_parsing(game), err_msg(ERR_MALLOC), -1);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return (err_msg(ERR_MALLOC), -1);
	if (composition(game) < 0)
		return (free_parsing(game), -1);
	if (map_val(game) < 0)
		return (free_parsing(game), -1);
	get_map_width(game);
	return (1);
}
