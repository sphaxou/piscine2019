/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:22:38 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/26 06:26:39 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_at(t_list *start, unsigned int nbr)
{
	if (!(start))
		return (NULL);
	if (nbr == 0)
		return (start);
	return (ft_list_at(start->next, nbr - 1));
}
