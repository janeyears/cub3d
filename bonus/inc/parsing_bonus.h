/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:15:17 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/14 15:11:15 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "cub3d_bonus.h"

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
