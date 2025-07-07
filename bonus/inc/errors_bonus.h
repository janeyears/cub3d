/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:14:38 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:20:36 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

# include "cub3d_bonus.h"

# define ERR_USAGE "Usage: ./cub3d maps/map.cub\n"
# define ERR_MALLOC "Memory allocation has failed\n"
# define ERR_NOTCUB "Map is not a .cub file\n"

# define ERR_OPEN "Couldn't open and read the map\n"
# define ERR_IDENT "Invalid identifier in the map file\n"
# define ERR_TWOID "Duplicate of identifier has been found\n"
# define ERR_MISS "Missing \\n after identifier\n"

# define ERR_RGB "RGB should have 3 values\n"
# define ERR_RGBRANGE "RGB colors must be in range [0,255]\n"
# define ERR_RGBFORMAT "Invalid format of RGB colors\n"

# define ERR_WRONGPLAYER "Invalid map: No player or more than one player\n"
# define ERR_SYMBOL "Invalid symbol in the map\n"
# define ERR_SPACE "There are empty space in the map\n"
# define ERR_WALLS "The map is not surrounded by walls\n"
# define SMALL_MAP "Map is too small to add enemies\n"
# define ADD_ENEMY "Couldn't add enemy\n"

# define ERR_TEXTURE "Couldn't upload texture\n"
# define ERR_IMAGE "Couldn't convert texture to image\n"
# define ERR_RESIZE "Function mlx_resize has failed\n"
# define ERR_DISPLAY "Function mlx_image_to_window has failed\n"

# define ERR_SIZE "Game width or height is too big\n"
# define ERR_MLXINIT "mlx_init has failed\n"
# define ERR_MLXWIN "image_to_window has failed\n"
# define INIT_IMAGE "Function init_image has failed\n"

void	err_msg(char *msg);

#endif
