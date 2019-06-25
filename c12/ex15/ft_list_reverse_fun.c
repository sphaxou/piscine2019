/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 03:44:24 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 08:05:14 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

static t_list	*ft_list_at(t_list *start, unsigned int nbr)
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

static int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = begin_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void			ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	t_list	*tmp;
	void	*t;
	t_list	*cur;

	cur = begin_list;
	j = ft_list_size(begin_list);
	i = 0;
	while (i < j)
	{
		tmp = ft_list_at(begin_list, j);
		t = cur->data;
		cur->data = tmp->data;
		tmp->data = t;
		i++;
		j--;
		cur = cur->next;
	}
}
