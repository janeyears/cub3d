/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:15:11 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:15:14 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "cub3d_bonus.h"

# define MINIMAP_SCALE 10
# define MINIMAP_RADIUS 124
# define MINIMAP_SIZE 248

void	draw_minimap(void *param);
void	draw_counter(void *param);

void	mini_init(t_mini *mini);
void	clean_minimap(t_game *game);
void	put_dot(mlx_image_t *img, int x, int y, uint32_t color);
void	put_pixel_mini(t_game *game, t_mini mini);

#endif