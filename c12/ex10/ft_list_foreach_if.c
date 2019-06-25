/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:45:40 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/21 03:07:31 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_foreach_if(t_list *start, void (*f)(void *), void
		*data_ref, int (*cmp)(void *, void *))
{
	while (start)
	{
		if (!cmp(data_ref, start->data))
			f(start->data);
		start = start->next;
	}
}
