/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:08:44 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 00:47:39 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

void	printnumber(char *s, int len, t_dict *dict)
{
	t_dict	tmp;

	if (!len)
		return ;
	tmp = finddict(s, len, len, dict);
	if (tmp.len)
	{
		if (s[0] != '0')
		{
			ft_putstr(tmp.str);
			if (*(s + 1))
				ft_putstr(" ");
		}
			return ;
	}
	tmp = findclosest(s, len, dict);
	if (tmp.len == 2)
	{
		if (s[0] != '0')
		{
			ft_putstr(tmp.str);
			if (*(s + 1))
				ft_putstr(" ");
		}
		printnumber(s + 1, len - 1, dict);
		return ;
	}
	//printf("start rec\ns: %s\n", s);
	tmp = findexposant(len, dict);
	printnumber(s, len - tmp.len + 1, dict);
	if (s[0] != '0')
	{
		ft_putstr(tmp.str);
		if (*(s + 1))
			ft_putstr(" ");
	}
	printnumber(s + (len - tmp.len + 1), tmp.len - 1, dict);
}
