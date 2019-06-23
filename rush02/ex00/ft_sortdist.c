/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortdist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maspiewa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:06:12 by maspiewa          #+#    #+#             */
/*   Updated: 2019/06/23 14:01:07 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	sort_len(t_dict *dict)
{
	int		i;
	t_dict	tmp;
	int		sort;

	sort = 0;
	while (!sort)
	{
		sort = 1;
		i = 0;
		while (dict[i + 1].len)
		{
			if (dict[i].len > dict[i + 1].len)
			{
				tmp = dict[i];
				dict[i] = dict[i + 1];
				dict[i + 1] = tmp;
				sort = 0;
			}
			i++;
		}
	}
}

void	sort_ascii(t_dict *dict)
{
	int		i;
	int		sort;
	t_dict	tmp;

	sort = 0;
	while (!sort)
	{
		sort = 1;
		i = 0;
		while (dict[i + 1].len)
		{
			if (dict[i].len == dict[i + 1].len
				&& ft_strcmp(dict[i].number, dict[i + 1].number) > 0)
			{
				tmp = dict[i];
				dict[i] = dict[i + 1];
				dict[i + 1] = tmp;
				sort = 0;
			}
			i++;
		}
	}
}

void	sortdict(t_dict *dict)
{
	sort_len(dict);
	sort_ascii(dict);
}
