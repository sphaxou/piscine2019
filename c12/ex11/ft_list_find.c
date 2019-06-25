/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 03:08:43 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/21 03:10:14 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list *ft_list_find(t_list *start, void *data_ref, int (*cmp)(void*, void*))
{
	while (start)
	{
		if (!cmp(data_ref, start->data))
			return (start);
		start = start->next;
	}
	return (NULL);
}
