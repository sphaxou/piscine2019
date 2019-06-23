/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 04:41:58 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 06:16:40 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

#include <stdio.h>
int **splitint(char *s, t_car car, int h, int l)
{
	printf("vide: %c plein: %c obs: %c\n", car.vide, car.plein, car.obs);
	int		**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (int **)malloc(sizeof(int*) * h)))
		return (NULL);
	i = 0;
	k = 0;
	while (i < h)
	{
		j = 0;
		if (!(tab[i] = (int *)malloc(sizeof(int) * l)))
			return (NULL);//free tous les tableaux precedents
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
