/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:48:33 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 20:15:36 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_list	*create_elem(t_btree *root, int level)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (0);
	new->item = root->item;
	new->level = level;
	new->first = 1;
	new->next = NULL;
	return (new);
}

t_list	*add_to_list(t_list *list, t_btree *root, int level)
{
	t_list	*tmp;
	t_list	*new;

	if (!root)
		return (NULL);
	new = create_elem(root, level);
	tmp = list;
	if (!tmp)
		list = new;
	else
	{
		while (tmp->next && tmp->next->level <= level)
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
		if (tmp->level == level)
			new->first = 0;
	}
	add_to_list(list, root->left, level + 1);
	add_to_list(list, root->right, level + 1);
	return (list);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_list	*list;

	list = NULL;
	list = add_to_list(list, root, 0);
	while (list)
	{
		applyf(list->item, list->level, list->first);
		list = list->next;
	}
}
