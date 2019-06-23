/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finddict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:37:13 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 13:01:50 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

t_dict	finddict(char *s, int size, int len, t_dict *dict)
{
	int i;

	i = 0;
	while (dict[i].len)
	{
		if (size == dict[i].len && !ft_strncmp(dict[i].number, s, len))
			return (dict[i]);
		i++;
	}
	return (dict[i]);
}

t_dict	findexposant(int len, t_dict *dict)
{
	int ires;
	int i;

	i = 0;
	ires = 0;
	while (dict[i].len)
	{
		if (len >= dict[i].len)
			if (dict[ires].len < dict[i].len)
				ires = i;
		i++;
	}
	return (dict[ires]);
}

t_dict	findclosest(char *s, int len, t_dict *dict)
{
	int	i;
	int	ires;
	int find;
	int	diff;

	diff = 256;
	i = 0;
	ires = 0;
	find = 0;
	while (dict[i + 1].len)
	{
		if (len == dict[i].len
			&& ft_str10cmp(s, dict[i].number, len)
			< ft_str10cmp(s, dict[ires].number, len))
		{
			ires = i;
			find = 1;
		}
		i++;
	}
	if (find)
		return (dict[ires]);
	return (dict[i]);
}
