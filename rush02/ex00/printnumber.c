/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:08:44 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/23 20:12:51 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	printdict(char *s, t_dict dict)
{
	if (s[0] != '0')
	{
		ft_putstr(dict.str);
		if (*(s + 1))
			ft_putstr(" ");
	}
}

void	printnumber(char *s, int len, t_dict *dict)
{
	t_dict	tmp;

	if (!len)
		return ;
	tmp = finddict(s, len, len, dict);
	if (tmp.len)
	{
		printdict(s, tmp);
		return ;
	}
	tmp = findclosest(s, len, dict);
	if (tmp.len == 2)
	{
		printdict(s, tmp);
		printnumber(s + 1, len - 1, dict);
		return ;
	}
	tmp = findexposant(len, dict);
	printnumber(s, len - tmp.len + 1, dict);
	printdict(s, tmp);
	printnumber(s + (len - tmp.len + 1), tmp.len - 1, dict);
}
