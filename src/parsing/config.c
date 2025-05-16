
# include "cub3d.h"

int	get_texture(t_game *game)
{
	skip_new_line(&game->map);
	if (!ft_strncmp(game->map->content, "NO \0", 4))
		return (err_msg("Wrong map configutration\n"), -1);
	else
		game->no_path = ft_substr(game->map->content, 3, ft_strlen(game->map->content) - 4);
	lst_del_first(&game->map);
	if (!ft_strncmp(game->map->content, "SO \0", 4))
		return (err_msg("Wrong map configutration\n"), -1);
	else
		game->so_path = ft_substr(game->map->content, 3, ft_strlen(game->map->content) - 4);
	lst_del_first(&game->map);
	if (!ft_strncmp(game->map->content, "WE \0", 4))
		return (err_msg("Wrong map configutration\n"), -1);
	else
		game->we_path = ft_substr(game->map->content, 3, ft_strlen(game->map->content) - 4);
	lst_del_first(&game->map);
	if (!ft_strncmp(game->map->content, "EA \0", 4))
		return (err_msg("Wrong map configutration\n"), -1);
	else
		game->ea_path = ft_substr(game->map->content, 3, ft_strlen(game->map->content) - 4);
	lst_del_first(&game->map);
	return (1);
}

int	get_color(t_game *game)
{
	skip_new_line(&game->map);
	if (!ft_strncmp(game->map->content, "F \0", 4))
		return (err_msg("Wrong map configutration\n"), -1);
	else
		game->ceiling_str = ft_substr(game->map->content, 2, ft_strlen(game->map->content) - 3);
	lst_del_first(&game->map);
	if (!ft_strncmp(game->map->content, "F \0", 4))
		return (err_msg("Wrong map configutration\n"), -1);
	else
		game->floor_str = ft_substr(game->map->content, 2, ft_strlen(game->map->content) - 3);
	lst_del_first(&game->map);
	skip_new_line(&game->map);
	return (1);
}