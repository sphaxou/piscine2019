/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:24:03 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/15 21:10:05 by mpedro-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_printtab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size * size)
	{
		ft_putnbr(tab[i++]);
		if (i % size == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
}
