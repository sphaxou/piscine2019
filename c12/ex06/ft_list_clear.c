/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:17:28 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/21 02:50:07 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_list_clear(t_list **start)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *start;
	while (tmp)
	{
		tmp2 = tmp->next;
		tmp = tmp2;
	}
	*start = NULL;
}
