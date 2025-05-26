#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define WIDTH 800
# define HEIGHT 600


# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_player
{
	double		x;
	double		y;
	char		pov;
	double		angle;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	char		**map;
	t_player	*player;
	mlx_image_t		*background;
	mlx_texture_t	*texture[4];
	int			size_y; 	// list size and number of rows
	int			*ceiling;	// int array [red, green, blue]
	int			*floor;		// int array [red, green, blue]
	int				color_f;
	int				color_c;
	char*		no_path;
	char*		so_path;
	char*		we_path;
	char*		ea_path;
}	t_game;

#endif
