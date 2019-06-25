/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:23:30 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 11:04:53 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

int	value(int **map, int i, int j)
{
	int		a;
	int		b;
	int		c;

	a = map[i][j + 1];
	b = map[i + 1][j];
	c = map[i + 1][j + 1];
	if (a == -1 || b == -1 || c == -1)
		return (1);
	if (a != b)
		return ((a > b) ? b + 1 : a + 1);
	return ((a < c ? a + 1 : c + 1));
}

void	solve(int **map, int h, int l, t_max *max)
{
	int		i;
	int		j;

	i = h - 1;
	max->i = i;
	max->j = l - 1;
	while (i >= 0)
	{
		j = l - 1;
		while (j >= 0)
		{
			if (map[i][j] != -1)
			{
				if (i == h - 1 || j == l - 1)
					map[i][j] = 1;
				else
				{
					max->value = value(map, i, j);
					map[i][j] = max->value;
					if (max->value >= map[max->i][max->j])
					{
						max->i = i;
						max->j = j;
					}
				}
			}
			j--;
		}
		i--;
	}
	max->value = map[max->i][max->j];
}

void	clean(int **tab, int h)
{
	int		i;

	i = 0;
	while (i < h)
		free(tab[i++]);
	free(tab);
}

int		bsq(char *s)
{
	int		h;
	int		l;
	int		**tab;
	t_car	car;
	t_max	max;

	h = 0;
	l = 0;
	tab = parse(s, &car, &h, &l);
	if (!tab)
		return (0);
	solve(tab, h, l, &max);
	max.l = l;
	max.h = h;
	printtab(tab, car, max);
	clean(tab, h);
	return (1);
}
