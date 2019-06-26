/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:17:28 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/26 06:20:26 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_list_clear(t_list *start, void (*free_fct)(void *))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = start;
	while (tmp)
	{
		tmp2 = tmp->next;
		free_fct(tmp->data);
		free(tmp);
		tmp = tmp2;
	}
}
