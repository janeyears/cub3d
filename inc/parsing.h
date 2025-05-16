#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

int	get_map(t_game *game, char *fname);
int	get_texture(t_game *game);
int	get_color(t_game *game);

int map_val(t_map *map);


#endif