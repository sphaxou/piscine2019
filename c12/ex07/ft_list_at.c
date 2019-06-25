/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:22:38 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 08:11:53 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_at(t_list *start, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (start)
	{
		i++;
		if (i == nbr)
			return (start);
		start = start->next;
	}
	return (NULL);
}
