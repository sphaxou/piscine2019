/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:37:12 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 08:14:24 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	if (!new)
		return ;
	new->next = *list;
	*list = new;
}
