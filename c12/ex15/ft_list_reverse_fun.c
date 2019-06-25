/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 03:44:24 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 03:50:47 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp;
	t_list	*cur;
	t_list	*prev;

	prev = NULL;
	cur = begin_list;
	while (cur->next)
	{
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
}
