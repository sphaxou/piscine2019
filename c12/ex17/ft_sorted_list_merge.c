/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 04:06:19 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 04:34:50 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdio.h>
void insert(t_list **start, t_list *new, int (*cmp)(void*, void*))
{
	t_list	*list;

	list = (*start);
	if (cmp(new->data, list->data) <= 0)
	{
		new->next = list;
		*start = new;
		return ;
	}
	while (list->next && cmp(new->data, list->next->data) > 0)
		list = list->next;
	new->next = list->next;
	list->next = new;
}

void ft_sorted_list_merge(t_list **list1, t_list *list2,
		int (*cmp)(void*, void*))
{
	t_list	*tmp;

	while (list2)
	{
		tmp = list2->next;
		insert(list1, list2, cmp);
		list2 = tmp;
	}
}
