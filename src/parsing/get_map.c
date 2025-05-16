
# include "cub3d.h"

static int	config(t_game *game)
{
	if (get_texture(game) < 0)
		return (-1);
	if (get_color(game) < 0)
		return (-1);
	return (1);
}

static int	read_map(t_map **map, char *fname)
{
	int		fd;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (err_msg(ERR_OPEN), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (lstadd(map, line) < 0)
			return (err_msg(ERR_MALLOC), -1);
		free(line);
	}
	close(fd);
	return (1);
}

int	get_map(t_game *game, char *fname)
{
	if (!fname || file_check(fname))
		return (err_msg(ERR_NOTCUB), -1);
	game->map = NULL;
	if (read_map(&game->map, fname) < 0)
		return (err_msg(ERR_OPEN), -1); // FREE MAP FUNCTION
	game->size_y = lstsize(game->map) -1;
	if (config(game) < 0)
		return (-1);					// FREE MAP FUNCTION
	if (map_val(game->map) < 0)
		return (-1);					// FREE MAP FUNCTION
	return (1);
}


// The map must be composed of only 6 possible characters: 0 for an empty space,
// 1 for a wall, and N,S,E or W for the player’s start position and spawning
// orientation


// The map must be closed/surrounded by walls, if not the program must return
// an error.
// ◦ Except for the map content, each type of element can be separated by one or
// more empty line(s).
// ◦ Except for the map content which always has to be the last, each type of
// element can be set in any order in the file.
// ◦ Except for the map, each type of information from an element can be separated
// by one or more space(s).
// ◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
// map and are up to you to handle. You must be able to parse any kind of map,
// as long as it respects the rules of the map.