/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:09:17 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/26 06:34:22 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **list1, t_list *list2)
{
	t_list	*cur;

	if (!(*list1))
	{
		*list1 = list2;
		return ;
	}
	cur = *list1;
	while (cur && cur->next)
		cur = cur->next;
	cur->next = list2;
}
