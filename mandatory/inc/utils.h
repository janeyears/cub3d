/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:35 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 12:24:20 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

// Parsing utils

int			file_check(char *fname);
int			skip_spaces(char *str);
void		free_arr(char **arr);
void		free_game(t_game *game);
void		free_parsing(t_game *game);
long long	ft_atol(const char *str);

// Linked list utils

t_list		*lstnew_m(void *content);
void		skip_new_line(t_list **map);
void		lst_del_first(t_list **lst);
char		**list_to_arr(t_list *list);

// Parsing utils

bool		if_inside(char c);
bool		is_player(char c);
void		set_player(t_game *game, int x, int y);
void		get_map_width(t_game *game);
int			is_map(const char *curr);
int			check_fill(t_game *game);

// Game utils

double		move_cos(double val, double vector, double time);
double		move_sin(double val, double vector, double time);
int			check_collision(t_game *game, double new_x, double new_y);

int			get_pixel_color(mlx_image_t *img, int tex_x, int tex_y);
int			get_color_code(int *color);

#endif