/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:18:29 by ekashirs          #+#    #+#             */
/*   Updated: 2025/07/07 14:18:30 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*lstnew_m(void *content)
{
	t_list	*new;

	if (!content)
		return (NULL);
	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	if (!new->content)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	lst_del_first(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	if (!(*lst)->next)
	{
		ft_lstclear(lst, free);
		return ;
	}
	temp = *lst;
	*lst = temp->next;
	ft_lstdelone(temp, free);
}

void	skip_new_line(t_list **map)
{
	if (!map)
		return ;
	if (*map && (*map)->content && ((char *)(*map)->content)[0] == '\n')
		while (*map && ((char *)(*map)->content)[0] == '\n')
			lst_del_first(map);
}

char	**list_to_arr(t_list *list)
{
	char	**arr;
	int		i;
	t_list	*current;
	int		size;

	i = 0;
	current = list;
	size = ft_lstsize(list);
	arr = ft_calloc(size + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (current && current->content)
	{
		if (i < size - 1)
			arr[i] = ft_substr(current->content, 0,
					ft_strlen(current->content) - 1);
		else
			arr[i] = ft_strdup(current->content);
		if (!arr[i++])
			return (NULL);
		current = current->next;
	}
	arr[i] = NULL;
	return (arr);
}
