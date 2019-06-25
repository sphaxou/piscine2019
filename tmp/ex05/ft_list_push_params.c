/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:56:38 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/21 02:41:25 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*start;
	t_list	*list;

	i = 1;
	start = ft_create_elem(av[ac - i++]);
	list = start;
	while (ac - i >= 0)
	{
		list->next = ft_create_elem(av[ac - i++]);
		list = list->next;
	}
	return (start);
}
