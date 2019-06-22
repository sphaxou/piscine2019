/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str10cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:30:05 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 00:32:56 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_str10cmp(char *s1, char *s2, int n)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (i < n)
	{
		res = 10 * res + ft_abs((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (res);
}
