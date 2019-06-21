/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:11:37 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/21 16:45:31 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insert_sort(t_list **list, t_list *elem,
		int (*cmp)(void*, void*))
{
	t_list	*tmp;

	tmp = *list;
	if (cmp(elem->data, tmp->data) < 0)
	{
		elem->next = tmp->next;
		tmp->next = elem;
		return ;
	}
	while (tmp->next && cmp(elem->data, tmp->data))
		tmp = tmp->next;
	elem->next = tmp->next;
	tmp->next = elem;
}

void	ft_list_sort(t_list **start, int (*cmp)(void*, void*))
{
	t_list	*list;
	t_list	*tmp;
	t_list	*tmp2;

	list = *start;
	tmp = list->next;
	list->next = NULL;
	while(tmp)
	{
		tmp2 = tmp->next;
		ft_list_insert_sort(&list, tmp, cmp);
		tmp = tmp2;
	}

}
