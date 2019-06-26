/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:34:26 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/26 15:23:38 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define BUFF_SIZE 50000
#include <stdlib.h>
#include <unistd.h>

char	*createbigbuff(char *s, char *buff)
{
	char	*res;
	int		len;

	len = ft_strlen(s) + ft_strlen(buff);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res = ft_strcpy(res, s);
	free(s);
	res = ft_strcat(res, buff);
	return (res);
}

void	displayinput(char *s, int size, int offset)
{
	int		i;

	i = 0;
	while (i < size - offset)
		i++;
	while (i < size)
		write(1, s + i++, 1);
}

int		**parse_input(char *s, t_car *car, int *h, int *l)
{
	int		**map;
	int		link;
	int		navi;

	link = 0;
	if (!s || zelda(s, car, 0, 0) != 1 || !(car->h))
	{
		if (s)
			ft_putstr_fd("map error\n", 2);
		return (NULL);
	}
	*h = car->h;
	while (s[link] && s[link] != '\n')
		link++;
	link = link + 1;
	navi = link;
	while (s[link] && s[link] != '\n')
	{
		*l += 1;
		link++;
	}
	map = splitint(s + navi, *car, *h, *l);
	return (map);
}

void	bsq_input(char *s)
{
	int		**tab;
	int		h;
	int		l;
	t_car	car;
	t_max	max;

	h = 0;
	l = 0;
	tab = parse_input(s, &car, &h, &l);
	if (!h)
		return ;
	if (!tab)
		return ;
	solve(tab, h, l, &max);
	max.l = l;
	max.h = h;
	printtab(tab, car, max);
	return ;
}

int		readinput(void)
{
	char	*s;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	if (!(s = (char*)malloc(sizeof(char))))
		return (0);
	s[0] = '\0';
	while ((ret = read(0, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		s = createbigbuff(s, buf);
	}
	bsq_input(s);
	free(s);
	return (0);
}
