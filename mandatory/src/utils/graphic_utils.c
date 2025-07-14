/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:25 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 15:32:05 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	move_sin(double val, double vector, double time)
{
	return (val + sin(vector) * TILE_SIZE * time);
}

double	move_cos(double val, double vector, double time)
{
	return (val + cos(vector) * TILE_SIZE * time);
}

uint64_t	get_pixel_color(mlx_image_t *img, int tex_x, int tex_y)
{
	uint8_t	*pixel;

	pixel = &img->pixels[(tex_y * img->width + tex_x) * 4];
	return ((pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3]);
}

uint64_t	get_color_code(int *color)
{
	return (((uint64_t)color[0] << 24)
		| ((uint64_t)color[1] << 16)
		| ((uint64_t)color[2] << 8)
		| 0xFF);
}
