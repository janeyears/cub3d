/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:39 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:18:40 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_msg(char *msg)
{
	char	*red;
	char	*reset;

	red = "\033[1;31m";
	reset = "\033[0m";
	write(2, red, 7);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	write(2, reset, 4);
}
