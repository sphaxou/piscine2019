/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:20:08 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 08:16:09 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **start, void *data,
		int (*cmp)(void*, void*))
{
	t_list	*new;
	t_list	*list;

	new = ft_create_elem(data);
	list = (*start);
	if (!(*start) || cmp(new->data, list->data) <= 0)
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
