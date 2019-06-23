/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:10:21 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/23 13:02:27 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_checkparams(int ac, char *str)
{
	int		i;

	i = 0;
	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!str[0])
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
