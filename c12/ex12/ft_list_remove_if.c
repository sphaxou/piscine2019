/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 22:28:54 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 08:15:12 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **start, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*cur;
	t_list	*prev;

	prev = *start;
	while (*start && !cmp(data_ref, (*start)->data))
	{
		tmp = (*start);
		*start = (*start)->next;
		free_fct(tmp->data);
		free(tmp);
	}
	cur = *start;
	while (cur && cur->next)
	{
		if (!cmp(cur->next->data, data_ref))
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			free_fct(tmp->data);
			free(tmp);
		}
		else
			cur = cur->next;
	}
}
