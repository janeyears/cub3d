/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:14:38 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/09 13:11:50 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_BONUS_H
# define ERRORS_BONUS_H

# include "cub3d_bonus.h"

# define ERR_USAGE "Usage: ./cub3d maps/map.cub"
# define ERR_MALLOC "Memory allocation has failed"
# define ERR_NOTCUB "Map is not a .cub file"

# define ERR_OPEN "Couldn't open and read the map"
# define ERR_IDENT "Invalid identifier in the map file"
# define ERR_TWOID "Duplicate of identifier has been found"
# define ERR_PATH "Invalid path to texture"

# define ERR_RGB "RGB should have 3 values"
# define ERR_RGBRANGE "RGB colors must be in range [0,255]"
# define ERR_RGBFORMAT "Invalid format of RGB colors"

# define ERR_WRONGPLAYER "Invalid map: No player or more than one player"
# define ERR_SYMBOL "Invalid symbol in the map"
# define ERR_WALLS "The map is not surrounded by walls"
# define SMALL_MAP "Map is too small to add enemies"
# define ADD_ENEMY "Couldn't add enemy"

# define ERR_TEXTURE "Couldn't upload texture"
# define ERR_IMAGE "Couldn't convert texture to image"
# define ERR_RESIZE "Function mlx_resize has failed"
# define ERR_DISPLAY "Function mlx_image_to_window has failed"

# define ERR_MLXINIT "mlx_init has failed"
# define INIT_IMAGE "Function init_image has failed"

void	err_msg(char *msg);

#endif
