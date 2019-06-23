/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maspiewa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:38:19 by maspiewa          #+#    #+#             */
/*   Updated: 2019/06/23 21:01:48 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void	ft_cleanmem(t_dict **dict)
{
	int i;

	i = 0;
	while ((*dict)[i].len)
	{
		free((*dict)[i].str);
		free((*dict)[i].number);
		i++;
	}
	free(*dict);
}
