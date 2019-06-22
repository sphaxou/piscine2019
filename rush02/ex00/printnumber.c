/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:08:44 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/22 22:53:31 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
/*void	print123(char *s, int size, t_dict *dict)
{
	t_dict	cur;

	if (size == 0)
		return ;
	cur = finddict(s, size, size, dict);
	if (cur.len)
		ft_putstr(cur.str);
	else
	{
		cur = finddict(s, size, 1, dict);
		if (!cur.len)
			printf("probleme");
		ft_putstr(cur.str);
		print123(s + 1, size - 1, dict);
	}
}

void	printexposant(int len, t_dict *dict)
{
	t_dict	cur;

	cur = findexposant(len, dict);
	ft_putstr(cur.str);
}

void	printnumber(char *s, t_dict *dict)
{
	int		len;
	int		size;
	int		i;

	printf("%s\n", s);
	printf("%s\n", dict[0].number);
	len = ft_strlen(s);
	printf("%d\n", len);
	size = (len % 3 ? len % 3 : 3);
	i = 0;
	print123(s, size, dict);
	if (len > 3)
		printexposant(len, dict);
	if (len > 3)
		printnumber(s + 3, dict);
}*/

void	printnumber(char *s, int len, t_dict *dict)
{
	t_dict	tmp;

	if (!len)
		return ;
	tmp = finddict(s, len, len, dict);
	if (tmp.len)
	{
		if (s[0] != '0')
			ft_putstr(tmp.str);
		return ;
	}
	//printf("start rec\ns: %s\n", s);
	tmp = findexposant(len, dict);
	printnumber(s, len - tmp.len + 1, dict);
	if (s[0] != '0')
		ft_putstr(tmp.str);
	printnumber(s + (len - tmp.len + 1), tmp.len - 1, dict);
}
