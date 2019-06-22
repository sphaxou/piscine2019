/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:57:39 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/14 02:23:10 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int len, int (*f)(int))
{
	int	*res;
	int	i;

	i = -1;
	if (!(res = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	while (++i < len)
		res[i] = f(tab[i]);
	return (res);
}
