/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 04:55:47 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 06:46:58 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	printtab(int **tab, t_car car, t_max max)
{
	int	i;
	int j;
	
	i = 0;
	while (i < max.h)
	{
		j = 0;
		 while (j < max.l)
		 {
			 if (tab[i][j] == -1)
				 ft_putchar(car.obs);
			 else
				 ft_putchar(((i - max.i) < max.value
					&& (j - max.j) < max.value
					&& i >= max.i && j >= max.j) ? car.plein : car.vide);
			 j++;
			 if (j == max.l)
				 ft_putchar('\n');
		 }
		 i++;
	}
}
