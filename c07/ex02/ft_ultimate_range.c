/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:35:34 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/11 17:19:56 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!range || !(tab = (int *)malloc(sizeof(*tab) * (max - min))))
		return (-1);
	i = 0;
	while (min < max)
	{
		tab[i++] = min++;
	}
	*range = tab;
	return (max - *range[0]);
}
