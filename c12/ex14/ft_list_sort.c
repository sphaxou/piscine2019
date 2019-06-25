/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:11:37 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 08:15:30 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_insert_sort(t_list **list, t_list *elem, int (*cmp)())
{
	t_list	*tmp;

	tmp = *list;
	if (cmp(elem->data, tmp->data) < 0)
	{
		elem->next = tmp;
		*list = elem;
		return ;
	}
	while (tmp)
	{
		if (!tmp->next || cmp(elem->data, tmp->next->data) < 0)
		{
			elem->next = tmp->next;
			tmp->next = elem;
			return ;
		}
		tmp = tmp->next;
	}
}

void	ft_list_sort(t_list **start, int (*cmp)())
{
	t_list	*list;
	t_list	*tmp;
	t_list	*tmp2;

	list = *start;
	tmp = list->next;
	list->next = NULL;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_list_insert_sort(&list, tmp, cmp);
		tmp = tmp2;
	}
	*start = list;
}
