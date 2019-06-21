/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:11:37 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/21 03:41:55 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap(t_list **l)
{
	t_list	*tmp;

	tmp = (*l)->next->next;
	*l = (*l)->next;
	(*l)->next = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)(void*, void*))
{
	t_list	*cur;

	cur = *begin_list;
	while (cur && cur->next)
	{
		printf("%s\n", cur->data);
		if (cmp(cur->data, cur->next->data) < 0)
		{
			ft_list_swap(&cur);
			cur = *begin_list;
		}
		else
			cur = cur->next;
	}
}
