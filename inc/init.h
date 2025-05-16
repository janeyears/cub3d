#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

typedef struct s_map
{
	char			*content; // t_list
	int				size_x;			// lenght of each line of map
	struct s_map	*next;
}	t_map;

typedef struct s_game
{
	t_map			*map;
	int				size_y; 	// list size and number of rows
	int				*ceiling;	// int array [red, green, blue]
	int				*floor;		// int array [red, green, blue]
	char*			no_path;
	char*			so_path;
	char*			we_path;
	char*			ea_path;
}	t_game;

#endif
