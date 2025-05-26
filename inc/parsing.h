#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		prew;
	int		next;
}	t_point;

typedef struct s_count
{
	int		player;
	bool	allowed;
}	t_count;

int		get_map(t_game *game, char *fname);
int		get_path(t_list *map, char **path, char *prefix);
int		*set_color(char *str);
// int		get_texture(t_game *game);
// int		get_color(t_game *game);

int		composition(t_game *game);
int		map_val(t_game *game);

#endif