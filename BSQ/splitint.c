/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 04:41:58 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/26 15:25:58 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

int	**splitint(char *s, t_car car, int h, int l)
{
	int		**tab;
	int		i;
	int		j;
	int		k;

	if (!h || !(tab = (int **)malloc(sizeof(int*) * h)))
		return (NULL);
	i = 0;
	k = 0;
	while (i < h)
	{
		j = 0;
		if (!(tab[i] = (int *)malloc(sizeof(int) * l)))
			return (NULL);
		while (j < l)
		{
			tab[i][j] = (s[k++] == car.vide ? 0 : -1);
			j++;
		}
		i++;
		k++;
	}
	return (tab);
}
