/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:06 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:17:07 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3d.h"

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_player
{
	double			x;
	double			y;
	char			pov;
	double			angle;
}	t_player;

typedef struct s_ray
{
	double			hit_x;
	double			hit_y;
	double			dist;
	bool			hit_vert;
	int				dir;
}	t_ray;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	t_player		*player;
	t_ray			*rays;
	mlx_image_t		*scene;
	mlx_image_t		*img[4];
	int				size_x;
	int				size_y;
	int				color_f;
	int				color_c;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				prev_mouse_x;
	int				mouse_initialized;
}	t_game;

#endif
