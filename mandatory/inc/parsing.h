/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:17:28 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 15:10:49 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		prew;
	int		next;
}	t_point;

typedef struct s_count
{
	int		player;
	bool	allowed;
}	t_count;

int		get_map(t_game *game, char *fname);
int		get_path(t_list *map, char **path, char *prefix);
int		parse_texture(t_list **curr, char *prefix, char **target);
int		parse_color(t_list **curr, const char *prefix, uint64_t **target);

int		composition(t_game *game);
int		map_val(t_game *game);

#endif
