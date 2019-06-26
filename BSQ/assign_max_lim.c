/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_max_lim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 02:14:05 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/26 02:46:31 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		assign_max_lim(int **map, t_max *max, int i, int j)
{
	max->value = 1;
	if (max->value >= map[max->i][max->j])
	{
		max->i = i;
		max->j = j;
	}
	return (1);
}
