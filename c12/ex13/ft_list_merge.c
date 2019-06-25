/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:09:17 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 08:14:04 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **list1, t_list *list2)
{
	t_list	*cur;

	cur = *list1;
	while (cur && cur->next)
		cur = cur->next;
	cur->next = list2;
}
