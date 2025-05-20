#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define WIDTH 800
# define HEIGHT 600

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
	int				width;
	int				height;
	int				endian;
}	t_img;

typedef struct s_game
{
	void			*mlx;
	t_img			*img;
	t_img			*wall;
	void			*window;
	t_map			*map;
	int				size_y; 	// list size and number of rows
	int				*ceiling;	// int array [red, green, blue]
	int				*floor;		// int array [red, green, blue]
	int				color_f;
	int				color_c;
	char*			no_path;
	char*			so_path;
	char*			we_path;
	char*			ea_path;
}	t_game;

#endif
