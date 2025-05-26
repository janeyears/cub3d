#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

typedef struct s_player
{
	double		x;
	double		y;
	char		pov;
	double		angle;
}	t_player;

typedef struct s_game
{
	char		**map;
	t_player	*player;
	int			size_y; 	// list size and number of rows
	int			*ceiling;	// int array [red, green, blue]
	int			*floor;		// int array [red, green, blue]
	char*		no_path;
	char*		so_path;
	char*		we_path;
	char*		ea_path;
}	t_game;

#endif
