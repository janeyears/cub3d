#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

typedef struct s_rgb
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
}	t_rgb;


typedef struct s_map
{
	char			*content; // t_list
	int				size_x;			// lenght of each line of map
	struct s_map	*next;
}	t_map;

typedef struct s_img
{
	mlx_image_t		*img;
	char			*address;
	int				width;
	int				height;
}	t_img;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	void			*window;
	t_map			*map;
	int				size_y; // list size and number of rows
	t_rgb			ceiling;
	t_rgb			floor;
	char*			ceiling_str;
	char*			floor_str;
	char*			no_path;
	char*			so_path;
	char*			we_path;
	char*			ea_path;
}	t_game;

#endif
