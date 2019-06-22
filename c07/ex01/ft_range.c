/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:20:00 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/09 21:33:30 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int	*tab;

	if (min >= max)
		return (NULL);
	if (!(tab = (int *)malloc(sizeof(tab) * (max - min))))
		return (NULL);
	i = 0;
	while (min < max)
		tab[i++] = min++;
	return (tab);
}
