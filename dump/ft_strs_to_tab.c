/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:54:59 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/11 17:37:44 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	char		*res;

	res = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	i = 0;
	if (!(res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	while (i < ac)
	{
		if (!(res[i].size = (int)malloc(sizeof(int))))
			return (NULL);
		res[i].size = ft_strlen(av[i]);
		if (!(res[i].str = (char *)malloc(sizeof(char) * (res[i].size + 1)))
				|| !(res[i].copy = (char *)malloc(sizeof(char) * (res[i].size
							+ 1))))
			return (NULL);
		res[i].copy = ft_strcpy(res[i].str, av[i]);
		i++;
	}
	res[i].str = NULL;
	res[i].copy = NULL;
	return (res);
}
